#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Combination Sum II – Find all unique combinations

In this article we will solve the most asked interview question “Combination Sum II – Find all unique combinations”.

Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Examples:

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.

Example 2:

Input: candidates = [2,5,2,1,2], target = 5

Output: [[1,2,2],[5]]

Explanation: These are the unique combinations whose sum is equal to target.
*/

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    // Base case if target is 0 means its a valid combo
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        // We need to ignore the duplicates
        // i>index means if same value occur at index other than current, ignore it but if we are at the first index i.e i==index means we can pick similar value its not duplicate
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target)
{
    // We need ans in sorted order so sort the array
    /*
    Time Complexity:O(2^n*k)
    Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.
    Space Complexity:O(k*x)
    Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
    */
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    return 0;
}