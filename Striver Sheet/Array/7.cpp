#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Merge Overlapping Sub-intervals

Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
*/

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    // Brute force
    // Sort all values
    // In a matrix, sorting is based on first element and if first element is same, then it is done on basis of second element
    // By sorting, we get all close elements together
    // Let us take (l1,r1) as our first interval and check if next element (l2,r2) is overlapping or not
    // How to check overlapping?
    // if r1>l2 then yes its overlapping so we can club l1,r1 and l2,r2 into [l1,r2]
    // we move to next element and check whether last element of that pair is <= r2
    // if yes, then move forward, do nothing and do this till end of matrix
    // if no, then put the prev overlapped ans in vector and take next interval as l1,r1 and do the same

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        // check if current interval already there in ans or not
        // and ans should already contain some interval
        // ans.back gives us latest interval of answer
        // ans.back()[1] gives us R1 from [l1,R1] interval
        if (!ans.empty() && ans.back()[1] >= end)
        {
            // if ans contain that interval, do nothing
            continue;
        }
        // if it does not contain, update the end of that interval
        for (int j = i + 1; j < arr.size(); j++)
        {
            // if end contains l1 of [l1,r1] interval means we can accumulate it
            if (arr[j][0] <= end)
            {
                // update end
                end = max(end, arr[j][1]);
            }
            else
            {
                // else break it we have got first overlapped intervals
                break;
            }
        }
        // store them in the ans
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> &arr)
{
    // Optimised approach
    // We will store the first interval we get into and try to compute things in one loop
    // if ans.empty() or prev interval ka R1 is < arr[i][0] then we make a new interval arr[i] and store in ans
    // if interval contains arr[i][0] inside [l1,r1] means we can merge it with us so we need to update the end
    // this way in one iteration we merge all overlapping intervals

    int n = arr.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < arr[i][0])
        {
            // create a new interval in ans
            ans.push_back(arr[i]);
        }
        else
        {
            // update the arr.back()[1] in the answer
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}