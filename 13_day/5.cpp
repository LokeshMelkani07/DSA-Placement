#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 6
// Lecture 36
// Quick Sort using Recursion | Day-6
// TC = Best case is O(nlogn) and worst case is O(n^2)
// SC: O(n)
// Good for large dataset but not good for smaller dataset
// It is not an stable algorithm



// Partition Function
int partition(int *arr,int s,int e)
{
    // Take a pivot
    int pivot = arr[s];

    // Count number of element less than pivot
    int count = 0;
    for(int i = s+1;i<=e;i++)
    {
        if(arr[i] <= pivot)
        {
            count++;
        }
    }

    // Place the elemnt in its right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    // Now Put all smaller elements than pivot to its left
    // Now Put all greater elements than pivot to its right
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex)
    {
       // If left elements are already smaller than pivot just move i pointer
       while(arr[i]<=pivot)
       {
        i++;
       }

       // If right elements are already greater than pivot just move j pointer
       while(arr[j]>pivot)
       {
        j--;
       }

       // if thats not the case then swap them but i should be less than pivotIndex and j should be greater than pivotIndex
       if(i<pivotIndex && j>pivotIndex)
       {
        swap(arr[i++],arr[j--]);
       }

    }

    return pivotIndex;
}

void quick_sort(int *arr,int start,int end)
{
    // Base case
    if(start>=end)
    {
        return;
    }

    // Parition
    int p = partition(arr,start,end);

    // Left sort karo
    quick_sort(arr,start,p-1);

    // Right sort karo
    quick_sort(arr,p+1,end);
}

int main()
{
    int arr[9] = {2,40,1,6,9,36,4,23,89};
    int n = 9;

    quick_sort(arr,0,n-1);

    for(int x : arr)
    {
        cout<<x<<" ";
    }
    return 0;
}