#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

// Lecture 101: Bellman Ford Algorithm
// To find shortest distance from src to destination considering negative weights also.
// TC: n-1 traverse all edges, O(n*m) times where m is edges, n is vertices

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // first we create distance data structure
    // here node start 1 , so we use n+1 distance
    // and every node have maximum number (1e9);
    vector<int> distance(n + 1, 1e9);

    // traversing from source node
    distance[src] = 0; // mark distance of src node = 0

    for (int i = 1; i <= n; i++)
    {
        // formula is applied on all edges
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // Apply formula n-1 times
            if (distance[u] != 1e9 && (distance[u] + weight < distance[v]))
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // checking for negative cycle

    bool flag = 0;

    // if negative cycle then flag =1;

    // Check for all edges
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        // if distance updated means negative cycle present
        if (distance[u] != 1e9 && (distance[u] + weight < distance[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0) // means no negative cycle present
    {
        return distance[dest];
    }
    else // means negative cycle present
    {
        return -1;
    }
}

int main()
{
    return 0;
}