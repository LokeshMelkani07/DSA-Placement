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
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note:
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’.

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).

Sample Input 1 :
2
sds
abc

Sample Output 1 :
6
7

Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.

Sample Input 2 :
2
aa
abab

Sample Output 2 :
3
8

Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }
*/

struct Node
{

    Node *arr[26];

    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }

    bool containsKey(char ch)
    {
        return arr[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    // take a counter
    // we are not making Trie class here because we only need insert function which can be made here also
    int count = 0;
    // start fron root
    Node *root = new Node;
    for (int i = 0; i < s.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                // if its does not contains, insert and increase count
                count++;
                node->put(s[j], new Node());
            }
            // get me to the ref node now
            node = node->get(s[j]);
        }
    }

    // +1 is for empty string
    return count + 1;
}

int main()
{
    return 0;
}