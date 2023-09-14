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
Egg Dropping Puzzle
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below.

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation:
1. Drop the egg from floor 1. If it
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.

Example 2:

Input:
N = 2, K = 10
Output: 4
*/

// Recursive code

int solve(int egg, int floor)
{
    // if there is only 0 or 1 floor left
    if (floor == 0 || floor == 1)
        return floor;

    // if there is only 1 egg, then the floor we are at is the critical/threshold floor
    if (egg == 1)
        return floor;

    int mini = INT_MAX;

    // we run loop for each floor and apply break/ not break condition
    for (int k = 1; k <= floor; k++)
    {
        // we need to solve for the worst case so we use max() to get the worst case answer from break and not break coniditon for each floor
        int temp = 1 + max(solve(egg - 1, floor - 1), solve(egg, floor - k));

        // get the minimum number of attemps from that worst case answer to fing threshold floor
        mini = min(mini, temp);
    }
    return mini;
}

int eggDrop(int n, int k)
{
    return solve(n, k);
}

// Memoization

int solve(int egg, int floor, vector<vector<int>> &dp)
{
    // if there is only 0 or 1 floor left
    if (floor == 0 || floor == 1)
        return floor;

    // if there is only 1 egg, then the floor we are at is the critical/threshold floor
    if (egg == 1)
        return floor;

    if (egg == 0)
        return 0;

    if (dp[egg][floor] != -1)
        return dp[egg][floor];

    int mini = INT_MAX;

    // we run loop for each floor and apply break/ not break condition
    for (int k = 1; k <= floor; k++)
    {
        // we need to solve for the worst case so we use max() to get the worst case answer from break and not break coniditon for each floor
        int temp = 1 + max(solve(egg - 1, floor - 1, dp), solve(egg, floor - k, dp));

        // get the minimum number of attemps from that worst case answer to fing threshold floor
        mini = min(mini, temp);
    }
    return dp[egg][floor] = mini;
}

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n, k, dp);
}

int main()
{
    return 0;
}