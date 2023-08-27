#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Subset – II | Print all the Unique Subsets

Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Examples:

Example 1:

Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]

Output: [ [ ], [1] ]

Explanation: Only two unique subsets are available
*/

void solve(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    for (int i = index; i < arr.size(); i++)
    {
        // i!=index because we need to store only the first occurence and ignore the other occurences of a duplicate
        if (i != index && arr[i - 1] == arr[i])
        {
            continue;
        }
        ds.push_back(arr[i]);
        // Call for next indexes
        solve(i + 1, arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // TC: O(2^n*n) SC: O(2^n*k)
    // We will sort the array
    // We will do pick and not pick concept but this time if arr[i-1] == arr[i], we do not pick
    // We will use a DS to store subsets
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    solve(0, arr, ans, ds);
    return ans;
}

int main()
{
    return 0;
}