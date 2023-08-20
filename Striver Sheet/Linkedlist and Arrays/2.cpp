#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Trapping Rain Water
Problem link: https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
(refer to problem link for pictorial representation)

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

int trap(vector<int> &height)
{
    // Brute force
    // For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.
    // min(left[i],right[i]) - arr[i]
    // left[i] is maximum height of any building in left of i, found for 0 to i
    // right[i] is maximum height of any building in right of i,found for i to n-1
    // TC: O(n*n) and SC: O(1)
    int n = height.size();
    int waterFilled = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, height[j]);
            j--;
        }
        j = i;
        while (j <= n - 1)
        {
            rightMax = max(rightMax, height[j]);
            j++;
        }
        waterFilled += min(leftMax, rightMax) - height[i];
    }

    return waterFilled;
}

int trap(vector<int> &arr)
{
    // Better Approach
    // we are running 2 loops to find leftMax and rightMax
    // We will pre-compute leftMax and rightMax using prefix array and suffix array
    // prefix array is found for i = 0 to n-1, which contain max height from left for each index
    // suffix array is found for i = n-1 to 0, which contain max height from right for each index
    // we use then same formula min(prefix[i],suffix[i]) - arr[i] to get water filled
    // TC: O(3n), SC:O(N) + O(N) for prefix and suffix array
    int n = arr.size();
    int *prefix = new int[n];
    int *suffix = new int[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

int trap(vector<int> &height)
{
    // Most optimal approach
    // We use 2 pointer
    // We use l = 0, r = n-1
    // LeftMax = 0, rightMax = 0, result = 0
    // check if(a[l]<=a[r]) means if(a[i]>=leftMax) then no water stored there so leftMax = a[i]
    // else res += leftMax - a[i]
    // do l++
    // if a[l]>a[r] means check for rightMax now, if(a[r]>=rightMax) rightMax = a[r]
    // else res += rightMax - a[r];
    // r--
    // we run this loop till l>r i.e l crosses r
    // TC: O(n), SC:O(1)
    int n = height.size();
    int l = 0;
    int r = n - 1;
    int leftMax = 0, rightMax = 0, res = 0;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            // use LeftMax
            if (height[l] >= leftMax)
            {
                leftMax = height[l];
            }
            else
            {
                res += (leftMax - height[l]);
            }
            l++;
        }
        else
        {
            // use Rightmax
            if (height[r] >= rightMax)
            {
                rightMax = height[r];
            }
            else
            {
                res += (rightMax - height[r]);
            }
            r--;
        }
    }
    return res;
}

int main()
{
    return 0;
}