#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Detect cycle in an undirected graph using BFS
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:

Input:
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
Output: 1
Explanation:

1->2->3->4->1 is a cycle.

Example 2:

Input:
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation:

No cycle in the graph.
*/

bool detect(int src, vector<int> adj[], int visited[])
{
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1}); // for first node, there is no parent so -1

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // check neighbours
        for (auto neighbours : adj[node])
        {
            if (!visited[neighbours])
            {
                // if neighbour is not visited, push it in queue with that node as neighbour
                visited[neighbours] = 1;
                q.push({neighbours, node});
            }
            else if (parent != neighbours)
            {
                // if its comes here means
                // ek neighbour already visited hai but uska parent current node nahi hai
                // means vo cycle vala node h, vo phele hi kisi aur node ke through visit krlia gya h so just
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // Using BFS
    // we will use BFS approach but to detect a cycle we need to use pair<int,int> in queue
    // To store node,parent where node is current node we are visiting and parent is node which brought us to current node
    // if there is a cycle for any node then one node will be already there in the queue with different parent which tells us that
    // yes,there is a cycle

    // there is something called disconnected components in graphs also
    // So to tackle the situation we need to run a loop for all the vertices
    // taking starting of loop as 0 or 1 based on question (here it is 0)
    // we again make a visited array and queue as its a bfs
    // TC: O(n+2E)
    // SC: O(2n)

    // int visited[V] = {0}; right
    int visited[10] = {0}; // wrong

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (detect(i, adj, visited))
            {
                // if, for any node cycle is detected means return true
                return true;
            }
        }
    }
    // if, no cycle detected for any node means return false
    return false;
}

int main()
{
    return 0;
}