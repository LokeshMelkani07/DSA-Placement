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
Topological sort using DFS
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
{
    // mark the node visited
    vis[node] = 1;
    // go to neighbours
    for (auto it : adj[node])
    {
        // if not visited, go to them
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    // if all calls are done for the node, push it into the stack
    st.push(node);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // using DFS
    // we will make use of a stack
    // we run a loop for all the nodes and for each node we make a call to a function dfs
    // which marks that node as visited and make further calls to its neighbours, it there are no further neighbours we push that node in the stack
    // we do this for all the nodes and at the end our stack contains the Topo sort result

    // int vis[V] = {0}; right
    int vis[10] = {0}; // wrong

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // take the result from the stack
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    return 0;
}