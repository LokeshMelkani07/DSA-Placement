#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;
// we make it a template to make it generic
template <typename T>

// Graph
// Representation of graph using adjacency list

class graph{

  public:
  unordered_map<T,list<T>> adj;

  void addEdge(T u,T v,bool direction)
  {
    // direction  = 0 means undirected graph
    // direction = 1 means directed graph

    // create an edge between u and v
    // u -> v
    adj[u].push_back(v);
    if(direction==0)
    {
        // means its a undirected graph se make an edge from v -> u also
        adj[v].push_back(u);
    }
  }

  void printAdjList()
  {
     for(auto i: adj)
     {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
        {
            cout<<j<<", ";
        }
        cout<<endl;
     }
  }
};

// Creating and Printing
// In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // n is number of nodes
    // m is number of edges
    // return answer in vector<vector<int>>
    vector<vector<int>> answer(n);
    // answer will store all adjacent nodes
    for(int i = 0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        answer[u].push_back(v);
        // as its undirected
        answer[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    // Entering neighbours
    for(int i = 0;i<n;i++)
    {
        adj[i].push_back(i);
        for(int j = 0;j<answer[i].size();j++)
        {
            adj[i].push_back(answer[i][j]);
        }
    }

    return adj;
}

int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    graph<int> g;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        // Creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
    return 0;
}
