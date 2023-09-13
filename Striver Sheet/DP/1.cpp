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
Longest Common Subsequence
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example:
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Sample Input 1 :

adebc
dcadb

Sample Output 1 :

3

Explanation of the Sample Output 1 :

Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3.

Sample Input 2 :

ab
defg

Sample Output 2 :

0

Explanation of the Sample Output 2 :

The only subsequence that is common to both the given strings is an empty string("") of length 0.
*/

int solve(string s, string t, int i, int j)
{
    // base case
    if (i == s.length())
    {
        return 0;
    }
    if (j == t.length())
    {
        return 0;
    }
    // store ans
    int ans = 0;
    // if characters match move both pointer
    if (s[i] == t[j])
    {
        ans = 1 + solve(s, t, i + 1, j + 1);
    }
    else
    {
        // both do not match
        // ek baar i ko aage badhao, j ko rehene do
        // ek baar j ko aage badhao, i ko rehene do
        // get the maximum as result
        ans = max(solve(s, t, i + 1, j), solve(s, t, i, j + 1));
    }
    return ans;
}

int lcs(string s, string t)
{
    return solve(s, t, 0, 0);
}

// Memoization(Top - down approach)

int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == s.length())
    {
        return 0;
    }
    if (j == t.length())
    {
        return 0;
    }
    // if ans is already there in dp, do not make calls just return the ans
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // store ans
    int ans = 0;
    // if characters match move both pointer
    if (s[i] == t[j])
    {
        ans = 1 + solve(s, t, i + 1, j + 1, dp);
    }
    else
    {
        // both do not match
        // ek baar i ko aage badhao, j ko rehene do
        // ek baar j ko aage badhao, i ko rehene do
        // get the maximum as result
        ans = max(solve(s, t, i + 1, j, dp), solve(s, t, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}

int lcs(string s, string t)
{
    // Memoization
    // we see i and j are changing so we need 2D dp
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solve(s, t, 0, 0, dp);
}

// Bottom - up DP(Tabulation)

int solveTab(string s, string t, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s[i] == t[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int lcs(string s, string t)
{
    // using tabulation
    int n = s.length();
    int m = t.length();
    return solveTab(s, t, n, m);
}

int main()
{
    return 0;
}