#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

// Lecture 89: Cycle Detection in Directed Graphs

// TC: o(N+E) i.e node + edges
// SC: o(N+E) for DFS Visited and adj list is given mostly

// Using DFS
bool cycleFound(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &DFSvisited,unordered_map<int,list<int>> &adj)
{
  // Mark the node visited
  visited[node] = true;
  // Mark the DFS[node] true
  DFSvisited[node] = true;

  // now check the adj list of that node
  for(auto neighbour : adj[node])
  {
    // if that neighbour is not visited just visit it
    if(!visited[neighbour])
    {
      bool cycleCheck = cycleFound(neighbour,visited,DFSvisited,adj);

      if(cycleCheck)
      {
        return true;
      }
    }
    else if(DFSvisited[neighbour])
    {
      // if it comes under this case means
      // node is visited and its dfs cycle is marked true
      return true;
    }
  }

  // Backtrack step
  // While coming back mark its DFS[node] = false;
  DFSvisited[node] = false;

  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   // Make a adjacency list
   unordered_map<int,list<int>> adj;
   for(int i = 0;i<edges.size();i++)
   {
     int u = edges[i].first;
     int v = edges[i].second;

     // As it is a directed graph
     adj[u].push_back(v);
   }

   // Make a visited DS
   unordered_map<int,bool> visited;
   // Make a DFSvisited DS
   unordered_map<int,bool> DFSvisited;

   // we write a for loop to consider disconected graph case also
   // Node are from 1 to n in input format so we use this
   for(int i = 1;i<=n;i++)
   {
     if(!visited[i])
     {
       bool cycleFoundd = cycleFound(i,visited,DFSvisited,adj);

       if(cycleFoundd)
       {
         return 1;
       }
     }
   }

   return 0;
}

int main()
{
    return 0;
}