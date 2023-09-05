#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Boundary Traversal of Binary Tree
You are given a binary tree having 'n' nodes
The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.
Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.
Sample Input 1:

10 5 20 3 8 18 25 -1 -1 7 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:

10 5 3 7 18 25 20

Explanation of Sample Input 1:

The nodes on the left boundary are [10, 5, 3]

The nodes on the right boundary are [10, 20, 25]

The leaf nodes are [3, 7, 18, 25].

Please note that nodes 3 and 25 appear in two places but are considered once.

Sample Input 2:

100 50 150 25 75 140 200 -1 30 70 80 -1 -1 -1 -1 -1 35 -1 -1 -1 -1 -1 -1

Sample Output 2:

100 50 25 30 35 70 80 140 200 150
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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root)
{
    // Jiska right and left child koi nhi h vo leaf node hai
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int> *node, vector<int> &res)
{
    // Start from left of root
    TreeNode<int> *cur = node->left;
    while (cur)
    {
        // if its not a leaf node, add in answer
        if (!isLeaf(cur))
            res.push_back(cur->data);
        // if there is a left, go to left
        if (cur->left)
            cur = cur->left;
        // go to right
        else
            cur = cur->right;
    }
}

void addLeafNode(TreeNode<int> *node, vector<int> &res)
{
    // Normal Inorder Traversal
    // Left root right

    if (isLeaf(node))
    {
        // isLeaf(node) is same as saying root==NULL
        res.push_back(node->data);
        return;
    }

    if (node->left)
        addLeafNode(node->left, res);
    if (node->right)
        addLeafNode(node->right, res);
}

void addRightBoundary(TreeNode<int> *node, vector<int> &res)
{
    vector<int> temp; // to store sequence in temp vector so that in original vector, reverse order can be stored
    // Start from right of root
    TreeNode<int> *cur = node->right;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        // if there is right, go right
        if (cur->right)
            cur = cur->right;
        // if there is no right, go left
        else
            cur = cur->left;
    }

    // Store in Reverse order
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // We can solve this using following cases:
    // We will use a vector to store the result
    // Take left boundary (excluding leaf nodes)
    // store the result but always check it should not be a leaf node
    // Go to the left left of the node, if there is no left go to right
    // Take leaf nodes
    // For this we use a Inorder Traversal to cover leaf nodes in a sequential manner
    // Take right boundary (excluding leaf nodes) in reverse order
    // For this we go right right and store in a temp vector or stack and if there is no right, we go left
    // at last we copy temp in result vector in reverse order and if its a stack then no need to reverse it as stack follows LIFO
    vector<int> result;
    if (!root)
        return result;
    // Add the root first
    if (!isLeaf(root))
        result.push_back(root->data);
    // Now add left boundary excluding leaf nodes
    addLeftBoundary(root, result);
    // Add leaf Nodes
    addLeafNode(root, result);
    // Add right boundary exclude leaf nodes in reverse order
    addRightBoundary(root, result);

    return result;
}

int main()
{
    return 0;
}