#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Construct Binary Search Tree from Preorder Traversal
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
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

TreeNode *Build(vector<int> &preOrder, int &i, int bound)
{
    if (i == preOrder.size() || preOrder[i] > bound)
        return NULL;
    // Create a node and increment i to next element
    TreeNode *node = new TreeNode(preOrder[i++]);
    // Go to left and bound is now node->val
    node->left = Build(preOrder, i, node->data);
    // Go to right and bound is same INT_MAX
    node->right = Build(preOrder, i, bound);

    return node;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Naive Approach
    // We know Preorder is root,left,right
    // We start from first element and it will be our root
    // now we check next element and if its smaller than root, we put it in left of root, else right of root
    // now, move to next element and check similarly
    // TC: O(n*n) to check and insert the element in BST
    // Optimised Approach 1
    // Inorder of a BST is always sorted in order
    // So if we sort the Preorder, we can get Inorder also so now we have PreOrder and Inorder and we have to make a BST out of it
    // Now we know how to make a Binary tree from Inorder and Preorder so we make it
    // TC: O(nlogn) + O(n), SC: O(n)
    // Optimised Approach 2
    // We know value of root can go max till [INT_MIN, INT_MAX]
    // i.e lower bound = INT_MIN and upper bound is INT_MAX for root
    // now for root->left, the range is [anything, root->val]
    // for root->right, the range is [root->val,anything]
    // Now if we take first element of preOrder as root, as preOrder is root,left,right
    // then next few elements whose upper bound is less than node->val can come in its left
    // Simply we say we have Baap, parent, childL,childR
    // if node has value<childL then it can be inserted in left of childL
    // but if value>childL we cannot insert it in left of childL so we check if value<parent
    // if yes, we insert it in right of childL, if no then we cannot insert it as child of childL
    // we go to parent and check if value<parent, we insert in parent->left
    // if value>parent, we check if value<Baap,if yes, we insert in parent->right
    // else we cannot insert it there, go to Baap and so on
    // Now when we go to root->right, we take bound = INT_MAX
    // and we try to do the same approach
    // base case, if our Array finishes or our A[i]>bound return NULL
    // TC: O(3n) and SC: O(1)
    int i = 0;
    return Build(preOrder, i, INT_MAX);
}

int main()
{
    return 0;
}