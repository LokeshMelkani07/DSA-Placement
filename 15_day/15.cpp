#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// Lecture 100: Kosaraju's Algorithm for Strongly Connected Components

// TC: O(N+E)
// SC: O(N)

// For topo sort
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    // Mark the node visited
    vis[node] = true;

    // Go to its neighbour
    for (auto neighbour : adj[node])
    {
        // if neighbour is not visited make a dfs call
        if (!vis[neighbour])
        {
            dfs(neighbour, vis, st, adj);
        }
    }
    // While coming back push the node into stack
    st.push(node);
}

// For DFS in the topo sort result
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    // Mark the node true
    vis[node] = true;

    for (auto neighbour : transpose[node])
    {
        if (!vis[neighbour])
        {
            revDfs(neighbour, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Make an adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // It is a connected graph
        adj[u].push_back(v);
    }

    // Make a DFS call and do topo sort
    stack<int> st;
    unordered_map<int, bool> visited;

    // For disconnected components
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // Make a Transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        // Make visited = 0 again as it must have updated in earlier DFS call
        visited[i] = 0;

        for (auto ngh : adj[i])
        {
            transpose[ngh].push_back(i);
        }
    }

    // Make DFS Call for the transpose graph
    // Store the count of SCC in the count variable to return it later
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!visited[top])
        {
            // SCC found
            count++;
            // RevDFS is for DFS in ordering we got from topo sort
            revDfs(top, visited, transpose);
        }
    }

    return count;
}

int main()
{
    return 0;
}