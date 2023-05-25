#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<list>
using namespace std;

// Lecture 90: Topological Sort ( Using DFS )
// Using DFS
// We will use extra space for stack and visited array and recursive call
// All these extra spaces will be linear that is O(vertices)
// TC: O(N+E)
// SC: O(N)

// If our solution faces TLE we can use vector<vector<int>> to make adj list
// We can use vector<bool> instead of unordered_map<int,bool> to make visited array

void topoSort(int node,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj)
{
    // Mark the current node visited
    visited[node] = true;

    // Check all its neighbours from its adj list
    for(auto neighbour: adj[node])
    {
        if(!visited[neighbour])
        {
            topoSort(neighbour,visited,s,adj);
        }
    }

    // While coming back push the element in the stack
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Making an adjacency list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<e;i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];

      // As it is a Directed Acyclic graph
      adj[u].push_back(v);
    }

    // Make a visited array
    vector<bool> visited(v);
    // Make a stack
    stack<int> s;
    // Check for all nodes considering disconnected graph also
    // Indexing starts from 0 to n so we use i=0 -> n
    for(int i = 0;i<v;i++)
    {
        if(!visited[i])
        {
            topoSort(i,visited,s,adj);
        }
    }

    // Copy The order from stack to a vector and return it
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;

}

int main()
{
    return 0;
}