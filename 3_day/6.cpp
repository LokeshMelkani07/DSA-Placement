#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Swap Alternate Numbers in array
void swap_alternate(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
            i++;
        }
    }
}

void print_array(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

// https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
// Find Unique
int findUnique(int *arr, int size)
{
    // One element is present only once, rest all are present twice, return the unique element
    int ans = 0;
    for(int i = 0;i<size;i++)
    {
        // a^a = 0
        // 0^a = a
        ans = ans^arr[i];
    }
    return ans;

}

// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
// Duplicate In Array
int findDuplicate(vector<int> &arr)
{
  int ans = 0;
  for(int i = 0;i<arr.size();i++)
  {
    ans = ans^arr[i];
  }

  for(int i = 1;i<arr.size();i++)
  {
    ans = ans^i;
  }

  return ans;

}

// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
// Intersection Of Two Sorted Arrays
/*
Got TLE
vector<int> ans;
	for(int i = 0;i<arr1.size();i++)
	{
	  int element = arr1[i];
     for(int j = 0;j<arr2.size();j++)
	 {
		if(element<arr2[j])
		{
			break;
		}
		if(element==arr2[j])
		{
			ans.push_back(arr2[j]);
			arr2[j] = -1;
			break;
		}
	 }
	}

	return ans;
*/

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0,j = 0;
	vector<int> ans;
	while(i<n && j<m)
	{
		if(arr1[i]<arr2[j])
		{
		  i++;
		}
		else if(arr1[i]==arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	return ans;
}


// https://www.codingninjas.com/codestudio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
// Pair Sum
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   for(int i = 0;i<arr.size();i++)
   {
       for(int j = i+1;j<arr.size();j++)
       {
           if(arr[i]+arr[j]==s)
           {
               vector<int> temp;
               temp.push_back(min(arr[i],arr[j]));
               temp.push_back(max(arr[i],arr[j]));
               ans.push_back(temp);
           }
       }
   }
   sort(ans.begin(),ans.end());
   return ans;
}

// https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
// Triplet with given sum or 3sum
vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       int n = nums.size();
        if(n<3)
            return {};
       sort(nums.begin(),nums.end());
        for(int i = 0;i<=n-2;i++)
       {
        if(i==0 || nums[i] != nums[i-1])
        {
            int j = i+1;
           int k = n-1;
           while(j<k)
           {

               int sum = nums[i]+nums[j]+nums[k];
               if(sum==0)
               {
                   result.push_back({nums[i],nums[j],nums[k]});
                   while(j<k && nums[j]==nums[j+1]) j++;
                   while(j<k && nums[k]==nums[k-1]) k--;
                   j++,k--;
               }
               else if(sum>0)
               {
                   k--;
               }
               else
               {
                   j++;
               }
           }
        }
       }
       return result;
    }

// https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
// Sort 0 1 2
void swap01(int arr[],int size)
{
    int left = 0;
    int right = size-1;
    while(left<right)
    {
        while(arr[left]==0 && left<right)
        {
            left++;
        }

        while(arr[right]==1 && left<right)
        {
            right--;
        }

        if(left<right)
        {
        swap(arr[left],arr[right]);
        left++;
        right--;
        }
    }
    print_array(arr,size);
}


int main()
{
    // Practice Questions Arrays
    int arr[] = {1,1,0,0,0,0,1,0};
    int size = sizeof(arr)/sizeof(int);
    // swap_alternate(arr,size);
    // print_array(arr,size);
    swap01(arr,size);
    return 0;
}
