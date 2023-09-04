#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Top View of Binary Tree
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost).
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    // We will use Vertical Line concept
    // We draw vertial lines and first node of our vertical line is our top view answer
    // we draw a line on root node and its line 0
    // we go to root->left and draw a line its line -1
    // we go to root->right and draw a line its line +1
    // Its simple, everytime we go left we do -1 from current line number
    // everytime we go right we do +1 from current line number
    // we will use a queue which stores pair of node and line Number
    // we will use a map which stores line number and node->val in unique and sorted order
    // We used same concept in bottom view but here we need top view so if there already exists a key in map for a line number then we will not store or update it
    // At the end our map contains our answer
    vector<int> ans;
    map<int, int> mpp;
    queue<pair<TreeNode<int> *, int>> q;
    if (root == NULL)
        return ans;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *cur = it.first;
        int lineNumber = it.second;
        if (mpp.find(lineNumber) == mpp.end())
        {
            mpp[lineNumber] = cur->data;
        }

        if (cur->left != NULL)
        {
            q.push({cur->left, lineNumber - 1});
        }

        if (cur->right != NULL)
        {
            q.push({cur->right, lineNumber + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    return 0;
}