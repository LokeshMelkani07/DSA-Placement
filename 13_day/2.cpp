#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 3
// Recursion and Binary Search | Day-3

// Check if array is sorted using recursion
bool isSorted(int *arr, int size)
{
    // base case
    if(size==0 || size==1)
    {
        return true;
    }

    // processing
    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
        // Check next element so array size decreases
        bool remainingArray = isSorted(arr+1,size-1);
        return remainingArray;
    }
}

// Sum of Array using Recursion
int sumOfArray(int *arr,int size)
{
    // base case
    if(size==0)
    {
        return 0;
    }

    // Base case
    if(size==1)
    {
        return arr[0];
    }

    // Recurrence relation
    int remainingPart = sumOfArray(arr+1,size-1);
    // Processing
    int sum = arr[0] + remainingPart;

    return sum;
}

// Linear search using Recursion
bool linearSearch(int *arr,int size,int key)
{
    // Base case
    if(size==0)
    {
        return false;
    }

    // Solve for one case
    if(arr[0]==key)
    {
        return true;
    }
    else{
        // Rest will be solved by recursion
        bool remainingPart = linearSearch(arr+1,size-1,key);
        return remainingPart;
    }
}

// Binary Search Using Recursion
bool binarySearch(int *arr,int key,int start,int end)
{
    // base case
    // if element is not found
    if(start>end)
    {
        return false;
    }

    int mid = start + (end-start)/2;

    // base case
    // if element is found
    if(arr[mid]==key)
    {
        return true;
    }

    if(arr[mid]<key)
    {
        return binarySearch(arr,key,mid+1,end);
    }
    else
    {
        return binarySearch(arr,key,start,mid-1);
    }
}


int main()
{
    int arr[] = {1,2,3,5,6};
    int size = 5;

    // check array is sorted
    bool ans = isSorted(arr,size);

    if(ans)
    {
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    // Get sum of all elements in an array using recursion
    cout<<"The sum of Array is "<<sumOfArray(arr,size)<<endl;

    // Linear Search
    bool ans1 = linearSearch(arr,size,60);
    if(ans1)
    {
        cout<<"Key is present"<<endl;
    }
    else
    {
        cout<<"Key is absent"<<endl;
    }

    // Binary Search using Recursion
    // Array should be sorted [Mandatory Condition]
    bool ans2 = binarySearch(arr,10,0,size-1);
    if(ans2)
    {
        cout<<"Key is present"<<endl;
    }
    else
    {
        cout<<"Key is absent"<<endl;
    }
    return 0;
}