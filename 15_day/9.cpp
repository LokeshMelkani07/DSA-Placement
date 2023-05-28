#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<limits.h>
using namespace std;

// Lecture 94: Shortest Path in Directed Acyclic Graphs
// TC: O(N+E)
// SC: O(N+E) for adj list, stack space, distance array, visited array

class graph{

	public:

	// Here as it is a Directed Acyclic graph with some weights so we use list<pair<int,int>> to store node value and weight
	unordered_map<int ,list<pair<int, int>>> adj;

	// Adding the edge in the graph
	void addEdge(int a, int b, int weight){
		pair<int ,int> p = make_pair(b, weight);
		adj[a].push_back(p);
	}

	void printAdj()
	{
		for(auto i:adj){
		cout<<i.first<<"->";
			for(auto j: i.second){
				cout<<"[ "<<j.first<<","<<j.second<<" ]";
			}
			cout<<endl;
		}
	}


	// For topological sort
	void dfs(int node ,unordered_map<int , bool> &visited,  stack<int> &s)
	{

		visited[node] = 1;
		// neighbour is an pair in this case
		for(auto neighbour :adj[node]){
			if(!visited[neighbour.first]){
				dfs(neighbour.first, visited, s);
			}
		}
		s.push(node);
    }

	// Processing to prepare the distance array
	void getShortestPath(int src ,vector<int> &dist, stack<int> &s )
	{
		// Mark distance of source node = 0
		dist[src]=0;
		while(!s.empty()){

			// Get the top element
			int ele = s.top();
			s.pop();

			if(dist[ele] != INT_MAX){

				// Update the distance for the neighbouring node
				for(auto i :adj[ele]){
					// If value present is more then value found then update it in distance array
					if(dist[i.first] > dist[ele] + i.second)
					{
						dist[i.first] = dist[ele] + i.second;
					}
				}
			}

		}
	}
};

int main(){

	graph g;

	g.addEdge(0,1,5);
	g.addEdge(0,2,3);
	g.addEdge(1,2,2);
	g.addEdge(1,3,6);
	g.addEdge(2,3,7);
	g.addEdge(2,4,4);
	g.addEdge(2,5,2);
	g.addEdge(3,4,-1);
	g.addEdge(4,5,-2);

	g.printAdj();

	// Finding the topological sort order
	int n=6;

	unordered_map<int , bool> visited;

	stack<int> s;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			g.dfs(i, visited,  s);
		}
	}

	// Creating ditance array initialise with infinity which will store the shortest path
	vector<int> dist(n);
	for(int i=0;i<n;i++){

		dist[i] = INT_MAX;
	}

	// Let our source node be 1
	int src =1;

	// Calling shortest path function
	g.getShortestPath(src, dist, s);
	cout<<"Answer is " <<endl;
	for(int i=0;i<dist.size();i++){
		cout<<dist[i]<<" ";
	}
	return 0;

}
