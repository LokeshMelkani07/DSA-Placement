#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Day 5 Recursion
// Merge Sort using Recursion | Day-5
// TC : O(nlogn)
// SC : O(n)

/*
Approach to do merge sort will be
1. Divide the array
2. Sort both the divided array
3. Merge 2 sorted arrays
   Merging will be done in a way that we create 2 arrays and copy values in them from left and right arrays [Divided array] and then we merge them
*/

// Merge two sorted arrays
void merge(int *arr,int s, int e)
{
    int mid = s + (e-s)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values of left array in first array

    int k = s;
    for(int i= 0; i<len1;i++)
    {
        first[i] = arr[k++];
    }



    // Copy values of right array in second array
    k = mid+1;
    for(int i= 0; i<len2;i++)
    {
        second[i] = arr[k++];
    }

    // Merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    while(index2 < len2)
    {
        arr[k++] = second[index2++];
    }

    // Delete the dynamic memory allocated to avoid memory leak
    delete []first;
    delete []second;
}


void mergeSort(int *arr,int start, int end)
{
    // base case
    if(start>=end)
    {
        return;
    }

    int mid = start + (end-start)/2;

    // Left vala sort karo
    mergeSort(arr,start,mid);

    // Right vala sort karo
    mergeSort(arr,mid+1,end);

    // Merge both sorted arrays
    merge(arr,start,end);
}

int main()
{
    int arr[7] = {38,27,43,3,9,82,10};
    mergeSort(arr,0,7);
    // print array
    for(auto it : arr)
    {
        cout<<it<<" ";
    }
    return 0;
}