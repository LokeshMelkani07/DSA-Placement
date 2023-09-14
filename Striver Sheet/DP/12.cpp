#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

bool solve(string s, int index, set<string> &st)
{
    if (index == s.size())
        return true;

    // make an temp string
    string temp = "";

    for (int j = index; j < s.size(); j++)
    {
        // store character by character inside the string temp and check if it matches the dict
        temp += s[j];
        if (st.find(temp) != st.end())
        {
            // check for next index of j
            if (solve(s, j + 1, st))
            {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // What we do is we will pick one character and try to match it in the      dictionary
    // starting from index = 0, we run a loop j = i to  j < s.size()
    // we will store dict in set so that its easy to compare
    // gives TLE
    set<string> st;
    for (auto it : wordDict)
    {
        st.insert(it);
    }

    return solve(s, 0, st);
}

// Memo code

bool solve(string s, int index, set<string> &st, vector<int> &dp)
{
    if (index == s.size())
        return true;

    if (dp[index] != -1)
        return dp[index];

    // make an temp string
    string temp = "";

    for (int j = index; j < s.size(); j++)
    {
        // store character by character inside the string temp and check if it matches the dict
        temp += s[j];
        if (st.find(temp) != st.end())
        {
            // check for next index of j
            if (solve(s, j + 1, st, dp))
            {
                return dp[index] = true;
            }
        }
    }
    return dp[index] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // What we do is we will pick one character and try to match it in the      dictionary
    // starting from index = 0, we run a loop j = i to  j < s.size()
    // we will store dict in set so that its easy to compare
    // gives TLE
    // let us make an DP array, we have only one changing variable i.e index so we make 1D DP array
    // Instead of calculating for index i again and again we pass DP array and store result in it.

    set<string> st;
    vector<int> dp(s.size(), -1);
    for (auto it : wordDict)
    {
        st.insert(it);
    }

    return solve(s, 0, st, dp);
}

int main()
{
    return 0;
}