#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Lecture 92: Cycle Detection in Directed Graph
// Cycle detection in directed graph using BFS (Kahn's Algo)
// TC: O(N+E)
// SC: O(N+E) for queue, adj list

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Creating a adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<edges.size();i++)
    {
        // nodes are from 1 to n so we do -1
        int u = edges[i].first -1 ;
        int v = edges[i].second -1;

        // As it is directed so
        adj[u].push_back(v);
    }

    // Make a indegree array
    vector<int> indegree(n);
    // Mark the indegree
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    // Make a queue to push all nodes with indegree = 0
    queue<int> q;
    // If indegree is 0 push it in the queue
    for(int i=0; i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    // Make a count which stores the count
    int cnt = 0;

    // Do The following thing till queue gest empty
    while(!q.empty())
    {
        int element = q.front();
        q.pop();

        // Push the answer in the answer array
        cnt++;

        // Perform BFS
        int frontNode = element;

        // Finf its neighbour
        for(auto neighbour: adj[frontNode])
        {
            indegree[neighbour]--;

            // if indegree of neighbour becomes 0 push it in queue
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }

    // if count is same as number of vertices means its a valid topo sort and topo sort only valid in DAG means cycle not present
    if(cnt == n)
    {
      return false;
    }
    // if count is not same as numner of vertices means its not a valid topo sort means cycle is present
    return true;
}

int main()
{
    return 0;
}