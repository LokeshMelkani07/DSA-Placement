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
Maximum XOR
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.

Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2

Sample Output 1:
15

Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15

Sample Input 2:
1
3 3
25 10 2
8 5 3

Sample Output 2:
28

Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.
*/

struct Node
{
    Node *links[2]; // just for 0 and 1

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }

    Node *get(int ind)
    {
        return links[ind];
    }

    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        // start from leftmost bit so use reverse loop
        // leftmose bit is 31st bit so start loop from 31 till 0
        for (int i = 31; i >= 0; i--)
        {
            // below operation gives us ith bit
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                // if bit not present, insert it
                node->put(bit, new Node());
            }
            // go to ref node of that bit
            node = node->get(bit);
        }
    }

public:
    int findMax(int num)
    {
        // To find maximum XOR, for that we will use that reverse technique
        // Find the reverse of ith bit of num in trie to maximize the answer
        Node *node = root;
        int maxNum = 0; // it means  000000000000000000000000000000000000
        for (int i = 31; i >= 0; i--)
        {
            // Get ith bit of num
            int bit = (num >> i) & 1;
            // instead of !bit we can also do 1- bit as we just need reverse
            // if bit = 1, then 1-0 = 1
            // if bit = 0, then 1-1 = 0
            if (node->containsKey(!bit))
            {
                // if we have reverse bit in Trie store in maximum
                // 1<<i means Turn on (make it 1) that ith bit in maxNum as our maxNum = 000000000000000000000000000000000 initially
                maxNum = maxNum | (1 << i);
                // get to ref node now
                node = node->get(!bit);
            }
            else
            {
                // if reverse bit not present, use whatever is there
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        // insert whole arr1 in Trie
        trie.insert(arr1[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        // Now trie contains all node of arr1 so use getMax and find max answer in Trie for arr2 ka har element
        maxi = max(maxi, trie.findMax(arr2[i]));
    }
    return maxi;
}

int main()
{
    return 0;
}