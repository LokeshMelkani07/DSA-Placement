#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”

Output: 2 7 13

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


Sample Input 3 :

abcd
xy


Sample Output 3 :

0


Expected time complexity:

The expected time complexity is O(‘n’ + ‘m’)
*/

vector<int> stringMatch(string txt, string pat)
{
    // Video Ref: https://youtu.be/qQ8vS2btsxI?si=QxXspGNFmUD7FO5Z
    // Code: https://www.youtube.com/watch?v=S-LXeuHGF98&ab_channel=KnowledgeCenter
    // We will take a Hash function which will store int value related to each character from a to z
    // say a->1, b->2, c->3, d->4.............z->26
    // We take each character from pattern string and add the sum say pat
    // Now we go to string text and take a window of pattern.size()
    // we calculate sum for that window and check if its equal to pat
    // if not we remove front character from window, decrease its value from sum and take next charcater inside window and take its value in sum
    // Again we compare
    // If comparison come successful, we check each character of window with pattern, character by character
    // and return index
    // But this algo has a drawback that we can get same sum for different values as our hash function is very week
    // So our TC can go to O(nm) whereas this should be O(n-m+1) and this problem is called spurious hit
    // So we optimise it and make a string hash function which is suggested by rabin karp
    // What we do it we multiply each character code with * 10 ^ m-n where m is size of pattern
    // say we have a b a then code become 1*10^3-1, 2*10^3-2, 1*10^3-3
    // we have taken 10 as base, but base could be anything depending on number of character our hash function stores
    // if we define our hash function for a-z then base can be 26
    // if we define it for a-z and A-Z also then base = 127
    // But the value can exceed the data type limit so we do sum%n to make it smaller in the hash function
    // Rest the working remains same
    vector<int> res;

    int d = 256; // No of characters in input
    int q = 101; // Prime number to do mod operation
    int M = pat.length();
    int N = txt.length();

    if (M > N)
    {
        return res;
    }

    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text and pattern
        // If the hash values match, then only check for characters one by one
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // If p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
            {
                res.push_back(i + 1);
            }
        }

        // Calculate hash value for the next window of text
        // Remove leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative values of t, converting it to positive
            if (t < 0)
            {
                t = t + q;
            }
        }
    }

    return res;
}

int main()
{
    return 0;
}