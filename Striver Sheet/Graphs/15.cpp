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
Bellman Ford
you have been given a directed weighted graph of n vertices labeled from 1 to n and m edges each edge connecting two nodes u and v has a weight w denoting the distance between them
Your task is to calculate the shortest distance of all vertices from the source vertex.
Note:
If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.
Example:
3 3 1
1 2 2
1 3 2
2 3 -1

In the above graph:

The length of the shortest path between vertex 1 and vertex 1 is 1->1 and the cost is 0.

The length of the shortest path between vertex 1 and vertex 2 is 1->2 and the cost is 2.

The length of the shortest path between vertex 1 and vertex 3 is 1->2->3 and the cost is 1.

Note:
It's guaranteed that the graph doesn't contain self-loops and multiple edges. Also, the graph does not contain negative weight cycles.


Hence we return [0, 2, 1].

*/

// To find shortest distance from src to destination considering negative weights also.
// TC: n 1 traverse all edges, O(n*m) times where m is edges, n is vertices

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // This algo cannot be applied on graph with negative cycle so it can be used to check if any graph contain negative cycle or not
    // To find shortest distance from src to destination considering negative weights also.
    // Bellman ford is applied in directed graph but we can use it in undirected graph also by converted undirected graph to directed graph
    // 1 2 can be seen as 1 >2 and 2 >1 so this way we can convert undirected to directed
    // In this algo
    // we will apply distance minimization formula on all nodes, (n 1) times
    /*
            // Apply formula n 1 times
            if (distance[u] != 1e9 && (distance[u] + weight < distance[v]))
            {
                distance[v] = distance[u] + weight;
            }
    */
    // Now we apply same formula one more time and if any of the distance value changes, we say negative cycle exists there and we cannot apply the algo
    // We will take an distance array in which we store shortest distance from source to reach distance[index] node

    // first we create distance data structure
    // here node start 1 , so we use n+1 distance
    // and every node have maximum number (1e9);
    vector<int> distance(n + 1, 1e9);

    // traversing from source node
    distance[src] = 0; // mark distance of src node = 0

    for (int i = 1; i <= n; i++)
    {
        // Our node starts from 1 so we start from index = 1
        // formula is applied on all edges
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // Apply formula n 1 times
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
        // return shortest distance to reach distination from source
        return distance[dest];
    }
    else // means negative cycle present
    {
        // if negative cycle present, ret  1
        return 1;
    }
}

int main()
{
    return 0;
}