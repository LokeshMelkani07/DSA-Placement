#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
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

void PostOrder(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    PostOrder(node->left, ans);
    PostOrder(node->right, ans);
    ans.push_back(node->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // PostOrder Traversal is left right root
    // So we first go to the left
    // then we go to its right
    // Then we print the data
    // we do this till node != NULL
    vector<int> ans;
    PostOrder(root, ans);
    return ans;
}

int main()
{
    return 0;
}