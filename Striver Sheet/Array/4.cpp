#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Sort an array of 0s, 1s and 2s

// Problem Statement : Given an array consisting of only 0s, 1s, and2s. Write a program to in - place sort the array without using inbuilt sort functions.(Expected: Single pass - O(N) and constant space)

void sortColors(vector<int> &nums)
{
    // Brute force
    // count all 0's, 1's, 2's
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            cnt_0++;
        if (nums[i] == 1)
            cnt_1++;
        if (nums[i] == 2)
            cnt_2++;
    }

    // place the items in the array accordingly in the array
    for (int i = 0; i < cnt_0; i++)
        nums[i] = 0;
    for (int i = cnt_0; i < cnt_0 + cnt_1; i++)
        nums[i] = 1;
    for (int i = cnt_0 + cnt_1; i < n; i++)
        nums[i] = 2;
}

// Optimised approach
void sortColors(vector<int> &arr)
{
    // we can consider array to be divided into 3 parts
    // low, mid and high
    // where low contains 0, mid contains =1, high contains 2
    // low = 0, mid = 0, high = n-1
    // till mid<=high we run this loop

    int n = arr.size();
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    return 0;
}