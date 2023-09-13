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
0 1 Knapsack
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.
Sample Input:

1
4 5
1 2 4 5
5 4 8 6

Sample Output:

13

Explanation of Sample output 1

The most optimal way to fill the knapsack is to choose items with weight 4 and value 8, weight 1 and value 5.

The total value of the knapsack =  8 + 5 = 13.

Sample Input 2:

1
5 100
20 24 36 40 42
12 35 41 25 32

Sample output 2:

101
*/

int solve(vector<int> &values, vector<int> &weights, int index, int capacity)
{
    // base case
    // if we have only one item left, whether we can include or not depends on space we have left in our knapsack
    // we are starting from end of the array, means we are at the index = 0 when we have base case reached so
    if (index == 0)
    {
        if (weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            // we cannot include last element so return 0
            return 0;
        }
    }

    // now we either include a item or we exclude it
    // if we inlude weight[i] we do capacity - weight[i]
    // we + values[i] in our answer also
    int include = 0;
    // when can we include something?
    // if we can fit it in our knapsack
    if (weights[index] <= capacity)
    {
        // if included, move to next index means index-1 as we are going last -> first index
        include = values[index] + solve(values, weights, index - 1, capacity - weights[index]);
    }
    // if excluded, capacity remains same
    // we move to next index that is index - 1 as we start from last index
    // we add 0 value in answer
    int exclude = 0 + solve(values, weights, index - 1, capacity);
    // our ans will be the one maximum(include,exclude)
    int ans = max(include, exclude);
    return ans;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return solve(values, weights, n - 1, w);
}

int solve(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    // if we have only one item left, whether we can include or not depends on space we have left in our knapsack
    // we are starting from end of the array, means we are at the index = 0 when we have base case reached so
    if (index == 0)
    {
        if (weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            // we cannot include last element so return 0
            return 0;
        }
    }
    // check DP array for ans
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // now we either include a item or we exclude it
    // if we inlude weight[i] we do capacity - weight[i]
    // we + values[i] in our answer also
    int include = 0;
    // when can we include something?
    // if we can fit it in our knapsack
    if (weights[index] <= capacity)
    {
        // if included, move to next index means index-1 as we are going last -> first index
        include = values[index] + solve(values, weights, index - 1, capacity - weights[index], dp);
    }
    // if excluded, capacity remains same
    // we move to next index that is index - 1 as we start from last index
    // we add 0 value in answer
    int exclude = 0 + solve(values, weights, index - 1, capacity, dp);
    // our dp[index][capacity] will be the one maximum(include,exclude)
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // creating 2D dp array of n rows and w+1 columns for index and capacity as these are only changing parameters
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(values, weights, n - 1, w, dp);
}

int solveTabulation(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // we analyse the base case
    // base case runs for weight[0]
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
        {
            dp[0][w] = values[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    // check other cases
    // our rows are of size = n
    // so our index will go from 0 to n-1, in base case we have done for 0th row, so we run ouer loop from i = 1 to i<n
    // our capacity will start from 0 to capacity so inner loop runs from 0 to <= capacity
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weights[index] <= w)
            {
                include = values[index] + dp[index - 1][w - weights[index]];
            }
            int exclude = 0 + dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return solveTabulation(values, weights, n, w);
}

int main()
{
    return 0;
}