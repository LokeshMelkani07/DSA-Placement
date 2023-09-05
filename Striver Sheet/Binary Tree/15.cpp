#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1
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

// Naive Approach
int heightofTree(TreeNode<int> *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = heightofTree(node->left);
    int right = heightofTree(node->right);
    int ans = max(left, right) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Naive Approach
    // We will find the left height and right height for a node
    // and (left height + right height) gives us the maximum path passing through that node
    // we can take a variable maxi to store the max height using this way
    // TC: O(n^2) i.e O(n) for finding left and right height of every node and O(n) to go to left and right node to find max path passing through that node
    if (root == NULL)
        return 0;
    int maxi = 0;

    int lh = heightofTree(root->left);
    int rh = heightofTree(root->right);
    maxi = max(maxi, (lh + rh));

    diameterOfBinaryTree(root->left);
    diameterOfBinaryTree(root->right);
    return maxi;
}

// Optimised Approach
int heightofTree(TreeNode<int> *node, int &maxi)
{
    if (node == NULL)
        return 0;

    int lh = heightofTree(node->left, maxi);
    int rh = heightofTree(node->right, maxi);
    maxi = max(maxi, rh + lh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Optimised Approach
    // TC: O(n)
    // We will find the max height for each node and store maximum answer inside a maxi variable
    // We know how to find max height for a node i.e 1 + max(left height,right height)
    // But simultaneously, we are calculating maxi also which is right height + left height
    int maxi = 0;
    heightofTree(root, maxi);
    return maxi;
}

int main()
{
    return 0;
}