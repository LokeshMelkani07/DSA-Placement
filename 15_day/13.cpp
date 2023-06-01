#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

// Lecture 98: Bridges in a Graph
// TC: O(V+E)
// SC: O(V+E)

void dfs(int node, int parent, vector<int> &discT, vector<int> &low, unordered_map< int, bool > &visited, vector<vector<int>> &result, unordered_map<int, list <int> > &adj, int &timer)

{
    // Mark the node visited
    visited[node] = true;
    // Mark the discovery time and low time
    discT[node] = low[node] = timer++;

    for(auto neighbour : adj[node])
    {
        // If neighbour is parent then ignore that case
        if(neighbour == parent)
        {
            continue;
        }

        if(!visited[neighbour])
        {
            // Make a DFS call taking node as a parent and go to its neighbour now
            dfs(neighbour, node, discT, low, visited, result, adj, timer);
            // Update the low becuase our child can be connected to a back edge
            low[node] =min(low[node], low[neighbour]);


            // Check for a bridge
            if(low[neighbour] > discT[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else  // means node is already visited and not a parent so its a back edge
        {
             // else it is a back edge so update the low of node
             low[node] = min(low[node], discT[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list <int> > adj;

    // Prepare adj list
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> discT(v);
    vector<int> low(v);
    int parent = -1;

    unordered_map< int, bool > visited;

    //Initialize
    for(int i = 0; i<v; i++)
    {
        discT[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    //Call DFS

    for(int i = 0; i < v; i++)
    {
      if(!visited[i])
      {
        dfs(i, parent, discT, low, visited, result, adj, timer);
      }
    }

    return result;
}

int main()
{
    return 0;
}