#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Size of Largest BST in Binary Tree
You have been given a Binary Tree of  nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Sample Input 1 :

2 1 3 -1 -1 -1 -1

Sample Output 1:

3

Explanation for Sample 1:

In the given binary tree, subtree rooted at 2 is a BST and its size is 3.

Sample Input 2 :

50 -1 20 -1 30 -1 40 -1 50 -1 -1

Sample Output 2:
4
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

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode *root, int &ans)
{
    // base case
    if (root == NULL)
    {

        return {INT_MIN, INT_MAX, true, 0};
    }

    // go to left subtree
    info left = solve(root->left, ans);
    // go to right subtree
    info right = solve(root->right, ans);

    // let us check if current node make a BST of largest size
    info currNode;

    currNode.size = left.size + right.size + 1;
    // In a BST, right has always element more than root so we get maxi from right.maxi
    currNode.maxi = max(root->data, right.maxi);
    // sameway for mini
    currNode.mini = min(root->data, left.mini);

    // To check if its valid BST
    // we see if left is valid BST && right is valid BST && root->val is more than maxi of left and lesser than mini of right
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // if its a valid BST
    if (currNode.isBST)
    {
        // store largest size possible
        ans = max(ans, currNode.size);
    }
    // return current node which has information of maxi,mini,isBST,size
    return currNode;
}

int largestBST(TreeNode *root)

{
    // Naive Approach
    // We can go on every node and check if it forms a valid BST or not
    // How to check?
    // We make use of a range and check whether value is in that range or not
    // TC: O(n^2) as we are validating for each BST
    // Optimised Approach 2
    // for each node we check if left subtree is a valid BST, right subtree is valid BST, node->val > maximum of left subtree and node->val is lesser smallest element of right subtree
    // so we need to have max element of left subtree, min element of right subtree, a bool to check if its a valid BST
    // then size of BST will be left.size() + right.size() + 1
    // we make a class in which we store maxi,mini,size,isBST
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

/*
Maximum Sum BST in Binary Tree
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode1
{
    int val;
    TreeNode1 *left;
    TreeNode1 *right;
    TreeNode1() : val(0), left(nullptr), right(nullptr) {}
    TreeNode1(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode1(int x, TreeNode1 *left, TreeNode1 *right) : val(x), left(left), right(right) {}
};

class info1
{
public:
    int maxi;
    int mini;
    bool isBst;
    int sum;
};

info1 solve1(TreeNode1 *root, int &ans)
{

    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info1 left = solve1(root->left, ans);
    info1 right = solve1(root->right, ans);

    info1 currNode;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);
    currNode.sum = left.sum + right.sum + root->val;

    if (left.isBst && right.isBst && (root->val > left.maxi && root->val < right.mini))
    {
        currNode.isBst = true;
        currNode.sum = left.sum + right.sum + root->val;
    }
    else
    {
        currNode.isBst = false;
    }

    if (currNode.isBst)
        ans = max(ans, currNode.sum);
    return currNode;
}
int maxSumBST(TreeNode1 *root)
{
    int sum = 0;
    info1 t = solve1(root, sum);
    return sum;
}

int main()
{
    return 0;
}