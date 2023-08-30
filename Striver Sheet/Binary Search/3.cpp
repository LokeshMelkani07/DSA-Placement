#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Search Element in a Rotated Sorted Array

Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.


Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/

int search(int *arr, int n, int k)
{
    // Brute force, we can simply apply linear search and find the element
    // we see before and after the pivot point, array is sorted in ascending order
    // So we can apply binary search in that part
    // if our mid comes at left part
    // we check where does our target occur at the left part
    /*
    Identify the sorted half, check where the target is located, and then eliminate one half accordingly:
    If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
        If arr[low] <= target && target <= arr[mid]: It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
        Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.

    Otherwise, if the right half is sorted:
        If arr[mid] <= target && target <= arr[high]: It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
        Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.

    Once, the ‘mid’ points to the target, the index will be returned.
    This process will be inside a loop and the loop will continue until low crosses high. If no index is found, we will return -1

    Time Complexity: O(logN), N = size of the given array.
    Reason: We are using binary search to search the target.

    Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
    */

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return mid;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}