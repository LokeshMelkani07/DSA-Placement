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
Maximum sum increasing subsequence
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}
*/

int solve(vector<int> &arr, int n)
{
    int maxi = 0;
    // int MSIS[n]; right
    int MSIS[10]; // wrong

    for (int i = 0; i < n; i++)
    {
        // fill MSIS
        MSIS[i] = arr[i];
    }

    // Fill MSIS with maximum increasing subsequence sum for any index
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && MSIS[i] < MSIS[j] + arr[i])
            {
                // for 0th index there is no one behind so arr[0] is its max value
                // for other index we check from 0 till that index
                // if it is forming increasing subsequence which we check by arr[i] > arr[j]
                // if MSIS has lower value, update it
                // we can update MSIS[i]
                MSIS[i] = arr[i] + MSIS[j];
            }
        }
    }

    // get max sum value
    for (int i = 0; i < n; i++)
    {
        if (maxi < MSIS[i])
        {
            maxi = MSIS[i];
        }
    }

    return maxi;
}

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    return solve(arr, n);
}

int main()
{
    return 0;
}