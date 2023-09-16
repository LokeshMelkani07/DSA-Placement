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
Complete String
Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".

Note:
String ‘P’ is lexicographically smaller than string ‘Q’, if :

1. There exists some index ‘i’ such that for all ‘j’ < ‘i’ , ‘P[j] = Q[j]’ and ‘P[i] < Q[i]’. E.g. “ninja” < “noder”.

2. If ‘P’ is a prefix of string ‘Q’, e.g. “code” < “coder”.

Example:
N = 4
A = [ “ab” , “abc” , “a” , “bp” ]

Explanation :

Only prefix of the string “a” is “a” which is present in array ‘A’. So, it is one of the possible strings.

Prefixes of the string “ab” are “a” and “ab” both of which are present in array ‘A’. So, it is one of the possible strings.

Prefixes of the string “bp” are “b” and “bp”. “b” is not present in array ‘A’. So, it cannot be a valid string.

Prefixes of the string “abc” are “a”,“ab” and “abc” all of which are present in array ‘A’. So, it is one of the possible strings.

We need to find the maximum length string, so “abc” is the required string.

Sample Input 1 :

2
6
n ni nin ninj ninja ninga
2
ab bc

Sample Output 1 :

ninja
None

Explanation Of Sample Input 1 :

For test case 1 we have,

All the prefixes of “ninja” -> “n”, “ni”, “nin”, “ninj” and “ninja” are present in array ‘A’. So, “ninja” is a valid answer whereas for “ninga” , the prefix “ning” is not present in array ‘A’.

So we output “ninja”.

For test case 2 we have,

The prefixes of “ab” are “a” and “ab”. “a” is not present in array ‘A’. So, “ab” is not a valid answer.

The prefixes of “bc” are “b” and “bc”. “b” is not present in array ‘A’. So, “ab” is not a valid answer.

Since none of the strings is a valid answer we output “None”.

Sample Input 2 :

2
5
g a ak szhkb hy
4
kez vfj vfjq vfjqo

Sample Output 2 :

ak
None
*/

// Let us make a struct node
struct Node
{

    Node *arr[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (arr[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool getEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    // constructor
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        // start from root
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            // check kar
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        // At last mark last node as true flag
        node->setEnd();
    }

    bool wordisThere(string word)
    {
        // starting from root
        Node *node = root;
        bool flag = true;

        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                flag = flag && node->getEnd();
            }
            else
            {
                return false;
            }
        }

        return flag;
    }
};

string completeString(int n, vector<string> &a)
{

    // Make object of Trie class
    Trie obj;

    string complete = "";

    for (auto it : a)
    {
        // Insert all strings in trie
        obj.insert(it);
    }

    // Again traverse and look for every word
    for (auto it : a)
    {
        if (obj.wordisThere(it))
        {
            // compare with complete because we need longest string
            if (it.size() > complete.size())
            {
                complete = it;
            }
            else if (it.size() == complete.size() && it < complete)
            {
                // if length of both are same means return lexo smaller string
                complete = it;
            }
        }
    }

    if (complete == "")
        return "None";
    return complete;
}

int main()
{
    return 0;
}