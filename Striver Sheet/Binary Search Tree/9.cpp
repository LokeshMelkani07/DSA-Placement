#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode<int> *root, int &K, int &ans)
{
    if (root == NULL)
        return;

    // go to left
    inorderTraversal(root->left, K, ans);
    // do k--
    K--;
    // if k==0 means we are standing at kth smallest element
    if (K == 0)
    {
        // store in ans and return
        ans = root->data;
        return;
    }

    // Go to right
    inorderTraversal(root->right, K, ans);
}

int kthSmallest(TreeNode<int> *root, int K)
{
    // Naive Approach
    // We do any of the traversal and we take a vector
    // we store all nodes in the vector
    // we sort that vector and get the kth smallest element
    // TC: O(n) + O(nlogn) for traversal and sorting, SC: O(n) for vector
    // Optimised Approach 1
    // There is a property of BST that Inorder of a BST is always sorted
    // So we store the Inorder of BST in a vector and get the kth smallest element
    // TC: O(n) for traversal and SC: O(n) for vector
    // Optimised Approach 2
    // Instead of using a vector to store Inorder we can use a count = 0;
    // When we pass a node, we do count++
    // if count==K means the node we are standing at is our kth smallest element

    // Inorder is left root right
    int ans = 0;
    inorderTraversal(root, K, ans);
    return ans;
}

int main()
{
    return 0;
}