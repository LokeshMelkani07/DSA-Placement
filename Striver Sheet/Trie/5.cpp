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
Maximum XOR With an Element From Array

You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers.  You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].
The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’  in ‘ARR’.
You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.

Note:
1. If all integers are greater than ‘Ai’ in array/list ‘ARR’  then the answer to this ith query will be -1.

Sample Input 1:
2
5 2
0 1 2 3 4
1 3
5 6
1 1
1
1 0

Sample Output 1:
3 7
-1

Explanation of sample input 1:
In the first test case, the answer of query [1, 3] is 3 because 1^2 = 3 and 2 <= 3,  and the answer of query [5, 6] is 7 because  5 ^ 2 = 7 and 2 <= 6.

In the second test case, no element is less than or equal to 0 in the given array ‘ARR’.

Sample Input 2:
2
6 3
6 6 3 5 2 4
6 3
8 1
12 4
5 2
0 0 0 0 0
1 0
1 1

Sample Output 2:
5 -1 15
1 1
*/

struct Node
{
    Node *links[2];

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
        // cout << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int index = 0;
    for (auto &it : queries)
    {
        // store {Ai, Xi, index} we need to sort according to Ai so we store it like that
        offlineQueries.push_back({it[1], {it[0], index++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    int n = arr.size();
    Trie trie;

    for (auto &it : offlineQueries)
    {
        // find all indexes less than arr[i]
        while (i < n && arr[i] <= it.first)
        {
            // insert them all in trie
            trie.insert(arr[i]);
            i++;
        }
        // if we have inserted them successfully, store them accordingly to offline query index in our answer using findMax function we created in last problem
        if (i != 0)
            ans[it.second.second] = trie.findMax(it.second.first);
        // means no element found <= arr[i] so store -1 in answer
        else
            ans[it.second.second] = -1;
    }
    return ans;
}

int main()
{
    return 0;
}