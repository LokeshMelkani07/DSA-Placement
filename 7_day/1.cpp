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

 bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[n-1]>nums[0])
        {
            count++;
        }

        return count<=1;
}

// Sum Of Two Arrays
// You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
	int j = m-1;
	int carry = 0;
	vector<int> ans;

	while(i>=0 && j>=0)
	{
		int value1 = a[i];
		int value2 = b[j];
		int sum = value1 + value2 + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
		j--;
	}

	// 1st case when arr1 is greater than arr2
	while(i>=0)
	{
		int value1 = a[i];
		int sum = value1 + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
	}

	// 2nd case when arr2 is greater than arr1
	while(j>=0)
	{
		int value1 = b[j];
		int sum = value1 + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		j--;
	}

	// 3rd case when any carry is left
	while(carry)
	{
		int sum = carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}

	return reverse(ans);
}

vector<int> reverse(vector<int> &ans)
{
	int s = 0;
	int e = ans.size()-1;

	while(s<e)
	{
		swap(ans[s++],ans[e--]);
	}

	return ans;
}


int main()
{
    return 0;
}