#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find the duplicate in an array of N+1 integers

Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.
*/

int findDuplicate(vector<int> &nums)
{
    // Brute force nlogn + n
    // Sort the array
    // if arr[i] == arr[i+1] return arr[i] as answer
    int n = nums.size();
    if (n == 2)
    {
        return nums[0];
    }
    int ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans = nums[i];
        }
    }
    return ans;
}

int findDuplicate(vector<int> &nums)
{
    // Optimised approach we will use an unordered_map and store the frequency of each number
    // As all numbers are repeated once except one duplicate number so
    // Number with frequency > 1 will be our answer
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    int ans = 0;
    for (auto i : mpp)
    {
        if (i.second > 1)
        {
            ans = i.first;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
