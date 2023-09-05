#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
*/

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> levelOrder(TreeNode<int> *root)
{
    // We will use a queue for it and a vector to store the answer
    // we will push root in the queue
    // now we traverse till !q.empty(), eveytime we run a loop for q.size()
    // we pick front element, and pop it
    // we check if front has left, push in queue
    // if front has right push in queue
    // now store value of front in vector
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            ans.push_back(node->data);
        }
    }

    return ans;
}

int main()
{
    return 0;
}
