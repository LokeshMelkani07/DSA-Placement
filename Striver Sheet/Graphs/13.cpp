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
Dijkstra's shortest path
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.
Example:
Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
In the given input, the number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.

Note:
1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.

*/

// TC: O(ElogV) where E is edges and V is vertices, log is due to using set
// SC: O(N+E)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // We will make use of a distance array in which we store infinity in starting
    // We will store shortest distance in distance array for all nodes
    // We make use of set to get the shortest distance element first always
    // we will make set<pair<int,int>> in which we store (node_shortest_distance, node_value)
    // we will push (0,first_node) in set and for first node distance initially is 0
    // we pick set top element and go to its neighbour and if top_element.distance + current_neighbour_distance < distance[current_neighbour]
    // we update it else we ignore it
    // We keep on doing this at the end we get our output in distance array

    // Create the adj list
    // As it is a weighted graph use pair<int,int> inside list
    unordered_map<int, list<pair<int, int>>> adj;

    // Fill the adj list
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        // For weight of node
        int w = vec[i][2];

        // As it is a undirected graph
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Make a distance array
    vector<int> dist(vertices);

    // Initialise it with infinity
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    // Mark the dist array value for source = 0
    dist[source] = 0;

    // Make a Set which will store <distance, node>
    // Set will store entries such that the lowest distance is at the beginning
    // A Set stores the elements in sorted order. Set stores unique elements. Elements can only be inserted and deleted but cannot be modified within the set.
    set<pair<int, int>> st;

    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // Get topnode from set
        // st.begin() returns a iterator so we use * to get the exact value
        auto topNode = *(st.begin());

        // Get values out of Set entry
        int distance_node = topNode.first;
        int node_value = topNode.second;

        // Remove that topnode from set
        st.erase(st.begin());

        // Go to neighbour of topnode node value
        for (auto neighbour : adj[node_value])
        {
            // if distance calculated is smaller tham current distance in array, then update it
            if (distance_node + neighbour.second < dist[neighbour.first])
            {
                // Check for any previous record inside the set for that same node value
                // In adj list we have stored nodes and weights like this
                // 1 -> {2,3}, {4,5} where 2,4 are value of neighbours of 1 and 3,5 are weights
                // so we use neighbour.second to refer to weight
                // neighbour.first to refer to value of node
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record is found, erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // Set new entry for that node value in distance array
                dist[neighbour.first] = distance_node + neighbour.second;

                // If its not found then push it in set
                st.insert(make_pair(distance_node + neighbour.second, neighbour.first));
            }
        }
    }

    // Return the distance array
    return dist;
}

int main()
{
    return 0;
}