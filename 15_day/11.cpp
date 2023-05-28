#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

// Lecture 96: Minimum Spanning Tree || Prim's Algorithm
// TC: O(n^2) but can be optimised to O(nlogn) if we use priority queue to get the mini element

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Our Node starts from 1 to n
    // Creating an adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0 ;i<g.size();i++)
    {
        int u1 = g[i].first.first;
        int v1 = g[i].first.second;
        int w1 = g[i].second;

        // As it is undirected graph so
        adj[u1].push_back({v1,w1});
        adj[v1].push_back({u1,w1});
    }

    // We need 3 Data structures
    // Size is n+1 as our node starts from 1
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);

    // Initialise them
    for(int i = 1;i<=n;i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Let source node be 1 so mark it
    key[1] = 0;
    parent[1] = -1;

    // Processing starts for each node
    for(int i = 1;i<n;i++)
    {
        int mini = INT_MAX;
        int u;

        // Find minimum value from key array
        // The below for loop takes o(n) to find the minimum but we can use priority queue min heap to get minimum element in o(1)
        for(int v = 1;v<=n;v++)
        {
            // Keep the condition in mind that mst[index] should be false
            if(mst[v]==false && key[v]<mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Mark it mst
        mst[u] = true;

        // Explore its neighbours
        for(auto it: adj[u])
        {
            int v = it.first; // node adjacent to u in adj list
            int w = it.second; // weight value of node adjacent to u in adj list

            // if current value is smaller than stored value then modify it
            if(mst[v]==false && key[v]>w)
            {
                parent[v] = u;
                key[v] = w;
            }
        }

    }

    // Now we just need our parent array and store things in result array
    vector<pair<pair<int, int>, int>> result;

    // We start the index from 2 as parent of 1 is -1 which means 1 is the starting node
    for(int i = 2;i<=n;i++)
    {
      // {{parent,child}, weight} is format of our result array
      result.push_back({{parent[i],i},key[i]});
    }

    // return result

    return result;

}


// Code using Priority queue :
// TC: O(nlogn)

vector<pair<pair<int, int>, int>> calculatePrimsMSTs(int n, int m,vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;

    for(auto i : g) {

        int u = i.first.first;

        int v = i.first.second;

        int w = i.second;

        adj[u].push_back({v, w});

        adj[v].push_back({u, w});

    }

	// min heap to get node with minimum weight

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	// let source as 1, and inititally distance of source is 0

	// {weight, node}

	pq.push({0, 1});

    vector<int> key(n+1, INT_MAX), parent(n+1, -1), visited(n+1, 0);

    parent[1] = -1;

	// weight to reach i is key[i]

    key[1] = 0;

    while(pq.size())
    {

        int w = pq.top().first;

        int node = pq.top().second;

        visited[node] = 1;

        pq.pop();



		// find node with minimum weight and to to its neighbour

        for(auto neg: adj[node])
        {

            int toGo = neg.first;

            int toGoWeg = neg.second;

			// if to reach node N from key[N] update weight(key[N]) with distance from node to N
            if(visited[toGo] == 0 && toGoWeg < key[toGo])
            {
                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;

	// loop from 2 because parent of 1 is -1 (1 is initial node)

    for(int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}


int main()
{
    return 0;
}
