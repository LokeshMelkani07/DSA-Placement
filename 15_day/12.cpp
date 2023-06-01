#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

// Lecture 97: Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression

// TC: O(mlogm) where m is number fo edges
// SC: O(n)
bool cmp(vector<int> &a,vector<int> &b)
{
  // Sort according to the weight and weight is in 2nd index of edges array so
  return a[2] < b[2];
}

// Initialise the parent and rank vector
void makeSet(vector<int> &parent,vector<int> &rank,int n)
{
  for(int i = 0;i<n;i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
}

// Find parent of nodes
int findParents(int node,vector<int> &parent)
{
  // We start from the bottom node and go to the top
  // if node is parent of itself means we have reached the top parent
  if(parent[node] == node)
  {
    return node;
  }

  // parent[node] = findParents(parent[node],parent) is for path compression logic
  return parent[node] = findParents(parent[node],parent);
}

// Find union of 2 nodes
void findUnion(int u,int v,vector<int> &parent,vector<int> &rank)
{
  // Find the parent for both node u and v
  u = findParents(u,parent);
  v = findParents(v,parent);

  // Now find rank for both the parents of u and v
  if(rank[u] < rank[v])
  {
    // Make the bigger one, parent of smaller one
    parent[u] = v;
  }
  else if(rank[v]<rank[u])
  {
    parent[v] = u;
  }
  else{
    // Both rank are equal so make anyone parent of anyone and increment its rank
    parent[v] = u;
    rank[u]++;
  }

}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  // We need to srt the edges array related to weight so we make a comparator
  sort(edges.begin(),edges.end(),cmp);

  // Make a parent vector
  vector<int> parent(n);
  // Make a rank vector
  vector<int> rank(n);

  // Initialise parent and rank vector
  makeSet(parent,rank,n);

  // Kruskal's Algo
  // We need to return the total weight of minimum spanning tree so
  int weight = 0;
  // We run a loop and start processing for each element of sorted edges array
  for(int i = 0;i<edges.size();i++)
  {
    // u means node 1
    int u = findParents(edges[i][0],parent);
    // v means node 2
    int v = findParents(edges[i][1],parent);
    // w means weight
    int w = edges[i][2];

    // if parents are not equal merge them and add the weight in final answer
    if(u != v)
    {
      weight += w;
      findUnion(u,v,parent,rank);
    }
    // else if parents are same do nothing
  }

  return weight;
}
int main()
{
    return 0;
}