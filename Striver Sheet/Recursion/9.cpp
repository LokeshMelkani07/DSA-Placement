#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
M – Coloring Problem

Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Examples:

Example 1:
Input:
N = 4
M = 3
E = 5
Edges[] = {
  (0, 1),
  (1, 2),
  (2, 3),
  (3, 0),
  (0, 2)
}

Output: 1

Explanation: It is possible to colour the given graph using 3 colours.

Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {
  (0, 1),
  (1, 2),
  (0, 2)
}

Output: 0
Explanation: It is not possible to color.
*/

bool isSafe(int node, vector<vector<int>> &mat, int color[], int m, int rang)
{
    // if no 2 adjacent node have same color means we can colour it
    for (int k = 0; k < mat.size(); k++)
    {
        // mat[k][node]==1 means there is an edge so its adjacent
        // color[k] = rang means if that adjacent node has same colour means not possible
        if (k != node && mat[k][node] == 1 && color[k] == rang)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, vector<vector<int>> &mat, int color[], int m)
{
    // Base case if we have colours all nodes
    if (node == mat.size())
    {
        return "YES";
    }

    // Check for each color
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, mat, color, m, i))
        {
            // if its safe to color, then color it
            color[node] = i;
            if (solve(node + 1, mat, color, m))
            {
                // if we can colour for one case, no need to make other recursive
                // call, just return true
                return true;
            }
            // backtrack step
            color[node] = 0;
        }
    }

    // if we are here means could not colour a node with any colour means its not possible to colour the graph with m colours so return false
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Initialise a colour array to store colour for each node
    // int color[mat.size()] = {0}; // right
    int color[100] = {0}; // wrong
    if (solve(0, mat, color, m))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    return 0;
}