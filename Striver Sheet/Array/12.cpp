#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Max distance between same elements
Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5

Example 2:

Input
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}

Output
10

Explanation



arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5


*/

int maxDistance(int arr[], int n)
{
    // we will use map to store element and index
    // if element not present in the map, store it and if present then check and update
    // we will have an maxi by which we will compare everytime the distance of prev index of same element - current index
    int maxi = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        if (mpp.find(arr[i]) == mpp.end())
        {
            mpp[arr[i]] = i;
        }
        else
        {
            maxi = max(maxi, i - mpp[arr[i]]);
        }
    }

    return maxi;
}

int main()
{
    return 0;
}