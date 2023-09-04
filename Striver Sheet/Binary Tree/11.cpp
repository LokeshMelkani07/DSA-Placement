#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
using namespace std;

/*
All Root to Leaf Paths In Binary Tree.
You are given an arbitrary binary tree consisting of 'N' nodes numbered from 1 to 'N'. Your task is to print all the root to leaf paths of the binary tree.

Note:

1. Two nodes may have the same value associated with it.
2. The root node will be fixed and will be provided in the function.
3. Note that the nodes in a path will appear in a fixed order. For example, 1 2 3 is not the same as 2 1 3.
4. Each path should be returned as a string consisting of nodes in order and separated by a space.
5. The path length may be as small as ‘1’.
Sample Input 1 :

5
1 2 3 4 5 -1 -1 -1 -1 -1 -1

Sample Output 1 :

1 2 4
1 2 5
1 3

Explanation for Sample Input 1:

All the root to leaf paths are :
1 2 4
1 2 5
1 3

Sample Input 2 :

7
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

Sample Output 2 :

1 3 5
1 3 6
1 2 4 7
*/

template <typename T = int>
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void path(BinaryTreeNode<int> *root, vector<string> &ans, string res)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        // if the node we are standing at is the leaf node
        // we have our first answer
        res += to_string(root->data);
        // store that answer
        ans.push_back(res);
        // and return, now check right node
        return;
    }

    // store node value in the answer
    res += to_string(root->data) + " ";
    // move to left part
    path(root->left, ans, res);
    // move to right part if left has no node further
    path(root->right, ans, res);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    // We will traverse lefttest node first
    // that becomes one of our path
    // now we come back and go to right node and then go to leftest node, thats another path
    // this way we get all root to leaf node paths
    vector<string> ans;
    path(root, ans, "");
    return ans;
}

int main()
{
    return 0;
}