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
Minimum Spanning Tree using Kruskal's algo, Union Set
You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.
Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.
By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
9

Explanation for Sample Input 1:
The edge (2,3) having weight 8 will be excluded from the MST. The total weight of the MST then will be 1 + 3 + 5 = 9.

Sample Input 2:

4 4
1 2 6
2 3 2
1 3 2
1 0 2

Sample Output 2:
6
*/

// TC: O(mlogm) where m is number fo edges
// SC: O(n)
bool cmp(vector<int> &a, vector<int> &b)
{
    // Sort according to the weight and weight is in 2nd index of edges array so
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{

    // Initialise the parent and rank vector
    // Initially make all node as their parent also
    // Mark all ranks as 0 initially
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find parent of nodes
int findParents(int node, vector<int> &parent)
{
    // if we have to check whether 3,4 are from same component
    // we check findParent(3) and findParent(4)
    // if parent of both are different means they are not from same component
    // for findParents() logic
    // We start from the bottom node and go to the top refer to notes for better understanding
    // if node is parent of itself means we have reached the top parent
    if (parent[node] == node)
    {
        // if we are at the top node i.e parents node then its parent will be the node itself
        return node;
    }

    // parent[node] = findParents(parent[node],parent) is for path compression logic
    return parent[node] = findParents(parent[node], parent);
}

// Find union of 2 nodes
void findUnion(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // Find the parent for both node u and v
    u = findParents(u, parent);
    v = findParents(v, parent);

    // Now find rank for both the parents of u and v
    if (rank[u] < rank[v])
    {
        // Make the bigger one, parent of smaller one
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        // Both rank are equal so make anyone parent of anyone and increment its rank
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // We need to srt the edges array related to weight so we make a comparator
    sort(edges.begin(), edges.end(), cmp);

    // Make a parent vector
    vector<int> parent(n);
    // Make a rank vector
    vector<int> rank(n);

    // Initialise parent and rank vector
    makeSet(parent, rank, n);

    // Kruskal's Algo
    // We need to return the total weight of minimum spanning tree so
    int weight = 0;
    // We run a loop and start processing for each element of sorted edges array
    for (int i = 0; i < edges.size(); i++)
    {
        // u means node 1
        int u = findParents(edges[i][0], parent);
        // v means node 2
        int v = findParents(edges[i][1], parent);
        // w means weight
        int w = edges[i][2];

        // if parents are not equal merge them and add the weight in final answer
        if (u != v)
        {
            weight += w;
            findUnion(u, v, parent, rank);
        }
        // else if parents are same do nothing
    }

    return weight;
}

int main()
{
    return 0;
}