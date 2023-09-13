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
Matrix Chain Multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension
40x20, 20x30, 30x10, 10x30. Say the matrices are
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D.
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.


Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions
10*30, 30*5, 5*60. Say the matrices are A, B
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The
number of multiplications are -
10*30*5 + 10*5*60 = 4500.
*/

int solve(int N, int arr[], int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int res = INT_MAX;
    int temp = 0;

    for (int k = left; k <= right - 1; k++)
    {
        temp = solve(N, arr, left, k) + solve(N, arr, k + 1, right) + (arr[left - 1] * arr[k] * arr[right]);
        res = min(res, temp);
    }

    return res;
}

int matrixMultiplication(int N, int arr[])
{
    // Gives TLE
    return solve(N, arr, 1, N - 1);
}

// Memoized code
int solve(int N, vector<int> arr, int left, int right, vector<vector<int>> &dp)
{
    if (left >= right)
    {
        return 0;
    }

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int res = INT_MAX;
    int temp = 0;

    for (int k = left; k <= right - 1; k++)
    {
        temp = solve(N, arr, left, k, dp) + solve(N, arr, k + 1, right, dp) + (arr[left - 1] * arr[k] * arr[right]);
        res = min(res, temp);
    }

    return dp[left][right] = res;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(N, arr, 1, N - 1, dp);
}

int main()
{
    return 0;
}
