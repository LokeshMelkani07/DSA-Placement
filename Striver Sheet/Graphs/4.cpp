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
Detect cycle in a directed graph using DFS
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

bool dfs(int node, int vis[], int pathV[], vector<int> adj[])
{
    // mark it visited first
    vis[node] = 1;
    // mark it path visited
    pathV[node] = 1;

    // go to neighbours
    for (auto it : adj[node])
    {
        // if its not visited make a call
        if (!vis[it])
        {
            // if any of call in this depth return true, no need to go further return true
            if (dfs(it, vis, pathV, adj))
                return true;
        }
        else if (pathV[it] == 1)
        {
            // if its here means its already visited and its pathVisited is also 1 means cycle found
            return true;
        }
    }

    // while returning if we did not found any cycle, leave visited as it is
    // but mark pathVisited as 0
    pathV[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // using DFS
    // We cannot run same code as undirected cycle detection because it will give false results
    // cycle is said to be detected if we visit a node in same path again
    // this time we will take a visited and pathvisited array
    // when we reach a node we mark its visited and pathvisited as 1
    // pathvisited means its visiited in the same path but if we reach end of the call and we go back with false result,
    // we do not disturb visited but we make all nodes while returning as pathVisited as 0 again as in this path we did not found any cycle
    // now in next cycle if this node is again reached, we see its already visited and its pathvisited is 0 means do not go furhtr as there is no cycle in that way
    // but if any node is already visited and its pathvisited is also 1 means it has already came in this path and we are here for second time means there is a cycle
    // if we find cycle for any one, we return true and do not go further
    //  we have keep in mind of dis-connected components also
    // TC: O(V+E), SC: O(2n)

    // visited array
    // int vis[V] = {0}; right
    int vis[10] = {0}; // wrong

    // path visited array
    // int pathVisited[V] = {0}; right
    int pathVisited[10] = {0}; // wrong

    // for dis-connected components
    for (int i = 0; i < V; i++)
    {
        // if its not already visisted then only make call for it
        if (!vis[i])
        {
            if (dfs(i, vis, pathVisited, adj))
                return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}