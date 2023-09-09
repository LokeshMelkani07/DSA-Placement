#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

/*
Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

int kthLargest(vector<int> &arr, int size, int K)
{
    // we need kth largest element so we use min_heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // we know min heap always stores the minimum element at the top
    // we push all array element in min heap and if size>k we pop
    // this way we always maintain, kth largest or (n-k)th smallest element at the top
    // at the end we return pq.top();
    // TC: O(n). SC: O(k)
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > K)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{
    return 0;
}