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
Palindrome Partitioning 2
You are given a string 'str' of length 'n'
Find the minimum number of partitions in the string so that no partition is empty and every partitioned substring is a palindrome.

Example:
Input: 'str' = "aaccb"

Output: 2

Explanation: We can make a valid partition like aa | cc | b.

Sample Input 1 :

aaccb


Sample Output 1 :

2


Explanation of sample input 1 :

We can make a valid partition like aa | cc | b.


Sample Input 2 :

ababa


Sample Output 2 :

0


Explanation of sample input 2 :

The string is already a palindrome, so we need not make any partition.


Sample Input 3:

aababa


Sample Output 3:

1
*/

// Recursion Code

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int index, int n)
{
    if (index == n)
    {
        return 0;
    }
    int Min_cost = INT_MAX;
    for (int j = index; j < n; j++)
    {
        if (isPalindrome(index, j, str))
        {
            int cost = 1 + solve(str, j + 1, n);
            Min_cost = min(Min_cost, cost);
        }
    }
    return Min_cost;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    // we need to do -1 in the answer because our code run till i == n means it puts a partition after last index also
    //  which is not needed so we do -1 below
    return solve(str, 0, n) - 1;
}

// Memo Code

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int index, int n, vector<int> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int Min_cost = INT_MAX;
    for (int j = index; j < n; j++)
    {
        if (isPalindrome(index, j, str))
        {
            int cost = 1 + solve(str, j + 1, n, dp);
            Min_cost = min(Min_cost, cost);
        }
    }
    return dp[index] = Min_cost;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    // we need to do -1 in the answer because our code run till i == n means it puts a partition after last index also
    //  which is not needed so we do -1 below
    vector<int> dp(n, -1);
    return solve(str, 0, n, dp) - 1;
}

// Tabulation Code

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    // Tabulation code
    int n = str.size();
    // we need to do -1 in the answer because our code run till i == n means it puts a partition after last index also
    //  which is not needed so we do -1 below
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int Min_cost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                Min_cost = min(Min_cost, cost);
            }
        }
        dp[i] = Min_cost;
    }
    return dp[0] - 1;
}

int main()
{
    return 0;
}