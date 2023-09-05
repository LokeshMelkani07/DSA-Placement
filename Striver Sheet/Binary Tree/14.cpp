#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.



Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:

Input: root = [1,null,2]
Output: 2
*/

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root)
{
    // We can solve it using Recursion and Level Order also
    // We will use Recursion for now
    // Let us make a Recurrence relation to get max height for each node
    // we can say 1 + max(left height,right height)
    // (1 +) for the current node we are in
    // then we move to left of that node and get max height from left subtree for that node
    // then we move to right of that node and get max height from right subtree for that node
    // we get max(left subtree height, right subtree height) +1 as height/depth for that particular node
    // we calulate this for all the node and at the end root node gives us height of whole tree
    // base case will be that if root==NULL i.e node is NULL return 0
    // TC: O(n), SC: O(height of tree)
    if (root == NULL)
        return 0;

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int heightOfBinaryTree(TreeNode<int> *root)
{
    // Using Level Order Traversal
    // TC: O(n), SC: O(n) for queue
    int level = 0;
    queue<TreeNode<int> *> q;
    if (root == NULL)
        return level;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        level++;
    }

    return level;
}

int main()
{
    return 0;
}