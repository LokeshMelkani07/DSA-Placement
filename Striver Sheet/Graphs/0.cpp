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
DFS Traversal
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note:
The Graph may not be connected i.e there may exist multiple components in a graph.

Sample Input 1:

5 4
0 2
0 1
1 2
3 4

Sample Output 1:

2
0 1 2
3 4

Explanation For Sample Input 1:

If we do a DFS traversal from vertex 0 we will get a component with vertices [0, 2, 1]. If we do a DFS traversal from 3 we will get another component with vertices [3, 4]

Hence,  we have two disconnected components so on the first line, print 2. Now, print each component in increasing order. On the first line print 0 1 2 and on the second line, print 3 4.

[0 1 2] comes before [3 4] as the first vertex 0 from the first component is smaller than the first vertex 3 from the second component.

Sample Input 2:

9 7
0 1
0 2
0 5
3 6
7 4
4 8
7 8

Sample Output 2:

3
0 1 2 5
3 6
4 7 8
*/

void dfs(int node, unordered_map<int, list<int>> &neighbours, unordered_map<int, bool> &visited, vector<int> &comp)
{
    // add first node in component
    comp.push_back(node);
    // mark it visited;
    visited[node] = true;
    // go to its neightbours
    for (auto it : neighbours[node])
    {
        if (!visited[it])
        {
            dfs(it, neighbours, visited, comp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // what we do is
    // we need to go to the depth of every node
    // we prepare a adj list like 1 -> 0,2,3,4 means node -> list of neightbours
    // we make visited array
    // we pick a node, go to its all child and before that we check if its already visited or not
    // if its not visited then only we visit it
    // TC: O(n) + O(degree which is 2*edges)
    // SC: O(n) + O(n) + O(n)

    // prepare adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        // its a undirected graph so both sides

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // make a visited
    unordered_map<int, bool> visited;
    // make answer array
    vector<vector<int>> ans;

    // call for all nodes
    for (int i = 0; i < V; i++)
    {
        // indexing of vertices start from 0 so we run loop from 0
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    return 0;
}
