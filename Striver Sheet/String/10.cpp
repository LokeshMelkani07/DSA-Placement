#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Longest Common Prefix
you-are-given-an-array-arr-of-n-strings
Find the longest common prefix in all these strings.
If there is no common prefix in all the strings return "-1".
Example:
Input: 'arr' = [“abcd”, “abc”, “abref”, “abcde”]

Output: ab

Explanation:
Answer is “ab”, as it is the longest prefix present in all the given strings.
Sample Input 1:

4
Codingninjas
Coding
Coders
Codezen


Sample Output 1:

Cod


Explanation of sample output 1:

In the given testcase, the longest prefix that is present in all the strings is “Cod”. Hence the answer is “Cod”.


Sample Input 2:

3
abcd
Abcd
abc

Sample Output 2:

-1

Explanation of sample output 2:

In the given testcase, there is no prefix that is present in all the strings. Hence the answer is “-1”
*/

string commonPrefix(vector<string> &arr, int n)
{
    // We will take the length of smallest string among all
    // we will store that string also say smallest
    // Now we start traversing each character of that smallest and compare it with all other string we have
    // We will store a count variable also
    // If at any time any character of any string does not match with that character of smallest string
    // we return substring from index = 0, of the length = count
    // else we do count++ till characters are matching
    int count = 0;
    int mini = 1000;
    string smallest;

    for (int i = 0; i < arr.size(); i++)
    {
        int len = arr[i].length();
        if (len < mini)
        {
            // we get the minimum string ki length
            mini = len;
            // we get the minimum string
            smallest = arr[i];
        }
    }

    // Now we have the smallest string
    // Let us compare it
    for (int i = 0; i < smallest.length(); i++)
    {
        // This i-loop will compare all characters of smallest string
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j][0] != smallest[0])
            {
                // Edge case
                // If first character of all string do not match, return -1
                return "-1";
            }

            // This j-loop will go through each string present inside our vector
            // and will check the ith character of that each string with the ith character of smallest string
            if (arr[j][i] != smallest[i])
            {
                // if characters do not match, return that sub string
                return smallest.substr(0, count);
            }
        }
        // if that character matched, count++ and move i to next character
        count++;
    }

    return smallest.substr(0, count);
}

int main()
{
    return 0;
}