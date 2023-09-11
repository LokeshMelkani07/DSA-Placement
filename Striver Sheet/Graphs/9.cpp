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
Bipartite Graph using DFS
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
*/

bool dfs(int node, int col, int color[], vector<int> adj[])
{
    // mark the color of the node
    color[node] = col;

    // go to neighbours
    for (auto it : adj[node])
    {
        // if neighbour not already coloured
        if (color[it] == -1)
        {
            // colour it with opposite colour and make a DFS call
            // if DFS call return us false means not bi-partite
            if (dfs(it, !col, color, adj) == false)
                return false;
        }
        else if (color[it] == color[node])
        {
            // if its laready coloured and its colour is same as parent means not a bi-partite
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // using DFS
    // Bipartite means if we can colour the node in 2 colours such that no two adjacent/neighbour nodes have same colour
    // Linear graphs with no cycle are always bi-partite
    // any graph with even cycle length can also be bi-partite
    // any graph with odd cycle length can never be bi-partite
    // For DFS we use a colour array, with -1 means no colour and we use 2 colours to colour i.e 0 and 1
    // we pick a node give it a color and make a dfs call to its neighbours in adj list and we send in colour of that node also
    // now we color the neighbour if not already coloured but we also check if its already coloured and its color is same as parent colour then return false
    // its not bi-partite

    // int color[V]; right
    int color[10]; // wrong

    // color with -1 initially
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }

    // now for disconnected graph we make a call for each node
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            // let us colour frist node with 0
            if (dfs(i, 0, color, adj) == false)
                return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}