#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
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

int heightOfTree(TreeNode<int> *node)
{
    if (node == NULL)
        return 0;

    int lh = heightOfTree(node->left);
    int rh = heightOfTree(node->right);

    return 1 + max(lh, rh);
}

bool isBalancedBT(TreeNode<int> *root)
{
    // Naive approach
    // A balanced Binary tree is the one in which, for every node
    // (right subtree height - left subtree height) <= 1
    // So if above condition do not fulfills for any one of the node in the tree means whole tree is unbalanced
    // we will find the left heigh and right height for each node and check above condition
    // Then we go left and right of that node and we do this for every node
    if (root == NULL)
        return true;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    if (abs(rightHeight - leftHeight) > 1)
        return false;

    bool left = isBalancedBT(root->left);
    bool right = isBalancedBT(root->right);

    // if any of the node is not balanced then whole tree is not balanced so return false
    if (!left || !right)
        return false;

    return true;
}

int height(TreeNode<int> *node)
{
    if (node == NULL)
        return 0;

    int lh = height(node->left);
    // if for any of the node answer is -1 means whole tree is unbalanced directly return -1
    if (lh == -1)
        return -1;
    int rh = height(node->right);
    // if for any of the node answer is -1 means whole tree is unbalanced directly return -1
    if (rh == -1)
        return -1;

    // if rh - lh is > 1 again its not a balanced BT
    if (abs(rh - lh) > 1)
        return -1;

    // otherwise return height for that node
    return 1 + max(lh, rh);
}

bool isBalancedBT(TreeNode<int> *root)
{
    // Optimised Approach
    // TC: O(n), SC: O(n)
    // We need to calculate heightofTree in same traversal to remove O(n) and optimise the solution
    // What we will do is, instead of returning true or false
    // we will return "height of the tree" if its a balanced BT
    // we will return -1 if its not a balanced BT

    // if ans is -1 means its not a Balanced BT else it is balanced BT
    return height(root) != -1;
}

int main()
{
    return 0;
}