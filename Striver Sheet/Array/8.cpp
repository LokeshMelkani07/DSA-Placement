#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Merge two Sorted Arrays Without Extra Space

Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/

/*
void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    // Insert the elements from the 2 arrays
    //  into the 3rd array using left and right
    //  pointers:

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}
*/

/*

// Optimised
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // we will use a left pointer and index pointer
    // index point points to first element of b[]
    // left pointer points to last element of a[] i.e max element of a[]
    // we move left towards 0 of a[]
    // we move index towards m-1 position of b[]
    // we compare a[left] and b[index]
    // if a[left]>b[index] then swap both and move left-- and index++
    // if a[left]<=b[index] then things are ok no need to do anything and break as both arrays are sorted
    // this way, a[] will contain all smaller elements and b[] will contain all bigger elements
    // at the end just sort()
    int n = a.size();
    int m = b.size();
    int left = n - 1, index = 0;

    while (left >= 0 && index < m)
    {
        if (a[left] > b[index])
        {
            // swap them and move the pointers
            swap(a[left], b[index]);
            left--;
            index++;
        }
        else
        {
            // do nothing
            break;
        }
    }

    // sort
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

*/
int main()
{
    return 0;
}