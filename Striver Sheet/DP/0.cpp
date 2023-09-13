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
Longest Increasing Subsequence
For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.
For example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.
Sample Input :

6
5 4 11 1 16 8

Sample Output 1 :

3

Explanation of Sample Input 1:

Length of longest subsequence is 3 i.e. [5, 11, 16] or [4, 11, 16].

Sample Input 2:

3
1 2 2

Sample Output 2 :

2
*/

int longestLengthSubsequence(int index, int prev, int arr[], int n)
{
    if (index == n)
        return 0;
    // Not - take case
    int len = 0 + longestLengthSubsequence(index + 1, prev, arr, n);
    // Take case
    if (prev == -1 || arr[index] > arr[prev])
    {
        //  prev = -1 means first index
        // arr[index]> arr[prev] means it makes a valid increasing subsequence
        // add +1 in length and move to next index, taking current index as previous
        // store the max length of take and not-takes case as we need longest increasing subsequence
        len = max(len, 1 + longestLengthSubsequence(index + 1, index, arr, n));
    }
    return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return longestLengthSubsequence(0, -1, arr, n);
}

int longestLengthSubsequence(int index, int prev, int arr[], int n,
                             vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];
    // Not - take case
    int len = 0 + longestLengthSubsequence(index + 1, prev, arr, n, dp);
    // Take case
    if (prev == -1 || arr[index] > arr[prev])
    {
        //  prev = -1 means first index
        // arr[index]> arr[prev] means it makes a valid increasing subsequence
        // add +1 in length and move to next index, taking current index as previous
        // store the max length of take and not-takes case as we need longest increasing subsequence
        len = max(len, 1 + longestLengthSubsequence(index + 1, index, arr, n, dp));
    }
    return dp[index][prev + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Memoization
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return longestLengthSubsequence(0, -1, arr, n, dp);
}

int main()
{
    return 0;
}
