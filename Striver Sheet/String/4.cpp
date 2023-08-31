#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
*/

bool isAnagram(string str1, string str2)
{
    // Store both strings in a map and check if both maps are equal or not
    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2)
    {
        return false;
    }
    unordered_map<char, int> mpp1;
    unordered_map<char, int> mpp2;

    for (int i = 0; i < n1; i++)
    {
        mpp1[str1[i]]++;
        mpp2[str2[i]]++;
    }

    return mpp1 == mpp2 ? true : false;
}

bool isAnagram(string s, string t)
{
    /*
    sort(s.begin(), s.end()); sorts the characters in string s in ascending order.         This rearranges the characters in s so that they are in alphabetical order.
    sort(t.begin(), t.end()); sorts the characters in string t in ascending order.         Similarly, this rearranges the characters in t to be in alphabetical order.
    return s == t; compares the sorted strings s and t using the equality operator          (==). If the sorted strings are equal, it means that the original strings s            and t have the same characters in the same order, indicating that they are              anagrams. In this case, the function returns true. Otherwise, if the sorted            strings are not equal, the function returns false, indicating that the                  strings are not anagrams.

    This code takes advantage of the fact that anagrams have the same characters,           but in different orders. By sorting the characters, the code transforms the             problem into a comparison of the sorted strings, simplifying the anagram check.
    */
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main()
{
    return 0;
}