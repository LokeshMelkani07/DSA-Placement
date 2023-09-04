#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Preorder Traversal
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
*/

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void preOrder(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    ans.push_back(node->data);
    preOrder(node->left, ans);
    preOrder(node->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Preorder Traversal follows the order (root,left,right)
    // Print the node you are at, go to its left and then go to its right
    // Do this till, node != NULL
    // Time Complexity: O(N).
    // Reason: We are traversing N nodes and every node is visited exactly once.
    // Space Complexity: O(N)
    // Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}

int main()
{
    return 0;
}