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
Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // mark the node as visited
    visited[row][col] = 1;
    // make an queue to store {row,col}
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        // go for its neighbours
        for (int rows = -1; rows <= 1; rows++)
        {
            for (int cols = -1; cols <= 1; cols++)
            {
                // from this loop we will get all 8 direction combinations
                int nrow = curr_row + rows;
                int ncol = curr_col + cols;

                // validate for nrow and ncol
                // nrow and ncol should be a valid index
                // the block should not be visited already
                // the block should be a land i.e '1' and not water i.e '0'
                // if all condition satisfies, mark it visited and push it in queue
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    // if we consider all 1's as nodes we can see that number of times we apply bfs using different starting points = number of islands
    // we will instead of visited array now take visited 2D array
    // we will take a queue in which we store the index of 1's
    // we do not have adj list here so we make use of checking in all 8 directions of a node if in any of the valid direction we see 1 means there is a node, push that index in queue
    // Now how to get starting points, for that we search whole 2D matrix if any node is 1 and is not visited already we apply bfs on it
    // To check in neighbour of a node, we need to check all 8 directions and if we draw all 8 directions we see
    // we do row+1, row-1, row, col-1, col+1 and col and we make combination out of it only so for each value of row = 0,-1,1 we run a loop for col = 0,-1,+1 and add in current row and col value
    // for more understanding draw all 8 directions for a node and we know
    // we go left its row,col+1, right its row,col-1, up its row-1,col, down its row+1,col and so on
    // TC: O(n^2), SC: O(n^2)

    int n = grid.size();
    int m = grid[0].size();
    // make an visited array initlaised with 0
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // we make a count variable which tells how many bfs calls we made for each starting point which is = number of islands
    int count = 0;
    // we check for all starting points
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                // it will not all for all 1's becuase if a group of first island is together then it will get visited in the first bfs call so it does not enter for them here again
                // here only unique starting points will call for bfs so number of islands = count
                count++;
                bfs(i, j, visited, grid);
            }
        }
    }
    return count;
}

int main()
{
    return 0;
}