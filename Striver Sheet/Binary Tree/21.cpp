#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
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

int maximumSumPath(BinaryTreeNode<int> *node, int &maxi)
{
    if (node == NULL)
        return 0;

    // here we are checking if there is negative value take 0 instead
    int left = max(0, maximumSumPath(node->left, maxi));
    // here we are checking if there is negative value take 0 instead
    int right = max(0, maximumSumPath(node->right, maxi));
    // left gives us max sum in left subtree, right gives us max sum in right subtree
    maxi = max(maxi, (left + right + node->data));

    // return maximum path
    return node->data + max(left, right);
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    // We can take path between any of 2 nodes and cover all nodes
    // compare sum with a maxi and get the answer but this approach will take O(n^2)
    // Optimised approach
    // we can take a node and find its max sum in left subtree of that node, max sum in right subtree of that node
    // So max sum for a longest path going through that node will become
    // (value of node) + (max sum from left subtree) + (max sum from right subtree)
    // Maximum sum from each node using above formula will be our answer
    // So what we do it, maintain a maxi which is initially 0
    // Go to left subtree then go to right subtree
    // now check maxi = max(maxi, left+right+node->val)
    // if yes then update maxi and
    // return node->value + max(leftHeight,rightHeight) this will give us which path to take to get maximum sum so we will take that path from left and right whose height is greater
    // We will ignore if any node has negative value and instead take it as 0
    // because a negative value will never help us in getting maximum sum
    int maxi = INT_MIN;
    maximumSumPath(root, maxi);
    return maxi;
}

int main()
{
    return 0;
}