#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

// Lecture 98: Bridges in a Graph

void dfs(int node, int parent, vector<int> &discT, vector<int> &low, unordered_map< int, bool > &visited, vector<vector<int>> &result, unordered_map<int, list <int> > &adj, int &timer)

{

    visited[node] = true;

    discT[node] = low[node] = timer++;



    for(auto neighbour : adj[node])

    {

        if(neighbour == parent)

        {

            continue;

        }

        if(!visited[neighbour])

        {

            dfs(neighbour, node, discT, low, visited, result, adj, timer);

            low[node] =min(low[node], low[neighbour]);



            if(low[neighbour] > discT[node])

            {

                vector<int> ans;

                ans.push_back(node);

                ans.push_back(neighbour);

                result.push_back(ans);

            }

        }

        else

        {

             low[node] = min(low[node], discT[neighbour]);

        }

    }



}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list <int> > adj;

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