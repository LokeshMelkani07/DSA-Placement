#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
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

bool checkSymmetry(TreeNode<int> *left, TreeNode<int> *right)
{
    // check if any of the left and right is NULL
    if (left == NULL || right == NULL)
    {
        // return true if both have equal value
        // return false if both have unequal value
        return left == right;
    }

    // if they are not NULL, compare their values and if values not same return false immediately
    if (left->data != right->data)
    {
        return false;
    }

    // if values are not NULL and values are same, go to left in left half and at the same time, go to right in right half
    // go to right in left half and left in right half and check the conditions
    return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
}

bool isSymmetric(TreeNode<int> *root)
{
    // Symmetric means mirror image of a tree from centre i.e root is created and original tree is superimposed in it
    // and if its successfully superimposes means its a symmetric tree
    // we know in a mirror, left appears right and right appears left so if a node if in root->left, In mirror it will become root->right
    // If we take a traversal like PreOrder in Original tree i.e root, left, right
    // It will become something like root, right, left in Mirror Image
    // So we can use this technique and find out if its a symmetric tree or not
    // What we do is, we traverse both parts simultaneously, In in left part we travel left, In right part, we travel right
    // If at any point value does not matches we return false

    // if root is NULL means its not mirron else go to left and right of root and considering root as center, start checking
    return root == NULL || checkSymmetry(root->left, root->right);
}

int main()
{
    return 0;
}