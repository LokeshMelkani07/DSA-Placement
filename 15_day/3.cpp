#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// Lecture 88: Cycle Detection in Undirected Graphs

// USING BFS
// TC: O(V+E)




bool isCyclicBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front])
        {
            if(visited[neighbour]==true && neighbour != parent[front])
            {
                // It is cyclic
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

// USING DFS
// TC: O(V+E)
bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    visited[node] = true;
    for(auto neighbour: adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetected)
                return true;
        }
        else if(neighbour != parent) // means visited is true and neighbour is not parent means its cyclic
        {
                // cycle is present
                return true;
        }
    }

    return false;

}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   // Make an Adjacency list
   unordered_map<int,list<int>> adj;
   for(int i = 0;i<m;i++)
   {
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
       // as it is a undirected graph
       adj[v].push_back(u);
   }

   unordered_map<int,bool> visited;
   // To handle disconnected components
   for(int i=0;i<n;i++)
   {
       if(!visited[i])
       {
           //bool ans = isCyclicBFS(i,visited,adj); // if using BFS
           bool ans = isCyclicDFS(i,-1,visited,adj); // if using DFS
           if(ans==1)
           {
               return "Yes";
           }
       }
   }

   return "No";
}



int main()
{
    return 0;
}