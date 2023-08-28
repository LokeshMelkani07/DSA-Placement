#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
Find K Closest Elements
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // we will make a min_heap of pair<int,int> to store difference and element
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        // storing difference and element in heap
        pq.push({abs(x - arr[i]), arr[i]});
    }

    // It is a min_heap means smallest difference will be at the top
    vector<int> ans;
    int i = k;
    while (i--)
    {
        // get top k element and store in vector answer
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // sort the answer vector
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}