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
Detect cycle in a directed graph using BFS
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

// Function to detect cycle in a directed graph.
vector<int> topo(int V, vector<int> adj[])
{
    // what we do in topo sort is
    // First, store the indegree of all the nodes with the help of adjacency list
    // now take a queue and push the node with indegree == 0 into queue
    // now till q is not empty
    // take front of queue, pop it out
    // and push in result vector
    // go to its neighbours and if do indegree[neighbour]-- if indegree  = 0, push it in queue

    // int indegree[V] = {0}; right
    int indegree[10] = {0}; // wrong

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // make a queue
    queue<int> q;

    // find node with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // ans vector
    vector<int> topo;

    // go to neighbours
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

bool isCyclic(int V, vector<int> adj[])
{
    // using BFS (also known as Kahn's algo)
    // we know Topological sort is only applicable in DAG, Directed Acyclic graph
    // and if result of Topo sort is not of size = n means topo sort can't be applied
    // and if topo sort can't be applied means there is a cycle in graph
    // for topo sort using BFS
    // we first mark the indegree for all the nodes, indegree means number of nodes incoming to that node
    vector<int> ans = topo(V, adj);
    if (ans.size() == V)
        return false;

    return true;
}

int main()
{
    return 0;
}