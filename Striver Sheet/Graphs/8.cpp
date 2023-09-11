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
Bipartite Graph using BFS
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
*/

bool bfs(int node, vector<int> adj[], int color[])
{
    // color the node first
    color[node] = 1;
    // make a queue and push node in it
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        // take out first node
        int nd = q.front();
        q.pop();

        // go to neighbours
        for (auto it : adj[nd])
        {
            if (color[it] == -1)
            {
                // its not been colours so colour it and push in queue
                color[it] = !color[nd];
                q.push(it);
            }
            else if (color[it] == color[nd])
            {
                // colour of node and child is same means not bipartitte
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // using BFS
    // Bipartite means if we can colour the node in 2 colours such that no two adjacent/neighbour nodes have same colour
    // Linear graphs with no cycle are always bi-partite
    // any graph with even cycle length can also be bi-partite
    // any graph with odd cycle length can never be bi-partite
    // For BFS we use a queue and a colour array, with -1 means no colour and we use 2 colours to colour i.e 0 and 1
    // we start by picking a node and giving it a colour and pushing it in the queue
    // say we pick node = 1, give it color 0
    // now we pick q.front i.e 1 and go to its child using adj list
    // we pick its child 2, we give color of 2 = opposite of 1 i.e 1 and push it in queue
    // now we pick 2 and go to its child and gives colour to them opposite of 2 and push in queue
    // if any time, while going to neighbour of a node, we see node and neighbour has same value of colour, we return false and its not a bi-partitte graph
    // we keep in mind the dis-connected component thing also

    // int color[V]; right
    int color[10]; // wrong

    for (int i = 0; i < V; i++)
    {
        // fill whole color array as -1 initially
        color[i] = -1;
    }

    // make a call to all nodes of disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            // if its not coloured till now
            if (bfs(i, adj, color) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    return 0;
}