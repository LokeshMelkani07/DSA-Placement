#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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

bool validate(BinaryTreeNode<int> *root, long mini, long maxi)
{
    // if its NULL return true
    if (root == NULL)
        return true;
    // if it does not follows condition return false
    if (root->data >= maxi || root->data <= mini)
        return false;

    return validate(root->left, mini, root->data) && validate(root->right, root->data, maxi);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // We know in a BST all the node to the right of root will be greater than root
    // All the nodes on left of root will be smaller than root
    // We will maintain a range for each node
    // Let say we have a root, childL as left child of root, childR as right child of root
    // Range for root = [INT_MIN, INT_MAX]
    // Range for childL = [INT_MIN, root->val]
    // Range for childR = [root->val,INT_MAX]
    // Now let say childL has childLL as left child and childLR as right child then
    // Range of childLL = [INT_MIN, childL]
    // ChildLR = [childL,root->val]
    // Sameway for childR we have childRL, childRR as left and right child of childR
    // Range for childRL = [root->val,childR->val]
    // Range for childRR = [childR->val, INT_MAX]
    // for each node we check if it lies in the range, if yes, then return true
    // if no, return false
    // if any of the node returns false, its not a valid BST
    // TC: O(n), SC: O(1)
    long maxi = INT_MAX;
    long mini = INT_MIN;
    return validate(root, mini, maxi);
}

int main()
{
    return 0;
}