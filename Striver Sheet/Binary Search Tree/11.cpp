#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Pair Sum in BST.
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
Note:
1. All the elements of the Binary Search Tree are unique.
2. You can’t use the same node value/element of BST twice.


Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
*/

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(BinaryTreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

bool twoSum(BinaryTreeNode *root, vector<int> ans, int k)
{
    int start = 0;
    int end = ans.size() - 1;

    while (start != end)
    {
        if (ans[start] + ans[end] == k)
        {
            return true;
        }

        if (ans[start] + ans[end] > k)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return false;
}

bool pairSumBst(BinaryTreeNode *root, int k)
{
    // We will do a Inorder as it gives a sorted order
    // Now we store Inorder in a vector
    // We take 2 pointers start and end
    // use 2-sum approach and if start+end > k, end-- else start++
    // TC: O(n) for traversal + O(n) for 2 pointer approach, SC: O(n) for vector
    vector<int> ans;
    inorderTraversal(root, ans);
    return twoSum(root, ans, k);
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimised approach
// We can use BST iterator in the next code file 12.cpp
// We had next() in it which gave us next element in Inorder
// we make next() by push all node->left in stack and if we pop, we go right and again push all node->left in stack
// we can make before() also which gives us previous element in Inorder. we do opposite, we push all node->right in stack, on pop, we go left and push again all node->right in stack like we do reverse Inorder for it
// Now we use next() for ith pointer pointing to starting
// before() pointing to last elemnt of inorder
// start+end == X, we got it
// sum > X, we call before() to go one element previous
// sum < X, we call next() to go one element forward
// This way we do it, TC: O(n) SC: O(height)*2
// In the below code, instead of taking next() and before() separately, we have taken a bool variable and modified the code accordingly
class BSTIterator
{
    stack<TreeNode *> myStack;
    bool reverse = true;
    // reverse = true means before()
    // reverse = false means next()

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        // constructor
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
            // means its next() so go to right and push all left
            pushAll(tmpNode->right);
        else
            // means its before() so go to left and push all right
            pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        // to push elements in stack
        for (; node != NULL;)
        {
            myStack.push(node);
            if (reverse == true)
            {
                // means its before() so push all right
                node = node->right;
            }
            else
            {
                // its next() so push all left
                node = node->left;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        // Making objects for next
        BSTIterator l(root, false);
        // Making objects for before
        BSTIterator r(root, true);

        // for beginning
        int i = l.next();
        // for ending
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                // move one forward so call next()
                i = l.next();
            else
                // move one step back, call before()
                j = r.next();
        }
        return false;
    }
};

int main()
{
    return 0;
}