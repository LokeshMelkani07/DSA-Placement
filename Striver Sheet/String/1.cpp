#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Longest Palindromic Substring
Given a string str and length N
Return longest palindromic substring. if there are many, return any
A substring is a contiguous segment of a string.
Sample Input 1:

abccbc

Sample Output 1:

bccb

Explanation for input 1:

For string "abccbc",  there are several palindromic substrings such as "a", "b", "c", "cc", "bccb", and "cbc". However, the longest palindromic substring is "bccb".

Sample Input 2:
aeiou

Sample Output 2:
a
*/

string longestPalindrome(string s)
{
    // We will make use of even-odd approach
    // let say we start from a character and our palindrome is of odd length
    // then we take 2 pointer, start and end starting from index i
    // start will move backward and end will move forward till str[start]==str[end]
    // we store the length as this above loop ends and length = end-start+1
    // we store max_length this way
    // if palindrome length is even, we start start from i and end from i+1
    // we move the same way and all other things remains the same
    // at the end we return substring from start of length of max_length

    if (s.length() <= 1)
        return s;
    int max_len = 1; // max length of a palindrome initially will be 1
    int st = 0;
    int en = 0;
    int n = s.length();
    // odd case
    for (int i = 0; i < n - 1; i++)
    {
        // we start the loop < n-1 because j pointer is moving i+1 in even case
        int start = i;
        int end = i;
        while (start >= 0 && end < n)
        {
            if (s[start] == s[end])
            {
                start--;
                end++;
            }
            else
            {
                break;
            }
        }
        // here loop ends
        int len = end - start - 1;
        if (len > max_len)
        {
            max_len = len;
            // either start is at index -1 now so move one step forward
            st = start + 1;
            // or end is index = n so move one step back
            en = end - 1;
        }
    }

    // Even length
    for (int i = 0; i < n - 1; i++)
    {
        int start = i;
        int end = i + 1;
        while (start >= 0 && end < n)
        {
            if (s[start] == s[end])
            {
                start--;
                end++;
            }
            else
            {
                break;
            }
        }
        // here loop ends
        int len = end - start - 1;
        if (len > max_len)
        {
            max_len = len;
            // either start is at index -1 now so move one step forward
            st = start + 1;
            // or end is index = n so move one step back
            en = end - 1;
        }
    }

    return s.substr(st, max_len);
}

int main()
{
    return 0;
}