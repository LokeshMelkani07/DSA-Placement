#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Array Questions Part 2

// Rotate Array
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()] = nums[i];
        }

        nums = temp;
}

// 2nd approach

void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
}

// 3rd approach
void reverse(vector<int> &arr,int start,int end)
{
        int a = start;
        int b = end;
        while(a<b)
        {
            swap(arr[a++],arr[b--]);
        }
}
void rotate(vector<int>& nums, int k)
{
         int size = nums.size();
        k = k%size;
        if(size==1)
            return;
         if(k<0) k += size;
         reverse(nums,0,size-k-1);
        reverse(nums,size-k,size-1);
        reverse(nums,0,size-1);
}

// Check if Array Is Sorted and Rotated
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.There may be duplicates in the original array.





int main()
{
    return 0;
}