#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
Note:
1. A balanced binary tree is a binary tree structure in which the left and right subtrees of every node differ in height by no more than 1.

2. A binary search tree is a binary tree data structure, with the following properties
    a. The left subtree of any node contains nodes with value less than the node’s value.
    b. The right subtree of any node contains nodes with values equal to or greater than the node’s value.
    c. Right, and left subtrees are also binary search trees.



Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
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

TreeNode<int> *createBST(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    ;

    TreeNode<int> *node = new TreeNode<int>(arr[mid]);

    node->left = createBST(arr, start, mid - 1);
    node->right = createBST(arr, mid + 1, end);

    return node;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // We have been given a sorted array
    // We know a property for BST that left is smaller than node and right is greater than node
    // In a sorted array, if we pick any value
    // we know, values left to picked value will be smaller than picked value
    // values on right of picked value will be greater than picked value
    // we take a start = 0, end = arr.size()-1 and we find mid = start+end/2
    // now we make a node of mid and we take left values of mid and put them in node->left
    // again find mid and do the same
    // now go to right and do mid->right = right values of mid and do the same
    // if(start>end) means this is the edge case, return NULL
    int start = 0;
    int end = n - 1;
    return createBST(arr, start, end);
}

int main()
{
    return 0;
}