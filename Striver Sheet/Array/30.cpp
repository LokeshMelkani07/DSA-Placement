#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    // Optimised force
    // we can store the sum in the mapfor each index
    // we use kadane's algo to get subarrays
    // If at any point we get sum = 0 means length of subarray = i+1 (0-based indexing)
    // otherwise we check whether that sum value exist in the map or not and if found, length = i - map[sum]
    // because let say we have sum of index 1 to 4 = S, we see index 1 to 2 has sum = S then we can definately say index 3 to 4 will have sum = 0
    // so that total 1 to 4 has sum = S
    // so if sum != 0 we check if that sum exist in map, if found we get length of subarray as i - map[sum]
    // else, we add that sum into map with its index till which that sum comes, map[sum] = i
    // each time we compare longest length and return it in the end
    int n = arr.size();
    int longest = 0;
    unordered_map<int, int> mpp;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            longest = i + 1;
        }
        else if (mpp.find(sum) != mpp.end())
        {
            longest = max(longest, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return longest;
}

int main()
{

    return 0;
}
