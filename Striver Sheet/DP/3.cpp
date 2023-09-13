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
Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character



Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

int distance(string s1, string s2, int i, int j)
{
    // base case
    if (i == s1.length())
    {
        // means s1 is smaller than s2
        // so return remaining elements of s2 as these many operations will be needed to match s1 and s2 so return
        return s2.length() - j;
    }

    if (j == s2.length())
    {
        // means s2 smaller than s1
        // return remaining element of s1
        return s1.length() - i;
    }

    int ans = 0;

    // if both characters are equal, no operation needed just move to comparing next indexes
    if (s1[i] == s2[j])
    {
        return distance(s1, s2, i + 1, j + 1);
    }
    else
    {
        // both not equal, we need to perform insert,delete,replace
        // insert
        // i remain as it is, j move by 1
        int insertAns = 1 + distance(s1, s2, i, j + 1);

        // delete
        // j remains as it is, i move by 1
        int deleteAns = 1 + distance(s1, s2, i + 1, j);

        // replace
        // j and i both move
        int replaceAns = 1 + distance(s1, s2, i + 1, j + 1);

        // store minimum of all in ans
        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return ans;
}

int minDistance(string word1, string word2)
{
    return distance(word1, word2, 0, 0);
}

// Memoised code
int distance(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == s1.length())
    {
        // means s1 is smaller than s2
        // so return remaining elements of s2 as these many operations will be needed to match s1 and s2 so return
        return s2.length() - j;
    }

    if (j == s2.length())
    {
        // means s2 smaller than s1
        // return remaining element of s1
        return s1.length() - i;
    }

    // check dp
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;

    // if both characters are equal, no operation needed just move to comparing next indexes
    if (s1[i] == s2[j])
    {
        return distance(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        // both not equal, we need to perform insert,delete,replace
        // insert
        // i remain as it is, j move by 1
        int insertAns = 1 + distance(s1, s2, i, j + 1, dp);

        // delete
        // j remains as it is, i move by 1
        int deleteAns = 1 + distance(s1, s2, i + 1, j, dp);

        // replace
        // j and i both move
        int replaceAns = 1 + distance(s1, s2, i + 1, j + 1, dp);

        // store minimum of all in ans
        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return dp[i][j] = ans;
}

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    return distance(word1, word2, 0, 0, dp);
}

// Tabulation
int solveTabulation(string a, string b)
{
    // make dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    // convert the base cases
    for (int j = 0; j < b.length(); j++)
    {
        // in a.length vali row fill
        dp[a.length()][j] = b.length() - j;
    }

    for (int i = 0; i < a.length(); i++)
    {
        // in b.length vali row fill
        dp[i][b.length()] = a.length() - i;
    }

    // now for other cases
    // we go from bottom to up
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;

            // if both characters are equal, no operation needed just move to comparing next indexes
            if (a[i] == b[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                // both not equal, we need to perform insert,delete,replace
                // insert
                // i remain as it is, j move by 1
                int insertAns = 1 + dp[i][j + 1];

                // delete
                // j remains as it is, i move by 1
                int deleteAns = 1 + dp[i + 1][j];

                // replace
                // j and i both move
                int replaceAns = 1 + dp[i + 1][j + 1];

                // store minimum of all in ans
                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int editDistance(string word1, string word2)
{
    return solveTabulation(word1, word2);
}

int main()
{
    return 0;
}