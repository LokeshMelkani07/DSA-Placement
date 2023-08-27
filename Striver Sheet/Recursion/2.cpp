#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Combination Sum – 1

Problem Statement:

Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples:

Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times. 7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is possible.
*/

void solve(int index, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds)
{
    // Base case
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[index] <= target)
    {
        // Pick
        ds.push_back(arr[index]);
        solve(index + 1, arr, target - arr[index], ans, ds);
        ds.pop_back();
    }

    solve(index + 1, arr, target, ans, ds);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // We will use a pick/Not pick approach
    // But in the question, it is said that we can pick a element infinite number of times
    // So we will pick a index till the time arr[index] <= target
    // We will start with an emoty DS and fill values inside it
    // we keep on doing target-arr[index] everytime
    // base case will be when we reach end of the array and if at the end of array, target becomes 0 means its a valid combo, so store in the answer vector
    // otherwise go for index+1
    // TC: O(2^target*k) SC: O(k*x) where x is number of combo
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, arr, k, ans, ds);
    return ans;
}

int main()
{
    return 0;
}