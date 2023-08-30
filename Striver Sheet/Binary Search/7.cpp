#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Aggressive Cows : Detailed Solution

Problem Statement: You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
Example 1:
Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result: 3
Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
Result: 5
Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}.

*/

bool isPossible(int mid, vector<int> &stalls, int k)
{
    int cowCount = 1;                  // let say we start by placing the first cow
    int lastPositionOfCow = stalls[0]; // we place first cow at 0th index

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPositionOfCow >= mid)
        {
            // one cow has been alloted successfully
            cowCount++;
            // if all cows alloted successfully return true
            if (cowCount == k)
            {
                return true;
            }
            // update the last position of cow
            lastPositionOfCow = stalls[i];
        }
    }

    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    // We can think of doing binary search
    // As we have been aksed to get largest minimum distance
    // We can think of search space where we place the first cow at index = 0 and last cow at index (maxi element/stall)
    // we first sort the array so that we can run this approach
    // we find the mid and check if mid can be our possible solution
    // if yes, we store that mid and do start = mid+1 because we need max distance so if mid is possible ans then to reach max answer we need to go to mid+1
    // if no, means we need to reduce our search space so do end = mid-1
    // To check if mid is possible answer we check if arr[i] - lastPositionOfCow >= mid
    // then we can easily assign the cow
    // each time check if k number of cows can be alloted this way successfully or not

    // we need to first sort the array
    sort(stalls.begin(), stalls.end());

    int start = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }

    int end = maxi;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(mid, stalls, k))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}