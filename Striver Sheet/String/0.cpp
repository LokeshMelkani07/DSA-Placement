#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Reverse Words in a String

Problem Statement: Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”
*/

string reverseString(string &str)
{
    // We can traverse whole string
    // We make use fo 2 pointer to cover each word
    int i = 0;
    int n = str.length();
    string result;
    while (i < n)
    {
        // move i till we encounter first word
        while (i < n && str[i] == ' ')
            i++;
        if (i >= n)
            break;
        // i will stand at the beginning of a word and j will move to cover the end of word
        int j = i + 1;
        while (j < n && str[j] != ' ')
            j++;
        // when j reaches the end of word we cut that sub string and a dd in the answer string
        string sub = str.substr(i, j - i);
        // if answer string is empty means its first word
        if (result.length() == 0)
            result = sub;
        else
        {
            // else its not first word so
            result = sub + " " + result;
        }
        // move to next word
        i = j + 1;
    }

    return result;
}

int main()
{
    return 0;
}
