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
Bottom View of Binary Tree
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

For the above tree the output should be 5 10 4 14 25.

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.

Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
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

vector<int> bottomView(TreeNode<int> *root)
{
    // To get a bottom view we will make use of vertical order where
    // we draw vertical lines with line number
    // we draw first line for root node and its line 0
    // we draw next line for root->left and do -1 in it so line -1
    // we draw next line for root->right and do +1 in it so line +1
    // we store this inside a queue where we store is as (node,line number) like (2,0), (3,-1), (4,1)
    // We will also take a map<line number,node> as map will store elemets in ascending sorted order and will maintain a unique key,value pair
    // So everytime we get the latest node for any vertical line
    // If two nodes overlap over each other, our answer will contain the node at the right most
    // We will now move to next node for which we do, q.top() and check its left and right in the same way
    // At last our map contains our answer
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
        mpp[lineNumber] = cur->data;

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