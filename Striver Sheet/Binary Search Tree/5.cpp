#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
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

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // What is LCA?
    // if we draw a path from P to Q, the common node will be our LCA in the path
    // In a BST we know, Left is smaller than root and right is bigger than root
    // if we have to search for LCA for P and Q, we need to know where are P and Q?
    // P and Q can be in left subtree
    // P and Q can be in right subtree
    // P can be in left subtree and Q can be in right subtree
    // the node we are standing in can be our P or Q also
    // First we will check if node we are at is greater than P and Q then move to node->left
    // if node is smaller than P and Q, move to node->right
    // if node is between P and Q, we can say P is in left subtree and Q is in right subtree
    // So node is our LCA
    // TC: O(height of tree), SC: O(1)
    // Recursive code
    if (root == NULL)
        return NULL;
    int curr = root->data;

    if (curr < P->data && curr < Q->data)
    {
        return LCAinaBST(root->right, P, Q);
    }

    if (curr > P->data && curr > Q->data)
    {
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}

TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Same code in Iterative way
    while (root)
    {
        if (root->data > p->data && root->data > q->data)
            root = root->left;
        else if (root->data < q->data && root->data < p->data)
            root = root->right;
        else
            return root;
    }

    return NULL;
}

int main()
{
    return 0;
}