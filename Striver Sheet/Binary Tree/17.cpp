#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
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

bool func(TreeNode<int> *root, int b, vector<int> &v)
{
    // Function to find the path from root to node with value b

    // if root==NULL means not found return false
    if (!root)
        return false;
    // else push data in vector first
    v.push_back(root->data);
    // check if data is b means we have found the path so return true
    if (root->data == b)
        return true;
    // if any of left or right subtree has node with value b, return true
    if (func(root->left, b, v) || func(root->right, b, v))
        return true;
    // otherwise pop the element inserted in the beginning
    v.pop_back();
    return false;
    ;
}

int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
    // Naive Approach
    // LCA for X and Y is an ancestor which is common for both and is at lowest level or closest level
    // if Y is itself a ancestor of X then Y can also become LCA
    // What we will do is, find path from root to X and store in vector
    // Find path from root to Y and store in vector
    // Now we compare both vectors and first element which mismatch, we go to its previous element which matched in both vector
    // That previous matched element will be our LCA for X and Y
    if (root->data == p || root->data == q)
        return root->data;
    if (root->left->data == p || root->left->data == q)
        return root->data;
    if (root->right->data == p || root->right->data == q)
        return root->data;
    int ans;
    vector<int> v1;
    vector<int> v2;
    func(root, p, v1);
    func(root, q, v2);
    int i = 0;
    // compare both vector
    while (i < v1.size() and i < v2.size())
    {
        // if a element not matched
        if (v1[i] != v2[i])
        {
            // store the last matched element and return it
            ans = v1[i - 1];
            break;
        }
        i++;
    }
    return ans;
}

TreeNode<int> *LCA(TreeNode<int> *node, int a, int b)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->data == a || node->data == b)
    {
        return node;
    }

    // Go to the left
    TreeNode<int> *left = LCA(node->left, a, b);
    // Go to the right
    TreeNode<int> *right = LCA(node->right, a, b);

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        // Both are not NULL means we have found the LCA
        return node;
    }
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    // Optimised Approach
    // For a node we go to its left and right and search for x and y
    // if we found x, we return x
    // if we found y, we return y
    // Now if left returns x and right returns NULL for a node, we pick the x value and ignore NULL
    // Sameway if left is NULL and right is y/x we pick right value
    // if both return NULL, we return NULL for a node
    // SO LCA will be the one whose left and right both are not NULL means thats the LCA we are looking for
    if (root == NULL)
        return -1;

    TreeNode<int> *ans = LCA(root, x, y);
    return ans->data;
}

int main()
{
    return 0;
}