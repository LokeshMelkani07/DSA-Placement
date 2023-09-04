#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// A binary tree is one of the most extensively used tree data structures. It is a hierarchical data structure wherein each node has two children, the left child and the right child

/*
Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

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

void inOrder(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    inOrder(node->left, ans);
    ans.push_back(node->data);
    inOrder(node->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Inorder Traversal means (Left, root, right)
    // We go to left node using recursion, go on to left node till node != NULL
    // if node == NULL, return
    // Print the data of the node
    // Go to right node now
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}

int main()
{
    return 0;
}
