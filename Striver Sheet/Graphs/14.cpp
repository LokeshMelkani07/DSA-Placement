#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Shortest path in an unweighted graph
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.
A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.
*/

// TC: O(N+E)
// SC: O(N+E) for queue and adj list and parent array

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // We will make a visited array
    // we will make a parent array
    // We will do a bfs traversal for that we need a queue also
    // when we pick any element, we mark its parent and mark it as visited then go to its nieghbours and push in queue
    // At the end we have a parent vector, now we pick destination node in vector and we backtrack to source node using parent vector
    // Then we see we have got the order but its in reverse order so reverse it to get original order

    // n is number of vertices
    // m is number of edges

    // Prepare adj list first
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // As it is a undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Make a visited Array
    unordered_map<int, bool> visited;
    // Make a Parents array
    unordered_map<int, int> parent;
    // Make a queue for BFS
    queue<int> q;

    // Insert the src node in queue and mark it visited
    q.push(s);

    visited[s] = true;

    // Mark parent of source node  = -1
    parent[s] = -1;

    // Start the BFS
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // Go in the neighbours
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
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
    while (currentNode != s)
    {
        // We use parent array to get parent of currentNode
        currentNode = parent[currentNode];

        ans.push_back(currentNode);
    }

    // Reverse the answer as we have started travelling from destination node -> source node
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    return 0;
}