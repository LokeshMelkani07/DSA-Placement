#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Two Sum : Check if a pair with given sum exists in Array

Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
    [-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.
*/

vector<int> twoSum(vector<int> &nums, int target)
{
    // Brute force
    // Take each element and calculate for every index in a nested loop
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // Optimal Approach
    // We can use an unordered map to store <element,index>

    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]] = i;
    }

    // for each arr[i], let us check for target-arr[i] inside the map
    for (int i = 0; i < nums.size(); i++)
    {
        int difference = target - nums[i];
        // It is given in the question that do not use same index twice so mpp[difference] != i condition is important
        if (mpp.find(difference) != mpp.end() && mpp[difference] != i)
        {
            return {i, mpp[difference]};
        }
    }

    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // More Optimal Approach than above, in one go
    // We can use an unordered map to store <element,index>

    unordered_map<int, int> mpp;
    // for each arr[i], let us check for target-arr[i] inside the map
    for (int i = 0; i < nums.size(); i++)
    {
        int difference = target - nums[i];
        // It is given in the question that do not use same index twice so mpp[difference] != i condition is important
        if (mpp.find(difference) != mpp.end() && mpp[difference] != i)
        {
            return {i, mpp[difference]};
        }
        mpp[nums[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    return 0;
}