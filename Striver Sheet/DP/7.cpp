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
Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0
*/

// Recursion Code

long solve(int *deno, int index, int T)
{
    if (index == 0)
    {
        return T % deno[0] == 0;
    }
    int notTake = solve(deno, index - 1, T);
    int take = 0;
    if (deno[index] <= T)
    {
        take = solve(deno, index, T - deno[index]);
    }
    return take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return solve(denominations, n - 1, value);
}

// Memo Code

long solve1(int *deno, int index, int T, vector<vector<long>> &dp)
{
    if (index == 0)
    {
        return T % deno[0] == 0;
    }
    if (dp[index][T] != -1)
    {
        return dp[index][T];
    }
    long notTake = solve1(deno, index - 1, T, dp);
    long take = 0;
    if (deno[index] <= T)
    {
        take = solve1(deno, index, T - deno[index], dp);
    }
    return dp[index][T] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve1(denominations, n - 1, value, dp);
}

// Tabulation Code

long Tabulation(int *deno, int value, int n)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % deno[0] == 0);
    }
    for (int index = 1; index < n; index++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = dp[index - 1][T];
            long take = 0;
            if (deno[index] <= T)
            {
                take = dp[index][T - deno[index]];
            }
            dp[index][T] = take + notTake;
        }
    }
    return dp[n - 1][value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return Tabulation(denominations, value, n);
}

int main()
{
    return 0;
}
