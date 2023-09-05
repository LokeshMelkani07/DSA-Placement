#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Same Tree
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false
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

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // We can do any type of traversal and at the end check if its same for both trees
    // if yes, they are identical
    // if no, they are not identical
    // Here we will do preOrder Traversal, we can also do Level order
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }

    // root left right -> preOrder
    return (root1->data == root2->data) && (identicalTrees(root1->left, root2->left)) && (identicalTrees(root1->right, root2->right));
}

int main()
{
    return 0;
}