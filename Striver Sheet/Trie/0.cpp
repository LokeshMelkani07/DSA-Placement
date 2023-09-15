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
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.



Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

struct Node
{
    Node *arr[26];
    bool flag = false;

    // To check if our array already has ch or not before inserting

    bool hasLetter(char ch)
    {
        // if node of that character is not NULL means that exists
        return (arr[ch - 'a'] != NULL);
    }

    // To insert a node in array for ch

    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }

    // To get ref node of ch

    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }

    // To set the end ref node ka bool as true

    void setEnd()
    {
        flag = true;
    }

    // Check if end ref node has flag value = true means word complete else false, then word is not found completely
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        // Every Time constructor is called, make a new root
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        // TC: O(length of word)
        // we need to insert each letter of word in trie
        // starting from root
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // before inserting check if that already exist so we make a function in struct Node
            if (!node->hasLetter(word[i]))
            {
                // we have used ! means if we here, it does not exist
                // let us insert it
                node->put(word[i], new Node());
            }
            // move to reference of trie node
            node = node->get(word[i]);
        }

        // loop ends means we are at the last ref node means mark the bool = true for last ref node as word is finished
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        // TC: O(length of word)
        // always start with root node
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // check if char is there or not
            if (!node->hasLetter(word[i]))
            {
                // if it does not exists means
                return false;
            }
            // else give me ref node of that char
            // we are storing ref node so that we can check at the end if last ref node is true means complete word is found
            node = node->get(word[i]);
        }

        // now we are at end ref node so check bool
        // if true means we are at the end else not
        if (node->isEnd())
        {
            return true;
        }

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        // TC: O(length of word)
        // again start from root
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->hasLetter(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        // if we reach here means there is something whose prefix is word
        return true;
    }
};

int main()
{
    return 0;
}
