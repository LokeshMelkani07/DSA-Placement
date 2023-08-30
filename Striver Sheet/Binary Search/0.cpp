#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Nth Root of a Number using Binary Search

Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the ‘nth root is not an integer, return -1.
Example 1:
Input Format: N = 3, M = 27
Result: 3
Explanation: The cube root of 27 is equal to 3.

Example 2:
Input Format: N = 4, M = 69
Result: -1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

// We will use Binary search because let say
// n = 3, m = 27 then ans = 3
// 3*3*3 = 27 we know
// if we do 4*4*4 = 64
// 5*5*5 = 125
// So its a monotonically increasing search space which will not extend m
// so our search space becomes 1 to m
int NthRoot(int n, int m)
{
    // T.C:-O(logn) S.C:-O(1)
    int l = 1, h = m;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) > m)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}

int main()
{
    return 0;
}
