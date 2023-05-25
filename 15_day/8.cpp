#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

// Lecture 93: Shortest Path in Undirected Graphs

// TC: O(N+E)
// SC: O(N+E) for queue and adj list and parent array

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

	// n is number of vertices
	// m is number of edges

	// Prepare adj list first
	unordered_map<int,list<int>> adj;
	for(int i = 0;i<edges.size();i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		// As it is a undirected graph
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Make a visited Array
	unordered_map<int,bool> visited;
	// Make a Parents array
	unordered_map<int,int> parent;
	// Make a queue for BFS
	queue<int> q;

	// Insert the src node in queue and mark it visited
	q.push(s);

	visited[s] = true;

	// Mark parent of source node  = -1
	parent[s] = -1;

	// Start the BFS
	while(!q.empty())
	{
		int frontNode = q.front();
		q.pop();

		// Go in the neighbours
		for(auto neighbour : adj[frontNode])
		{
			if(!visited[neighbour])
			{
				// Mark neighbours visited
				visited[neighbour] = true;
				// Mark the parent of neighbour
				parent[neighbour] = frontNode;
				// Push the neighbour in queue
				q.push(neighbour);
			}
		}
	}

	// Now we have our visisted and Parent array ready
	// We need to find the shortest path now

	// t is destination node
	int currentNode = t;

	// Make an output vector
	vector<int> ans;

	// Push t in ans
	ans.push_back(currentNode);

	// Run loop till currentNode is not equal to soruce
	while(currentNode != s)
	{
		// We use parent array to get parent of currentNode
		currentNode = parent[currentNode];

		ans.push_back(currentNode);

	}

	// Reverse the answer as we have started travelling from destination node -> source node
	reverse(ans.begin(),ans.end());

	return ans;

}


int main()
{
    return 0;
}