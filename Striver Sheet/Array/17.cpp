#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Subarray Sums Divisible by K
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0
*/

int subarraysDivByK(vector<int> &nums, int k)
{
    // we will use prefixSum concept
    // we wil store sum and count in the map
    long long prefixSum = 0;
    int count = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        // calculate the prefix sum
        prefixSum += nums[i];
        // check if divisble or not
        int res = prefixSum % k;

        if (res == 0)
        {
            // means divisble so count++
            count++;
        }
        if (res < 0)
        {
            // if answer of mod comes out negative we add +k in it to make it positive in c++ so we make res positive if its negative
            res += k;
        }

        // if there is any value of res in map
        if (mpp[res])
        {
            // store in count
            count += mpp[res];
        }
        // and do
        mpp[res]++;
    }
    return count;
}

int main()
{
    return 0;
}