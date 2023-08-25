#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

/*
Sliding Window Maximum

Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Examples:

Example 1:

Input: arr = [4,0,-1,3,5,3,6,8], k = 3

Output: [4,3,5,5,6,8]

Explanation:

Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and add it to our output array.

Example 2:

Input: arr= [20,25], k = 2

Output: [25]

Explanation: There’s just one window is size 2 that is possible and the maximum of the two elements is our answer.
*/

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    // Brute force Approach
    // For every value of i, we check its window i tp i+k
    // We traverse that window and find out the maximum out of it
    // We store that maximum in answer vector
    // We will run the outer loop till i = 0 to i = n-k because we run inner loop from j = i to j < i+k
    // TC: O(n*k)
    vector<int> ans;
    int maxi;
    for (int i = 0; i <= n - k; i++)
    {
        maxi = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            maxi = max(maxi, arr[j]);
        }
        ans.push_back(maxi);
    }

    return ans;
}

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    // Optimised approach
    // We will make use of deque
    // In a deque, we can push_front, push_back, pop_front, pop_back
    // For a group of k elements, we always maintain a max element in the deque
    // if dq.front()  == i-k means dq.pop_front
    // if dq.front goes of out of bound that is range becomes more than k, we pop_front
    // We check if dq.back <= arr[i] we pop_back
    // then we push i in dq
    // Now at the end if i >= k-1, dq.front has index of max element in grp of k
    // TC: O(n), SC: O(k)
    // Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of our present window size. If so, we need to pop that out. Also, we need to check from the rear that the element present is smaller than the incoming element. If yes, there’s no point storing them and hence we pop them out. Finally, the element present at the front would be our largest element.
    deque<int> dq;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() == i - k)
        {
            // check for out of bound index
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            // Check if there exits smaller elements in the deque
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            // if window size criteria is fulfilled, extract the max element from the deque
            answer.push_back(arr[dq.front()]);
        }
    }

    return answer;
}

int main()
{
    return 0;
}