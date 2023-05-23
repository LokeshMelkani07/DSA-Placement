#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<list>
#include<set>
using namespace std;

// Lecture 86: BFS Traversal in Graph
// TC: O(N+M) where N = number of nodes/vertex and M is number fo edges
// SC: O(N+M) where N = number of nodes/vertex and M is number fo edges


void  preparedAdjList ( unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){

    // Preparing adjacency list
    for(int i=0; i<edges.size();i++){

        int u= edges[i].first;

        int v= edges[i].second;


        // As it is a undirected graph
        adjList[u].insert(v);  // if we use list instead of set then we do adj[u].push_back(v)

        adjList[v].insert(u); // if we use list instead of set then we do adj[v].push_back(u)

    }

}



void bfs(  unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &visited,    vector<int>&ans,int node){

   queue<int>q;

   q.push(node);

   visited[node]=1;

    while(!q.empty()){

        int frontnode=q.front();

        q.pop();

        //storefrontnode to ans

        ans.push_back(frontnode);

        //traverse all neighbours of frontnode

        for(auto i:adjList[frontnode]){

            // If neighbour is not visited already then visit it
            if(!visited[i]){

                q.push(i);

                visited[i]=1;

            }

        }

    }

}



vector<int> BFS(int vertex, vector<pair<int, int>> edges)

{

    unordered_map<int,set<int>> adjList; // we can use list instead of set but we want answer in sorted order so we use set

    vector<int> ans;

    unordered_map<int,bool> visited;


    // Making an adjacency list
    preparedAdjList(adjList,edges);

    // traverse all components

    for(int i =0;i<vertex;i++){

        if(!visited[i]){

            bfs(adjList,visited,ans,i);

        }

    }

   return ans;

}

int main()
{
    return 0;
}