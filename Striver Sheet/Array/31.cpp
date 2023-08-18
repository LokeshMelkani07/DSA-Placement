#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/*
Length of Longest Substring without any Repeating Character

Problem Statement: Given a String, find the length of longest substring without any repeating character.

Example 1:

Input: s = ”abcabcbb”

Output: 3

Explanation: The answer is abc with length of 3.

Example 2:

Input: s = ”bbbbb”

Output: 1

Explanation: The answer is b with length of 1 units.
*/

int lengthOfLongestSubstring(string str)
{
    // We will use a count to store length of substring
    // we will use a set also to store characters of the string
    // we will use 2 pointers, l and r both initially at 0
    // we start from s[0] and check if s[0] is there in the set, if no then count = r-l+1 and move s[0] to set, do r++
    // now check s[r] in the set or not, if not then do count = r-l+1 and add it in the set, r++
    // now check again s[r] if its in the set means we need to remove l from the set and do l++ now count  = r-l+1
    // we keep on doing this till r<n
    // TC: O(2n) i.e O(n) for r pointer and o(n) for l pointer in worst case

    if (str.size() == 0)
        return 0;
    int count = INT_MIN;
    unordered_set<int> set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end()) // if duplicate element is found
        {
            while (l < r && set.find(str[r]) != set.end())
            {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        count = max(count, r - l + 1);
    }
    return count;
}

int lengthOfLongestSubstring(string s)
{
    // Optimised approach
    // In the previous approach we saw that in the worst case, l pointer was also travelling o(n) times
    // To reduce it, we can take a map in which we will have a vector which store frequency of all characters
    int n = s.length();
    int len = 0;
    // declare a frequency array with initial value of all characters as -1
    vector<int> mpp(256, -1);
    int l = 0, r = 0;
    while (r < n)
    {
        // if s[r] already present in frequency array then instead of moving left one by one, take left and put in next to right directly
        if (mpp[s[r]] != -1)
        {
            l = max(mpp[s[r]] + 1, l);
        }

        // update s[r] with value which was its latest position
        mpp[s[r]] = r;
        // get the max length
        len = max(len, r - l + 1);
        // move right pointer
        r++;
    }

    return len;
}

int main()
{

    return 0;
}