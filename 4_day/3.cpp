#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

// Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
int pivotIndex(vector<int>& nums) {
        int right = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(int i=0;i<nums.size();i++){
            right -= nums[i];
            if(left == right){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }

// Find pivot in an array
// Pivot means [3,8,10,17,1];
// here pivot is index:2, element = 10
int getPivot(vector<int> &arr,int size)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    while(start<end)
    {
        if(arr[mid]>= arr[0])
        {
            start = mid+1;
        }
        else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start; // return end; also can be written here
}

// Search In Rotated Sorted Array
// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

int getPivots(vector<int> &arr,int size)
{
    // Get the pivot
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    while(start<end)
    {
        if(arr[mid]>= arr[0])
        {
            start = mid+1;
        }
        else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start; // return end; also can be written here
}

int binary_search(vector<int> &arr,int start,int end,int key)
{
    // normal binary search
    int mid = start + (end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // get the pivot to check on which part we have to apply binary search to find our key
    int pivot = getPivot(arr,n);
    if(k >= arr[pivot] && k<=arr[n-1])
    {
        // apply binary search on left side of pivot
        return binary_search(arr,pivot,n-1,k);
    }
    else
    {
        // apply binary search on right side of pivot
        return binary_search(arr,0,pivot,k);
    }
}

// Square Root of a number
// https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// https://leetcode.com/problems/sqrtx/

long long int binary_Search(int x)
    {
        // mid*mid can go out of range of int so we are using long long int
        int start = 0;
        int end = x;
        long long int mid = start + (end-start)/2;

        long long int ans = -1;
        while(start<=end)
        {
            long long int square = mid*mid;
            if(square == x)
            {
                return mid;
            }

            if(square<x)
            {
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
        return binary_Search(x);
    }

// To find the decimal or more precise value of given number, we will use below function

double precision_value(int n,int precision,int integerValue)
{
    double factor = 1;
    double ans = integerValue;

    for(int i = 0;i<precision;i++)
    {
        factor = factor/10;
        for(double j = integerValue;j*j<n;j = j+factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"The integer value of square root of "<<n<<" is "<<binary_Search(n)<<endl;
    int val = binary_Search(n);
    cout<<"The Decimal or exact value of "<<n<<" is "<<precision_value(n,3,val)<<endl;
    return 0;
}