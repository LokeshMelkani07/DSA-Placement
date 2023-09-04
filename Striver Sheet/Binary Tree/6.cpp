#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []
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

vector<int> rightSideView(TreeNode *root)
{
    // Recursive Solution
    // TC : O(n) SC : O(Height of tree)
    // To get the right view, we see the tree from right side and print all node we see from the right
    // we see our ans vector consists of all the last nodes of each level of tree
    // we will use a recursive reverse preorder traversal
    // In normal preOrder we do, root left right
    // In reverse preOrder we will do, root right left
    // we store level of tree and a DS also
    // before storing anything in our answer we check if level == ds.size() means we are coming to this level for this first time
    // So store it in the answer
    vector<int> ans;
    // we pass level as 0 initially
    rightView(root, 0, ans);
    return ans;
}
void rightView(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    // check the level before storing ans
    // if below condition satisfy means we are visiting that level for the first time so store in the answer
    if (level == res.size())
    {
        res.push_back(root->val);
    }

    rightView(root->right, level + 1, res);
    rightView(root->left, level + 1, res);
}

int main()
{
    return 0;
}