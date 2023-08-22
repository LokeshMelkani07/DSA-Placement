#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Minimum number of platforms required for a railway

Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

Examples 1:

Input: N=6,
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

Output:3

Explanation: There are at-most three trains at a time. The train at 11:00 arrived but the trains which had arrived at 9:45 and 9:55 have still not departed. So, we need at least three platforms here.

Example 2:

Input Format: N=2,
arr[]={10:20,12:00}
dep[]={10:50,12:30}

Output: 1

Explanation: Before the arrival of the new train, the earlier train already departed. So, we don’t require multiple platforms.

Note:
1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.

2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".

3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
*/

int calculateMinPatforms(int arr[], int dep[], int n)
{
    // We have arrival times in arr
    // We have departure time in dep
    // Any platform can be used only by one train at time
    // So First we will sort arr,dep
    // It will distort the arr,dep time of each train but we are not intereseted in any particular train
    // We need overall timings to check if at any given time platform will be empty or not
    // if train A comes at 4pm and leaves at 5pm and train B comes at 6pm leaves at 8pm
    // we can allot same platform to both A and B but not the case if A leaves at 7pm
    // We will traverse arr and dep array one by one
    // TC: O(2nlogn) + O(2n) to sort both array and traverse both of them
    // SC: O(1)
    sort(arr, arr + n);
    sort(dep, dep + n);

    // We will allocate atleast one platform to first train
    int platform = 1;
    // initially max is 1
    int max_platform = 1;

    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++; // move to next train then
        }
        else
        {
            platform--;
            j++; // move to dep time of that latest train then
        }
        max_platform = max(platform, max_platform);
    }

    return max_platform;
}

int main()
{
    return 0;
}