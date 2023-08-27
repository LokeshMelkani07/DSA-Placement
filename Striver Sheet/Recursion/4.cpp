#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Palindrome Partitioning

Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

Note: A palindrome string is a string that reads the same backward as forward.

Examples:

Example 1:

Input: s = “aab”

Output: [ ["a","a","b"], ["aa","b"] ]


Example 2:

Input: s = “aabb”

Output: [ [“a”,”a”,”b”,”b”], [“aa”,”bb”], [“a”,”a”,”bb”], [“aa”,”b”,”b”] ]
*/

bool isPalindrome(string s, int start, int end)
{
    // Checking if its palindrome
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void solve(int index, string s, vector<vector<string>> &ans, vector<string> &ds)
{
    // Base case
    if (index == s.size())
    {
        ans.push_back(ds);
        return;
    }

    // Looping for all the index
    for (int i = index; i < s.size(); i++)
    {
        // before putting anything in answer, we check first whether its a palindrome or not
        if (isPalindrome(s, index, i))
        {
            // index is always greater than i so we check palindrome for index->i and store substring from index->index-i+1
            ds.push_back(s.substr(index, i - index + 1));
            // we call recursion for next value of index
            solve(i + 1, s, ans, ds);
            // On moving backtrack, we remove the element added
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    /*
    Time Complexity: O( (2^n) *k*(n/2) )
    Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.
    Space Complexity: O(k * x)
    Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
    */
    vector<vector<string>> ans;
    vector<string> ds;
    solve(0, s, ans, ds);
    return ans;
}

int main()
{
    return 0;
}