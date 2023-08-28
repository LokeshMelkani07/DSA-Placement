#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // Using hashing
    unordered_map<int, int> m;
    for (auto it : nums)
    {
        m[it]++;
    }
    vector<pair<int, int>> v;
    for (auto it : m)
    {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(v[i].second);
    }

    return ans;
}

// Using Heap

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    // Making a max heap to store frequency and element
    priority_queue<pair<int, int>> maxH;
    for (auto it : mpp)
    {
        maxH.push({it.second, it.first});
    }

    int i = k;
    vector<int> ans;
    while (i--)
    {
        ans.push_back(maxH.top().second);
        maxH.pop();
    }

    return ans;
}

int main()
{
    return 0;
}