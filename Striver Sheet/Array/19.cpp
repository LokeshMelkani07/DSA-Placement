#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Count inversions in an array

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
*/

int numberOfInversions(vector<int> &a, int n)
{
    // Brute force approach
    // we will run a outer loop for i = 0 to i<n
    // we will run a inner loop for j = i+1 to j<n in which we will check the condition for each value of i
    // i>j always because we are running inner loop from j = i+1
    // so make a count variable to count number of inversions
    // if(a[i]>a[j]) count++
    // return count

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                count++;
        }
    }

    return count;
}

// Optimised approach
// Let us say we have 2 sorted arrays
// We take 2 point i and j on arr1 and arr2
// we take a count variable to count number of inversion pair
// now using 2 pointers we check whether arr1[i] and arr2[j] can make a pair or not
// To make a pair, condition needed is arr1[i]>arr2[j]
// we start i and j from beginning of arr1 and arr2
// we compare if(arr1[i]<=arr2[j]) just do i++
// if arr1[i]>arr2[j] we say yes, they can make a pair so count++ but but
// arrays are sorted so if i=1 position of arr1 is > jth position of arr2 means all other elements of arr1 can make pair with that jth position of arr2 also
// so we do count = count + (N-i)
// now move j++
// again compare same things if arr1[i]<=arr2[j] just do i++ else if arr1[i]>arr2[j] then count = count + (N-i)
// we do this till any one of the array gets exhausted
// this way we get all inversion pairs for 2 sorted arrays given

// But in the question we have only one array so we think of merge sort approach
// which works on dividing the array and sorting them just we need to add this arr1[i]>arr2[j] condition
// Merge sort code is same just that we have added 3 modifications

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr
    for (int i = low; i <= high; i++)
    {
        // temp has all element in reversed order so
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    // go till the end of left subtree till only one-one element left
    cnt += mergeSort(arr, low, mid); // left half
    // go till the end of right subtree till only one-one element left
    cnt += mergeSort(arr, mid + 1, high); // right half
    // Merge both halves
    cnt += merge(arr, low, mid, high); // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> &a, int n)
{

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    return 0;
}
