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
Implement Trie 2
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.
1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

Note:
1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.

Can you help Ninja implement the "TRIE" data structure?

Sample Input 1:

1
5
insert coding
insert ninja
countWordsEqualTo coding
countWordsStartingWith nin
erase coding

Sample Output 1:

1
1

Explanation of sample input 1:

After insertion of “coding” in “TRIE”:

After insertion of “ninja” in “TRIE”:

Count words equal to “coding” :

Count words those prefix is “nin”:

After deletion of the word “coding”, “TRIE” is:

Sample Input 2:

1
6
insert samsung
insert samsung
insert vivo
erase vivo
countWordsEqualTo samsung
countWordsStartingWith vi

Sample Output 2:

2
0

Explanation for sample input 2:

insert “samsung”: we are going to insert the word “samsung” into the “TRIE”.

insert “samsung”: we are going to insert another “samsung” word into the “TRIE”.

insert “vivo”: we are going to insert the word “vivo” into the “TRIE”.

erase “vivo”: we are going to delete the word “vivo” from the “TRIE”.

countWordsEqualTo “samsung”: There are two instances of “sumsung” is present in “TRIE”.

countWordsStartingWith “vi”: There is not a single word in the “TRIE” that starts from the prefix “vi”.
*/

struct Node
{
    Node *arr[26]; // 0-based indexing
    int endWith = 0;
    int countPrefix = 0;

    bool containsLetter(char ch)
    {
        return (arr[ch - 'a']);
    }

    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }

    void incrementEndWith()
    {
        endWith++;
    }

    void decrementEndWith()
    {
        endWith--;
    }

    void incrementCountPrefix()
    {
        countPrefix++;
    }

    void decrementCountPrefix()
    {
        countPrefix--;
    }

    int getEndWithofLastNode()
    {
        return endWith;
    }

    int getCountPrefix()
    {
        return countPrefix;
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsLetter(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementCountPrefix();
        }

        // last node
        node->incrementEndWith();
    }

    int countWordsEqualTo(string &word)
    {
        // start from root
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsLetter(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        // End with has info of number of words ending with this word
        return node->getEndWithofLastNode();
    }

    int countWordsStartingWith(string &word)
    {
        // start from root
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsLetter(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        // Count Prefix has information of number of word whose prefix is this word
        return node->getCountPrefix();
    }

    void erase(string &word)
    {
        // start from root
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // Assume we found it, so decrese CP for everyone
            if (node->containsLetter(word[i]))
            {
                node = node->get(word[i]);
                node->decrementCountPrefix();
            }
            else
            {
                return;
            }
        }
        // we are at last node
        // so decrease EW also
        node->decrementEndWith();
    }
};

int main()
{
    return 0;
}