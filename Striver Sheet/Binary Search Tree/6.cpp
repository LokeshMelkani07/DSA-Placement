#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Predecessor and Successor
There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

Note:
1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

3. The node for which predecessor and successor are to be found will always be present in the given tree.

4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.


Example 1:

Input:
        10
      /   \
     2    11
   /  \
  1    5
      /  \
     3    6
      \
       4
key = 8
Output:
6 10
Explanation:
In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.

Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
key = 11
Output:
10 -1
Explanation:
In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
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

int successor(TreeNode *root, int key)
{
    int succ = -1;
    while (root != NULL)
    {
        if (key >= root->data)
        {
            root = root->right;
        }
        else
        {
            // Before we move to left side, we store the ans in variable because we might have found the succ, we just want to go further and check if its the immediate successor or not
            // So before going just store it
            // Move to left half in search of any bigger succcessor which is greater than current succ and > key (immediate)
            succ = root->data;
            root = root->left;
        }
    }

    return succ;
}

int predecessor(TreeNode *root, int key)
{
    int pred = -1;
    while (root != NULL)
    {
        if (key > root->data)
        {
            // same as above, before moving to right half to confirm whether its the immediate predecessor, just store it as it can be our potential answer
            // now move to right half in search of any bigger predecessor which is greater than current pred and < key
            pred = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return pred;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Method 1
    // We know Inorder of a BST is always a sorted array so we can find the Inorder of BST
    // We will do Binary Search (preff as its a sorted array) or linear search
    // and find the key in array then preDecessor is arr[found]-1 and successor is arr[found]+1
    // TC: O(n) for Inorder and O(logn) for Searching
    // SC: O(n) for storing Inorder in array
    // Method 2
    // Do a Inorder Traversal, first value we encounter < key is our preDecessor
    // First value we encounter > key will be our successor
    // SC: O(1), TC: O(n)
    // Method 3
    // we take the key and we check root
    // we make a predecessor and successor variable and assign it to NULL
    // if root<key, we know we will get our answer in right subtree
    // if root>key, we know we will get our answer in left subtree
    // say we go to left subtree
    // we again check if node>key or node<key and we go to left and right subtree accordingly
    // we assign variables in each step and we do this till node != NULL within our conditions
    // predecessor = element just immediate smaller to node
    // successor = element just immediate greater to node
    // TC: O(heigh of tree), SC: O(1)
    int pred = predecessor(root, key);
    int succ = successor(root, key);

    return {pred, succ};
}

int main()
{
    return 0;
}