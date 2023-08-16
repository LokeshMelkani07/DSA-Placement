#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Kadane’s Algorithm : Maximum Subarray Sum in an Array

// Problem Statement : Given an integer array arr, find the contiguous subarray(containing at least one number) which has the largest sum and returns its sum and prints the subarray.

int maxSubArray(vector<int> &nums)
{
    // brute force
    // simply run a loop
    // find sum for index = i to n and compare max sum
    int maxi = INT_MIN;
    int sum;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int maxSubArray1(vector<int> &nums)
{
    // Optimised approach

    // The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

    // Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

    int maxi = INT_MIN;
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

// If in the same problem it is also asked to consider empty subarray means if maxi<0 consider its sum  = 0

long long maxSubarraySum3(int arr[], int n)
{
    long long sum = 0;
    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi < 0 ? 0 : maxi;
}

// To store the subarray with maximum sum we will use start and end
// our max subarray always start from the point after which our sum = 0
// our end point of that subarray will be the one at which our sum>maxi

long long maxSubarraySumPrint(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }
}

int main()
{
    return 0;
}