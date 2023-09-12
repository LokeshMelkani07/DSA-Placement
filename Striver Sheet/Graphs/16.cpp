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
Floyd Warshall
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.

Example 1:

Input: matrix = {{0,25},{-1,0}}

Output: {{0,25},{-1,0}}

Explanation: The shortest distance between
every pair is already given(if it exists).

Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

Output: {{0,1,7},{1,0,6},{-1,-1,0}}

Explanation: We can reach 2 from 0 as 0->1->2
and the cost will be 1+6=7 which is less than
43.
*/

void shortest_distance(vector<vector<int>> &matrix)
{
    // Also known as multi-source shortest path algorithm
    // if there are no negative cycle, we can use dijksta for each node but it does not work for negative cycle
    // Earlier we were given a source and we needed to find shortest path from that source
    // But here, we should know shortest path from every node to every node
    // Helps in detecting negative cycle also
    // Let say we need to find shortest path between node 0 and node 1. Now, In how many ways we can go from 0 to 1?
    // We can go directly 0 to 1 and note the cost
    // we can go fromm 0->some node + some node->1 again note the cost
    // This way there are many ways to go from 0 to 1
    // Our answer for 0 to 1 is minimum of all such paths
    // So here we can also think of DP as we are using pre-computed paths also let say we need 0->4 + 4->1
    // Now 0->4 goes like 0->2->4  so if we already have 0->4 path, we can definately use it for our work
    // We generally use adjacency list but here we will use adj matrix. we will store weights in matrix[i][j] for node i to node j
    // for a node i to node i, weight will always be 0
    // Rest all node whose cost is not given will be marked as infinity
    // If its a undirected graph we convert it to directed like 1-5 in undirected means 1->5 and 5->1 in directed
    // if we fill the martix for node = 0
    // for matrix[1][2] value will be we need to go 1 to 2 via 0 so [1][2] = [1][0] + [0][2] now from matrix add the cost and if its lesser than already present value for [1][2] in matrix then update
    // Once we have computed for via 0, now we use that update matrix and compute for via 1
    // We know all diagnols will be 0 and node i to node i has cost = 0,
    // if we see carefully, 1th row and 1th col will have same value as previous matrix because it does not make sense to go [1][2] via 1 = [1][1] + [1][2] which is same as [1][2]
    // Now for left over values, we will do computations
    // Similarly we go for via 2 and via 3 and our final matrix will be output
    // We are just traversing a matrix and everytime cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j])
    // We do this for(via = 0; via<n ; via++)
    // So this is our n^3 loop
    // How to detect a negative cycle?
    // We know cost[i][i] is always 0 for non-negative so if cost[i][i] < 0 means there exist a negative cycle
    // In question, it is given that
    // If Matrix[i][j]=-1, it means there is no edge from i to j. so we make it INT_MAX initially for or algo and while returning we again make it -1
    // TC: O(n^3), SC: O(n^2)
    int n = matrix.size();
    // fill int_max instead of -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
            {
                // mark it 0
                matrix[i][j] = 0;
            }
        }
    }

    // algo starts
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    // for negative cycle
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            // negative cycle exists
        }
    }

    // fill -1 instead of int_max
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

int main()
{
    return 0;
}