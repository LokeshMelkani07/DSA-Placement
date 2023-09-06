#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
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

TreeNode<int> *buildingTree(vector<int> inOrder, int Instart, int Inend, vector<int> postOrder, int postStart, int postEnd, unordered_map<int, int> mpp)
{
    if (Instart > Inend || postStart > postEnd)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(postOrder[postEnd]);
    // Find in map
    int index = mpp[postOrder[postEnd]];
    // Number in the left of node in Inorder
    int numsLeft = index - Instart;

    node->left = buildingTree(inOrder, Instart, index - 1, postOrder, postStart, postStart + numsLeft - 1, mpp);
    node->right = buildingTree(inOrder, index + 1, Inend, postOrder, postStart + numsLeft, postEnd - 1, mpp);

    return node;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    // We know Inorder is left, root, right
    // We know Postorder is left, right, root
    // We know that the last element of postOrder will be our root
    // We if say x is root
    // then in Inorder, all the elements to the left of x will be part of left subtree of x
    // all the elements in right will be part of right subtree of x
    // we again go to (x-1)th element in PostOrder and consider it as root say y
    // Now again we check in Inorder, left of y will be left subtree of y and right will part of right subtree
    // This way we construct as Binary tree recursively
    // Say for y, in Inorder, there are numsleft number of elements at left of y in Inorder
    // There are numsRight number of elements in right of y for right subtree
    // For y, the postOrder of left subtree is from 0 to 0 + numsLeft -1
    // postOrder of right subtree is from 0 + numsLeft to preorderEnd
    // We will store Inorder in a map so that its easy to locate the root and find its left and right subtree
    int inOrderSize = inOrder.size() - 1;
    int postOrderSize = postOrder.size() - 1;

    if (inOrderSize != postOrderSize)
    {
        return NULL;
    }

    unordered_map<int, int> mpp;
    for (int i = 0; i <= inOrderSize; i++)
    {
        mpp[inOrder[i]] = i;
    }
    TreeNode<int> *root = buildingTree(inOrder, 0, inOrderSize, postOrder, 0, postOrderSize, mpp);
    return root;
}

int main()
{
    return 0;
}