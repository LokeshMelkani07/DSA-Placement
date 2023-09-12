#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Strongly Connected Components (Kosaraju's Algo)
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Sample Input 1:

1
5 6
0 1
1 2
1 4
2 3
3 2
4 0

Sample Output 1:

0 1 4
2 3

Explanation for Sample Input 1:

For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as shown in the image below.

Sample Input 2:

2
1 0
4 4
0 1
1 2
2 3
3 1

Sample Output 2:

0
0
1 2 3

Explanation for Sample Input 2:

For the first test case, the graph has 1 node(0) but there are no edges, therefore only 1 SCC exists and that is {0}.

For the second test case, one SCC is {0} and the other is {1, 2, 3}. Therefore the answer is 0, 1 2 3
*/

void dfs(int node, vector<vector<int>> adj, vector<int> &vis, stack<int> &st)
{
    // mark the node as visited
    vis[node] = 1;

    // go to its neighbour
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }

    // while coming back store it in stack
    st.push(node);
}

void dfs3(int node, vector<int> adjR[], vector<int> &vis)
{
    // mark the node visited
    vis[node] = 1;

    // go to its neighbour
    for (auto it : adjR[node])
    {
        if (!vis[it])
        {
            dfs3(it, adjR, vis);
        }
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // strongely connected components (SCC) is only valid for Directed graphs
    // strongely connected components means if we have 3 nodes directed, we can go from any node to any node
    // then they are called strongely connected.
    // We can travel from one SCC to other SCC if we do a DFS traversal so what if we reverse the edges between SCCs
    // We no more can travel between SCCs so now we can count number of SCCs
    // What if we reverse all the edges in the graph
    // An SCC remains an SCC, does not matter if edges are reversed so Thought process behind kosraju's algo is
    // Reverse the edges and if we are able to travel all nodes in a components means its an SCC
    // Steps of kosaraju algo
    // Step 1: Sort the nodes based on their finishing time, now what is finishing time?
    // We do DFS on whole graph and from the last node when we come back we put that in the stack and come back
    // we do this till we reach top node and push that in stack
    // This is our order now
    // Step 2: Reverse the graph (reverse all links)
    // Step 3: Do DFS traversal on sorted sequence and reversed graph
    // In step 3, we do a DFS only if node is not already visited and if any node is in SCC, it would be already visited by it neighbour in SCC so this way we do DFS only for first node of all SCCs and we can count number of SCCs also
    // TC: O(V+E), SC: O(2V)
    // In this question we need to return number of SCCs (0-based indexing)

    vector<int> vis(V, 0);
    stack<int> st;

    // find the sequence
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    // Now we have the sequence
    // Let us reverse the graph
    // For that we make another adj list for Reversed graph

    // vector<int> adjR[V]; right
    vector<int> adjR[10]; // wrong

    for (int i = 0; i < V; i++)
    {
        // mark all nodes all unvisited so that we can do DFS again in step 3
        vis[i] = 0;
        for (auto it : adj[i])
        {
            // i -> it will be original adj list
            // it -> i will be reversed adj list
            adjR[it].push_back(i);
        }
    }

    int count = 0;

    // Now that we have reversed the link, we will perform DFS on stack order we got in step 1
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // this time we pass adjR in the dfs call
        if (!vis[node])
        {
            // everytime we go inside, it will be for first node of each SCC as other node in a SCC will already be visited by first node during DFS
            count++;
            dfs3(node, adjR, vis);
        }
    }

    return count;
}

int main()
{
    return 0;
}
