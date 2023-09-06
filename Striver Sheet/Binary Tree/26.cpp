#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Invert a Binary Tree
Given the root of a binary tree, invert the tree, and return its root.



Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []


Example 1:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2

Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *root)
{
    if (root == NULL)
        return;
    helper(root->left);
    helper(root->right);
    // swapping happens
    auto temp = root->left;
    root->left = root->right;
    root->right = temp;
}
TreeNode *invertTree(TreeNode *root)
{
    // We see that At each level, swapping is happenening
    // Except root
    // If we use example 1
    // 4 remains same as it is
    // we go to root->left if node==NULL we return
    // we go to root->right, if node==NULL we return
    // we swap root->left with root->right using a temp variable
    // that's it
    helper(root);
    return root;
}

int main()
{
    return 0;
}