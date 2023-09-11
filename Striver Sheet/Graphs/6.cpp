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
Topological sort using BFS (Kahn's algo)
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // using BFS (also known as Kahn's algo)
    // Topo sort is a linear orderding in such a way that if there occurs an edge from u and v then u appears before v in the ordering
    // if there is a adj like [5,0], [4,0], [5,2], [4,1], [2,3], [2,1]
    // then topo order will be 5,4,0,2,3,1 or 4,5,2,3,1,0 in which we can see
    // 5 comes before 0, 4 comes before 0, 4 comes before 1, 2 comes before 3 and 2 comes before 1
    // Topo sort is only valid in DAG, directed Acyclic graph
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
        // if indegree = 0 means we can put that node in topo vector now as there is no problem of u coming before v as indegree = 0
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
        // now that we have the element in topo vector we remove that node and any edge that node is having are also removed
        for (auto it : adj[node])
        {
            // remove the edges of that node
            indegree[it]--;
            // if indegree == 0 means it can be put in our answer now so push in queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

int main()
{
    return 0;
}