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
Subset Sum Equal To K
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Sample Input 1:

2
4 5
4 3 2 1
5 4
2 5 1 6 7

Sample Output 1:

true
false

Explanation For Sample Input 1:

In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.

Sample Input 2:

2
4 4
6 1 2 1
5 6
1 7 2 9 10

Sample Output 2:

true
false

Explanation For Sample Input 2:

In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.
*/

// Recursion Code

bool solve(int index, int target, vector<int> arr)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[0] == target;
    bool notTake = solve(index - 1, target, arr);
    bool take = false;
    if (target >= arr[index])
    {
        take = solve(index - 1, target - arr[index], arr);
    }
    return take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solve(n - 1, k, arr);
}

// Memo Code

bool solve(int index, int target, vector<int> arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[0] == target;
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    bool notTake = solve(index - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[index])
    {
        take = solve(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// Tabulation Code

bool Tabulation(int n, int k, vector<int> arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[index - 1][target];
            bool take = false;
            if (target >= arr[index])
            {
                take = dp[index - 1][target - arr[index]];
            }
            dp[index][target] = take | notTake;
        }
    }
    // we are going from 0 to n-1 here in index and 0 to k in target so dp[n-1][k] has our answer
    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return Tabulation(n, k, arr);
}

int main()
{
    return 0;
}