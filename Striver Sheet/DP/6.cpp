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
Minimum Path Sum
Medium

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

// Recursion Code

int solve(vector<vector<int>> &grid, int i, int j)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9; // we do not need to take this value so we return INT_MAX as min(left,up) will ignore INT_MAX automatically
    int up = grid[i][j] + solve(grid, i - 1, j);
    int left = grid[i][j] + solve(grid, i, j - 1);
    return min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return solve(grid, n - 1, m - 1);
}

// Memo Code

int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9; // we do not need to take this value so we return INT_MAX as min(left,up) will ignore INT_MAX automatically
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solve(grid, i - 1, j, dp);
    int left = grid[i][j] + solve(grid, i, j - 1, dp);
    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(grid, n - 1, m - 1, dp);
}

// Tabulation Code

int Tabulation(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }

                int left = grid[i][j];

                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return Tabulation(grid, n, m);
}

int main()
{
    return 0;
}