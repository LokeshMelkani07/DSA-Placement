#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
Sort Array by Increasing Frequency
Easy

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.



Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
*/

// Using hashing
bool static comparator(pair<int, int> m, pair<int, int> n)
{
    if (m.second == n.second)     // if frequency same
        return m.first > n.first; // return whose element is bigger
    else
        return m.second < n.second; // return whose frequency is bigger
}
vector<int> frequencySort(vector<int> &nums)
{
    // We can store the frequency in a map
    // We can use min_heap to get minimum frequency element at the top
    // We push element, freq number of times in the ans vector
    // We use pair<int,int> to store frequency and element
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    // Now we get one element at a time from top of heap
    // and store frequency times in the array
    vector<pair<int, int>> v1;
    for (auto k : mpp)
    {
        v1.push_back(k);
    }

    // We will make a vector of pair and store all frequency and elements in that vector
    // now, we sort that vector on basis of comparator which says if two numbers have same frequency then put the bigger one first then smaller one
    // say 3->2, 2->2 then in final array, 3 comes first then 2 comes
    sort(v1.begin(), v1.end(), comparator);

    vector<int> ans;
    // store all elements in ans vector
    for (auto y : v1)
    {
        // till frequency becomes 0, store the element
        while (y.second--)
        {
            ans.push_back(y.first);
        }
    }

    return ans;
}

// Using heap
vector<int> frequencySort(vector<int> &nums)
{
    // We can store the frequency in a map
    // We can use min_heap to get minimum frequency element at the top
    // We push element, freq number of times in the ans vector
    // We use pair<int,int> to store frequency and element
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it : mpp)
    {
        pq.push({it.second, it.first});
    }

    // Now we get one element at a time from top of heap
    // and store frequency times in the array
    vector<int> ans;

    while (!pq.empty())
    {
        int k = pq.top().first;
        while (k--)
        {
            ans.push_back(pq.top().second);
        }
        pq.pop();
    }
    return ans;
}

int main()
{
    return 0;
}