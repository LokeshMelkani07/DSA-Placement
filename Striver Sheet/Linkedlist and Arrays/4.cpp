#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.

Example 1:

Input: arr[1,1,2,2,2,3,3]

Output: arr[1,2,3,_,_,_,_]

Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2:

Input: arr[1,1,1,2,2,3,3,3,3,4,4]

Output: arr[1,2,3,4,_,_,_,_,_,_,_]

Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/

int removeDuplicates(vector<int> &nums)
{
    // Brute force approach
    // We can use a Hashset as it stores non-duplicate elements only
    // TC: O(nlogn) + O(n) for insertion in set and then inserting back in array
    // SC: O(n) for usign set
    // return the size of the resultant array
    set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    int j = 0;
    int k = st.size();
    for (auto x : st)
    {
        nums[j++] = x;
    }

    return k;
}

int removeDuplicates(vector<int> &nums)
{
    // Optimised approach
    // We need to get rid of this extra space
    // We can use 2 pointer approach
    // we use i =0, j = from 1 to n-1
    // for each i, we check if arr[i]==arr[j]
    // if yes, move j++
    // if arr[i] != arr[j] then i++, arr[i]=arr[j]
    // at the end i+1 is the size of our resultant array
    // TC: o(n), SC: O(1)
    int i = 0;
    int n = nums.size();
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

int main()
{
    return 0;
}