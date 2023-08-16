#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Count pairs with given sum
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, K = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation:
Each 1 will produce sum 2 with any 1.
*/

int getPairsCount(int arr[], int n, int k)
{
    // for each element we store it in the map but before that we check if k - arr[i] is present in map or not
    // if it is present then add it in the count
    // if not present then just add that arr[i] in the map
    int count = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int target = k - arr[i];
        count += mpp[target];
        mpp[arr[i]]++;
    }
    return count;
}

int main()
{
    return 0;
}