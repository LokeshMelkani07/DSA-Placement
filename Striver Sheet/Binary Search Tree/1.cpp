#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Search in a Binary Search Tree
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []
*/

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Almost all the Binary Search Trees  have height of log2(n)
    // If it was a Binary Tree then, we could have done any type of Traversal and found out if root->val = x return true which would take O(n)
    // But in BST, we know one thing that node->left->val is always smaller than node->val
    // node->right->val is always bigger than node->val
    // So we can make use of this property, we will start from root and traverse left or right till root != NULL or root->val != x
    // TC: O(logn)
    while (root != NULL && root->data != x)
    {
        root = root->data > x ? root->left : root->right;
    }

    return root;
}

int main()
{
    return 0;
}