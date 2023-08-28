#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Print All Permutations of a String/Array

Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

Examples:

Example 1:

Input: arr = [1, 2, 3]

Output:
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

Explanation: Given an array, return all the possible permutations.

Example 2:

Input: arr = [0, 1]

Output:
[
  [0, 1],
  [1, 0]
]

Explanation: Given an array, return all the possible permutations.
*/

void solve(int index, string &s, vector<string> &ans, int n)
{
    if (index == n)
    {
        // base case -> we reach the last index
        ans.push_back(s);
        return;
    }

    // we pick a index and swap it with other indexes
    for (int j = index; j < n; j++)
    {
        // swap that particular index with other indexes of array
        swap(s[index], s[j]);
        // move to next index value
        solve(index + 1, s, ans, n);
        // back track step
        swap(s[index], s[j]);
    }

    return;
}
vector<string> findPermutations(string &s)
{
    vector<string> ans;
    int n = s.size();
    solve(0, s, ans, n);
    return ans;
}

int main()
{
    return 0;
}