#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Count the number of subarrays having a given XOR
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples:

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of
              their elements as 6 are {4, 2},
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}


*/

// approach
// we can say if Y^k = X then we can also write it as Y = X^K
// we will use a map to store XOR and its count
// we use concept of prefix_XOR and if prefix_XOR is == k we do count++
// if its not equal to K then we check if prefix_XOR^K is there in the map
// if found we add its count in the answer
// if not found, we just add prefix_XOR in the map

int solve(vector<int> &A, int B)
{
    // making a map to store XOR and count
    unordered_map<int, int> mpp;
    int count = 0;
    int pre_XOR = 0;
    for (int i = 0; i < A.size(); i++)
    {
        // calculating pre_XOR
        pre_XOR ^= A[i];
        // if pre_XOR is found
        if (pre_XOR == B)
        {
            count++;
        }
        // if Y is found in the map, add into count
        if (mpp.find(pre_XOR ^ B) != mpp.end())
        {
            count += mpp[pre_XOR ^ B];
        }
        // at last add pre_XOR in the map
        mpp[pre_XOR]++;
    }
    // return the count
    return count;
}

int main()
{
    return 0;
}