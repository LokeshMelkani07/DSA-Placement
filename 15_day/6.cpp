#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

// Lecture 91: Topological Sort ( Using Kahn's Algorithm )

// Using Kahn's Algorithm
// TC: O(N+E)
// SC: O(N+E) for queue and adj list

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Creating a adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // As it is directed so
        adj[u].push_back(v);
    }

    // Make a indegree array
    vector<int> indegree(v);
    // Mark the indegree
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    // Make a queue to push all nodes with indegree = 0
    queue<int> q;
    // If indegree is 0 push it in the queue
    for(int i =0; i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    // Make an answer vector to store the answer
    vector<int> ans;

    // Do The following thing till queue gest empty
    while(!q.empty())
    {
        int element = q.front();
        q.pop();

        // Push the answer in the answer array
        ans.push_back(element);

        // Perform BFS
        int frontNode = element;

        // Finf its neighbour
        for(auto neighbour: adj[frontNode])
        {
            indegree[neighbour]--;

            // if indegree of neighbour becomes 0 push it in queue
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}