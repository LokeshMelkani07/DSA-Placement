#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Search Pattern (KMP    Algorithm)
you  are  given  two  strings  text  of  length  n  and  pattern  of  length  m  consisting  of  lowercase  characters
Find all the occurrences of the string ‘pattern’ in ‘text’.
For each occurrence, print the index from where it starts in the string ‘text’ (1    indexed).
Example:
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”

Output: Occurrences = [2, 7, 13]

Explanation: The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.
Sample Input 1:

cxyzghxyzvjkxyz
xyz


Sample Output 1:

3
2 7 13


Explanation Of Sample Input 1 :

The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.


Sample Input 2 :

ababacabab
aba


Sample Output 2 :

3
1 3 7


Explanation Of Sample Input 2 :

Here we have an overlap between the first occurrence (at position 1) and the second occurrence (at position 3), and we are considering both.
*/

vector<int> stringMatch(string text, string pattern)
{

    // Dry run of this algo: https://youtu.be/V5-7GzOfADQ?si=vU-TxHgm_ENiXAxn
    int n = text.length(), m = pattern.length();
    vector<int> ans, LPS(m, 0);
    int len = 0;
    for (int i = 1; i < m; i++)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            LPS[i] = len;
        }
        else
        {
            if (len != 0)
            {
                len = LPS[len - 1];
            }
        }
    }

    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                ans.push_back(i - j + 1);
                j = LPS[j - 1];
            }
        }
        else
        {
            if (j > 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}