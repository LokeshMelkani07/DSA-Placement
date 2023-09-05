#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

For the given binary tree [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
    1
   / \
  2   3
     / \
    4   5

Output: 1 3 2 4 5


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
*/

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
    // We will do a Level order Traversal only but
    // First we print left to right
    // then we print right to left
    // then we print left to right and so on
    // So we need a queue and vector<int> to do level order traversal and store it
    // but we will also need a flag variable to tell us if its leftToRight or rightToLeft
    // Level order traversal will be same just that when we are storing it in the vector we will store it based on leftToRight or rightToLeft
    vector<int> result;
    if (root == NULL)
        return result;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;

            ans[index] = node->data;

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
        for (auto &ele : ans)
        {
            result.push_back(ele);
        }
        leftToRight = !leftToRight;
    }

    return result;
}

int main()
{
    return 0;
}