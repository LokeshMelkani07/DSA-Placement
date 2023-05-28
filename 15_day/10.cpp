#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;

// Lecture 95: Dijkstra's Algorithm

// TC: O(ElogV) where E is edges and V is vertices, log is due to using set
// SC: O(N+E)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create the adj list
    // As it is a weighted graph use pair<int,int> inside list
    unordered_map<int,list<pair<int,int>>> adj;

    // Fill the adj list
    for(int i = 0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        // For weight of node
        int w = vec[i][2];

        // As it is a undirected graph
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // Make a distance array
    vector<int> dist(vertices);

    // Initialise it with infinity
    for(int i = 0;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }

    // Mark the dist array value for source = 0
    dist[source] = 0;

    // Make a Set which will store <distance, node>
    // Set will store entries such that the lowest distance is at the beginning
    // A Set stores the elements in sorted order. Set stores unique elements. Elements can only be inserted and deleted but cannot be modified within the set.
    set<pair<int,int>> st;

    st.insert(make_pair(0,source));

    while(!st.empty())
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
        for(auto neighbour: adj[node_value])
        {
            // if distance calculated is smaller tham current distance in array, then update it
            if(distance_node + neighbour.second < dist[neighbour.first])
            {
                // Check for any previous record inside the set for that same node value
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                // if record is found, erase it
                if(record != st.end())
                {
                    st.erase(record);
                }

                // Set new entry for that node value in distance array
                dist[neighbour.first] = distance_node + neighbour.second;

                // If its not found then push it in set
                st.insert(make_pair(distance_node + neighbour.second,neighbour.first));

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