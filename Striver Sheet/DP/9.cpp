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
Rod cutting problem
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Sample Input 1:

2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20

Sample Output 1:

12
24

Explanation of sample input 1:

Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.


Test case 2:

Possible partitions are:
1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
and so on….

If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 8 pieces, we get 8*3 = 24.

Sample Input 2:

1
6
3 5 6 7 10 12

Sample Output 2:

18
*/

// Recursion Code

int solve(vector<int> &price, int index, int n)
{
    if (index == 0)
    {
        return n * price[0];
    }
    int notTake = 0 + solve(price, index - 1, n);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= n)
    {
        take = price[index] + solve(price, index, n - rodLength);
    }
    return max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    return solve(price, n - 1, n);
}

// Memo Code

int solve(vector<int> &price, int index, int n, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return n * price[0];
    }
    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }
    int notTake = 0 + solve(price, index - 1, n, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= n)
    {
        take = price[index] + solve(price, index, n - rodLength, dp);
    }
    return dp[index][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(price, n - 1, n, dp);
}

// Tabulation Code

int Tabulation(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[index - 1][N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= N)
            {
                take = price[index] + dp[index][N - rodLength];
            }
            dp[index][N] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

int cutRod(vector<int> &price, int n)
{
    return Tabulation(price, n);
}

int main()
{
    return 0;
}