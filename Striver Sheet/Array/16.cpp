#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Subarrays with sum K
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

Example 1:

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination:
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.


Example 2:

Input:
N = 6
Arr = {9, 4, 20, 3, 10, 5}
k = 33
Output: 2
Explaination:
Subarrays : arr[0...2], arr[2...4] have sum
exactly equal to 33.
*/

int findSubArraySum(int Arr[], int N, int sum)
{
    // Optimised Approach
    // Take an map and store the sum and count of it in map
    // Initialise Count by 0, count stores number of subArrays of that type found
    int count = 0;
    // Make an map to store current_Sum and count of number of times that sum appears
    unordered_map<int, int> mpp;
    int currSum = 0;
    for (int i = 0; i < N; i++)
    {
        // Store the sum in the current sum
        // Means maintain a Prefix sum array but its not a array we take the sum after adding each element
        currSum += Arr[i];

        // if current_sum is equal to required_sum then we have found that one subarray
        // so do count++;
        if (currSum == sum)
        {
            count++;
        }

        // if current_sum > sum then check whether current_sum - required_sum exists in the map or not
        // because let say our current_sum = 14 , required  = 7 , then 14-7 if its exited in map ealrier
        // means there must have been an subarray with required sum of 7
        if (mpp.find(currSum - sum) != mpp.end())
        {
            // if it exists add its frequency in the count
            count += mpp[currSum - sum];
        }
        // if it does not exists add current_sum in the map with its frequency
        mpp[currSum]++;
    }
    return count;
}

int main()
{
    return 0;
}