// Binary Search Questions
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// First and Last Position of an Element In Sorted Array
// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

int first_occurence(vector<int> &arr,int n,int key)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>key)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int last_occurence(vector<int> &arr,int n,int key)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid]>key)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int ans1 = first_occurence(arr,n,k);
    int ans2 = last_occurence(arr,n,k);
    return {ans1,ans2};
}

//  Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/
 int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end-start)/2;
        while(start<end)
        {
            if(arr[mid]<arr[mid+1])
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }

int main()
{
    return 0;
}