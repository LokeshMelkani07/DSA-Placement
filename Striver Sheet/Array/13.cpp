#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

*/

int firstUniqChar(string s)
{
    // we will make a map in which we will store the element and the count of the element in the array
    // if count is 1 then we return that index else return -1
    // TC: O(n), SC: O(n)
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (mpp[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    return 0;
}