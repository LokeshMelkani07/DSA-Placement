#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Subset Sum : Sum of all Subsets

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

void subsetSumHelper(vector<int> &num, int ind, int n, int sum, vector<int> &ans)
{
    // Base case
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    // Pick
    subsetSumHelper(num, ind + 1, n, sum + num[ind], ans);

    // Not pick
    subsetSumHelper(num, ind + 1, n, sum, ans);
}
vector<int> subsetSum(vector<int> &num)
{
    /*
    We will do a pick/Not pick approach in which we will maintain a sum variable
    we will start with the given array and start from first index
    We will pick first index, add it in the sum and do this till index == last index
    We store all sums in the answer vector
    We return back on hitting the base case and on returning we go to not pick case
    In not pick case, we do not add anything in the sum
    At the end, we sort the array and return it
    Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
    Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
    */
    vector<int> ans;
    int n = num.size();
    int sum = 0;
    subsetSumHelper(num, 0, n, sum, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}
