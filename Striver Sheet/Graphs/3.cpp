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
Detect cycle in an undirected graph using DFS
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
*/

bool dfs(int src, int parent, vector<int> adj[], int vis[])
{
    // mark node as visited
    vis[src] = 1;
    // Go to neighbours
    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            // if any of the call return true, return true, do not go in depth
            if (dfs(it, src, adj, vis))
                return true;
        }
        else if (it != parent)
        {
            // if node is already visisted but the parent is different means there is a cycle
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // using DFS
    // We know in DFS we go recusively to the depth of first child then we comeback go to depth of second child
    // this time while going depth we need to detect a cycle
    // if any of the recursion call detects a cycle, it returns true to all above calls and we do not go further and return true
    // this time, to detect a cycle, we need to take parent also in the dfs call with the current node
    // if there is any node which is already visited and we encounter it again and we check it s  parent is not the node which brought us to current node means its already been visited with some another parent so then there is a cycle
    // SC: O(n) + O(n)
    // TC: O(n + 2*edge) + O(n)

    // int vis[V] = {0}; right
    int vis[10] = {0}; // wrong
    // for the disconnected compoents
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // for 0th node, there is no parent so -1
            if (dfs(i, -1, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}