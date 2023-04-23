#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Array Questions Part 1

// Reverse the array
// https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3
// m is position after which we need to reverse the array
void reverseArray(vector<int> &num , int m)
{
    int i = m+1;
    int j = num.size()-1;
    while(i<j)
    {
        swap(num[i],num[j]);
        i++;
        j--;
    }
}

// Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.Merge nums1 and nums2 into a single array sorted in non-decreasing order.The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = 0;
       int j = 0;
       int k = 0;
       vector<int> nums3(m+n);
       while(i<m && j<n)
       {
           if(nums1[i]<nums2[j])
           {
               nums3[k++] = nums1[i++];
           }
           else
           {
               nums3[k++] = nums2[j++];
           }
       }
       while(i<m)
       {
            nums3[k++] = nums1[i++];

       }
       while(j<n)
       {
            nums3[k++] = nums2[j++];
       }
       for(int i = 0;i<nums3.size();i++)
       {
           nums1[i] = nums3[i];
       }
}

// Other way
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
}

// Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// All non zero elements should be sorted in output array and All 0 elements should be at the end of array in the output array

 void moveZeroes(vector<int>& nums) {
        // Using 2 pointer approach
        // if element is 0, ignore it
        // if element is non zero, swap it
        int i = 0;
        for(int j = 0;j<nums.size();j++)
        {
            if(nums[j] != 0)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }


int main()
{
    vector<int> nums{1,56,32,2,4};
    int n = nums.size();
    return 0;
}