#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Compare Version Numbers
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

    If version1 < version2, return -1.
    If version1 > version2, return 1.
    Otherwise, return 0.

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".

Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
*/

int compareVersion(string version1, string version2)
{
    // Each version number contains 2.45.64.23.67
    // and 2,45,64,23,67 are revisions
    // Each revision is separated by a '.'
    // Ignore any leading zeroes in any revision means 001 = 1 or 00004 = 4 only
    // if there is no digit, consider it as 0
    // we need to start comparing from left -> right
    // if v1>v2 return 1, v2>v1 return -1 else return 0
    // we will take the number before . everytime from both strings and compare then
    int v1length = version1.length();
    int v2length = version2.length();
    if (v1length == 0)
    {
        return -1;
    }
    else if (v2length == 0)
    {
        return 1;
    }

    int i = 0;
    int j = 0;
    while (i < v1length || j < v2length)
    {
        // we are taking n1 and n2 as 0 initially so that is anyone of the string has exhausted then we can consider it as 0
        int n1 = 0, n2 = 0;
        while (i < v1length && version1[i] != '.')
        {
            n1 = n1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < v2length && version2[j] != '.')
        {
            n2 = n2 * 10 + (version2[j] - '0');
            j++;
        }

        if (n1 > n2)
            return 1;
        else if (n2 > n1)
            return -1;

        i++;
        j++;
    }

    return 0;
}

int main()
{
    return 0;
}
