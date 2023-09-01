#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Pattern Searching Using Z Algorithm
you are given two strings s of size n which is the text string and pattern of size m which is the pattern string
Your task is to return all the indices in sorted order (in 1-based indexing) of string ‘s’ such that starting from that index, the substring in ‘s’ of length ‘m’ is equal to ‘pattern’.
Example:
Input: ‘n’ = 8, ‘m’ = 3
‘s’ = “abdchabd”, ‘pattern’ = “abd”

Output: 1 6

Explanation: The indices where the string ‘s’ substring of length ‘3’ matches with string ‘pattern’ are 1 and 6.
 <br/>
Sample Input 1:

8 3
abdchabd
abd


Sample Output 1 :

1 6


Explanation Of Sample Input 1:

Input: ‘n’ = 8, ‘m’ = 3
‘s’ = “abdchabd”, ‘pattern’ = “abd”

Output: 1 6

Explanation: The indices where the string ‘s’ substring of length ‘3’ matches with string ‘pattern’ are 1 and 6.

Sample Input 2:

6 2
aaaaaa
aa


Sample Output 2:

1 2 3 4 5


Explanation Of Sample Input 2:

Input: ‘n’ = 6, ‘m’ = 2
‘s’ = “aaaaaa”, ‘pattern’ = “aa”

Output: 1 2 3 4 5

Explanation: The indices where the string ‘s’ substring of length ‘2’ matches with string ‘pattern’ are 1, 2, 3, 4, and 5.
*/

vector<int> search(string s, string pattern)
{
    // Brute force approach
    // We can take length of pattern string say pat
    // We take substring of pat length from string s, at a time
    // we compare it with pattern and store index in answer vector
    // The index should start from 1 so we store index +1
    // we run the loop from i = 0 to i < s.length - pat.length + 1
    // because we need substring of pat.length everytime so we run loop till this length
    vector<int> ans;
    int sLength = s.length();
    int patLength = pattern.length();

    for (int i = 0; i < sLength - patLength + 1; i++)
    {
        if (pattern == s.substr(i, patLength))
        {
            ans.push_back(i + 1);
        }
    }

    return ans;
}

vector<int> search(string s, string pattern)
{
    // Video Reference: https://www.youtube.com/watch?v=cx4MEJZu9kk&ab_channel=Let%27sPracticeTogether
    // Linear time pattern searching using Z-algorithm
    // We will take a Z-vector
    // We will take a new string which will store (pattern + '$' + s)
    // We store pattern to be searched + $ or any other sign to seperate 2 strings + text string jisme se hume pattern match karwana hai
    // We will store Z-vector as 0 till $
    // Now we search in rest of new string from first index of s and try to match the pattern
    // if pattern matches we store Z[index] = length of matched string in pat
    // else we store 0 in Z-vector
    // At the end we check in Z-vector from starting of s string, if out index matches pattern.length store that answer in the ans vector
    vector<int> ans;
    int len1 = s.length();
    int len2 = pattern.length();
    string new_string = pattern + '$' + s;
    int n = new_string.length();
    vector<int> Z;
    int i = 0;
    while (i < n)
    {
        if (i <= len2)
        {
            // fill 0's for pattern in Z-vector
            Z.push_back(0);
        }
        else
        {
            int left = 0;
            int right = 0;
            if (new_string[left] == new_string[i])
            {
                right = i;
                while (new_string[left] == new_string[right] && right < n)
                {
                    left++;
                    right++;
                }
            }
            Z.push_back(left);
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (Z[i] == len2)
            ans.push_back(i - len2);
    }

    return ans;
}

int main()
{
    return 0;
}