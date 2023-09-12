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
Minimum Spanning Tree using prim's algo
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. Given  adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.

Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
*/

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // We have a undirected weighted graph with n vertices and m edges
    // Spanning tree is a tree which has n nodes and n-1 edges and each node is reachable
    // Minimum spanning tree is one which has lowest cost
    // We can draw any number of spanning trees from a graph and we need to return spanning tree with least cost as answer
    // To solve this problem we will take a min_heap with (weight,node,parent) which will store minimum weight at the top
    // We take a MST array to store MST path
    // We will take a visited array
    // we will also take variable sum = 0 to store cost of each pair we add in MST which at the end gives us total cost of our MST
    // We will pick first node = 0 and store in min_heap as (0, 0 ,-1) as no parent for first node
    // We pick minH.top() and mark it visited now we go to its neighbours in adj list
    // we push them in minH with their weight,node,parent as 0 but DO NOT MARK THEM VISITED FOR NOW
    // we again take minH.top() say 2 now we store parent->node i.e o->2 in MST array
    // We do not mark mark it visited now also
    // We traverse all neighbour of 2 which are not visited and we push them in minH now we mark 2 as visisted
    // We go to min.top() again now do the same and mark it as visited at the end
    // In question we do not need to print or get the MST we just need that sum
    // So in Priority queue we just store {weight,node}

    // declaring min_heap of {weight,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // make a visited array
    vector<int> vis(V, 0);
    // add first element
    pq.push({0, 0});

    // store cost of MST
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        // if its already visited no need to add it in MST
        if (vis[node] == 1)
            continue;

        // else mark it visited
        vis[node] = 1;
        sum += wt;

        // go to its neighbours
        for (auto it : adj[node])
        {
            // we store node in first and weight in second
            int node1 = it[0];
            int wt1 = it[1];

            if (!vis[node1])
            {
                // do not mark it visited here, we mark it viisted only when we include it in our MST
                pq.push({wt1, node1});
            }
        }
    }

    return sum;
}

int main()
{
    return 0;
}
