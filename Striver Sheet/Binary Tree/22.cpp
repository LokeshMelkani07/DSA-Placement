#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
using namespace std;

/*
Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
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

TreeNode<int> *buildingTree(vector<int> &inorder, int Instart, int Inend, vector<int> &preorder, int preStart, int preEnd, map<int, int> mpp)
{
    if (Instart > Inend || preStart > preEnd)
    {
        // if there is no Inorder or Preorder for any node means
        return NULL;
    }

    // Create a new node with taking first element of preOrder as root
    TreeNode<int> *node = new TreeNode<int>(preorder[preStart]);
    // Find in map
    int index = mpp[node->data];
    // get the left elements in Inorder
    int numsLeft = index - Instart;

    // Take left subtree Inorder and from the preorder take preOrder of left subtree elements only i.e [20,40,50]
    node->left = buildingTree(inorder, Instart, index - 1, preorder, preStart + 1, preStart + numsLeft, mpp);
    // Take right subtree Inorder [60,30] and from the preorder take preOrder of right subtree elements only i.e [60,30]
    node->right = buildingTree(inorder, index + 1, Inend, preorder, preStart + numsLeft + 1, preEnd, mpp);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    // We know inorder is left, root, right
    // We know preorder is root, left, right
    // So first element of preOrder will always show root element
    // Let us take this example where inorder = [40,20,50,10,60,30] and preorder = [10,20,40,50,30,60]
    // 10 is our root element as we see from preOrder
    // we see in Inorder for element 10, [40,20,50] will be its left and [60,30] will be its right as we know Inorder is left root right
    // For others, we again check preOrder and inOrder
    // Now for [40,20,50] we check preOrder we see 20 is the root
    // for ele = 20 we check Inorder and we see 40 is its left and 50 is its right
    // Similarly we can check for each element and we can make subtrees and complete the whole tree
    // So how will our code work let us take this example again
    // inorder = [40,20,50,10,60,30] and preorder = [10,20,40,50,30,60]
    // we will store the Inorder inside a map with indexes as value
    // we will take one value from preOrder and mark it as root say 10
    // for 10, [40,20,50] becomes Inorder of left subtree and [60,30] becomes Inorder of right subtree
    // Using map we check where is our preOrder[10] lies in Inorder
    // and we pass preOrder starting point, preOrder ending point, Inorder starting point, Inorder ending point
    // Using these indexes we find Inorder of left subtree and right subtree for a root preOrder[10]
    // We call the recusrion for left and right subtree
    // for any node if preStart>preEnd or Instart>Inend then that is leaf node, return NULL
    map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }

    TreeNode<int> *root = buildingTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, mpp);
    return root;
}

int main()
{
    return 0;
}