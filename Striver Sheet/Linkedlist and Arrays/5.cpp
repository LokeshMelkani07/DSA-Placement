#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Count Maximum Consecutive One’s in the array

Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples:

Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1}

Output: 2

Explanation: There are two consecutive 1's in the array.
*/

int findMaxConsecutiveOnes(vector<int> &nums)
{
    // Optmised approach
    // We will use a count variable which will maintain count of 1's
    // we will use a max_count variable which will maintain count of max number of 1's
    // We iterate through the loop and if nums[i]==1 we do cnt++ otherwise we do cnt = 0
    // at the end of each iteration we compare count with max_count
    // TC: O(n), SC: O(1)
    int count = 0;
    int max_count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        max_count = max(count, max_count);
    }

    return max_count;
}

int main()
{
    return 0;
}