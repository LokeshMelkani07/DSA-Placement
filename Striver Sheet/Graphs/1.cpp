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
BFS of graph
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Example 1:

Input:
V = 5, E = 4
edges = {(0,1),(0,2),(0,3),(2,4)}


Output:
0 1 2 3 4
Explanation:
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.

Example 2:

Input:
V = 3, E = 2
edges = {(0,1),(0,2)}

Output:
0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2.
*/

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // bfs means traversing level-wise level
    // We will first see the starting node
    // if our starting node is 0 according to example 1, then we go level-wise
    // 0 then 1,2,3 then 4
    // if starting node is given to be something else, we take nodes at edge = 1 as level one
    // nodes at edge = 2 as level 2 and so on
    // we will also take an visited array and queue
    // adj list is already given to us in form int -> list<int>
    // V = number of vertices i.e number of nodes
    // TC: O(n) + O(degree i.e 2*edges)
    // SC: O(3n)

    // int visited[V] = {0}; right
    int visited[10] = {0}; // wrong

    queue<int> q;
    q.push(0); // as its 0-based indexing
    visited[0] = 1;
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // check its neighbours
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main()
{
    return 0;
}