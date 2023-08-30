#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Search Single Element in a sorted array

Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

Pre-requisite: Binary Search Algorithm

Examples

Example 1:
Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Result: 4
Explanation: Only the number 4 appears once in the array.

Example 2:

Input Format: arr[] = {1,1,3,5,5}
Result: 3
Explanation: Only the number 3 appears once in the array.
*/

int singleNonDuplicate(vector<int> &arr)
{
    // First approach
    // Use a hashmap simply
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }

    int ans;
    for (auto i : mpp)
    {
        if (i.second == 1)
        {
            ans = i.first;
        }
    }

    return ans;
}

int singleNonDuplicate(vector<int> &arr)
{
    // Second approach
    /*
    We can simplify the above approach using the XOR operation. We need to remember 2 important properties of XOR:
    a ^ a = 0, XOR of two same numbers results in 0.
    a ^ 0 = a, XOR of a number with 0 always results in that number.
    Now, if we XOR all the array elements, all the duplicates will result in 0 and we will be left with a single element.
    */
    // Time Complexity: O(N), N = size of the given array.
    // Reason: We are traversing the entire array.
    // Space Complexity: O(1) as we are not using any extra space.
    int n = arr.size(); // size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int singleNonDuplicate(vector<int> &arr)
{
    // We can apply the binary search
    // As this array is sorted
    // But to check whether any particular element is single element or not
    // We can check if arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1] then its a single element
    // The above condition will throw errors in the following 3 cases:
    // If the array size is 1.
    // If ‘mid’ points to 0 i.e. the first index.
    // If ‘mid’ points to n-1 i.e. the last index.
    // How to check in which half we are standing currently?
    // 0 1 2 3 4 5 6 7 8 9 10 are indexes of array
    // Let say our single element is at index = 6
    // even (0) ,odd (1) ,even (2), odd (3), even (4),odd (5) ,even (6),odd (7),even (8),odd (9),even (10)
    // before index = 6, (even,odd) sequence is there
    // after index = 6, (odd,even) sequence is there
    /*
        The index sequence of the duplicate numbers in the left half is always (even, odd). That means one of the following conditions will be satisfied if we are in the left half:
        If the current index is even, the element at the next odd index will be the same as the current element.
        Similarly, If the current index is odd, the element at the preceding even index will be the same as the current element.

        The index sequence of the duplicate numbers in the right half is always (odd, even). That means one of the following conditions will be satisfied if we are in the right half:
        If the current index is even, the element at the preceding odd index will be the same as the current element.
        Similarly, If the current index is odd, the element at the next even index will be the same as the current element.

        Now, we can easily identify the left and right halves, just by checking the sequence of the current index, i, like the following:

        If (i % 2 == 0 and arr[i] == arr[i+1]) or (i%2 == 1 and arr[i] == arr[i-1]), we are in the left half.
        If (i % 2 == 0 and arr[i] == arr[i-1]) or (i%2 == 1 and arr[i] == arr[i+1]), we are in the right half.

    */

    int n = arr.size(); // size of the array.

    // Edge cases:
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    return 0;
}