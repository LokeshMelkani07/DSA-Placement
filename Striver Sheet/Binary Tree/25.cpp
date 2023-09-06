#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [0]
Output: [0]
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

void flatten(TreeNode<int> *root, TreeNode<int> *&prev)
{
    if (root == NULL)
        return;

    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flattenBinaryTree(TreeNode<int> *root)
{
    // We can think of solution like we will find the preOrder and make a LL out of it but
    // We have to use Tree and re-arrange it in such a way that it represents a LL whose order is same as PreOrder of tree
    // and right child of each node and NEXT pointer in LL and left child Points to NULL
    // Recursive Solution
    // We know preOrder is root, left, right
    // here what we will do is we will start making list from right,left,root
    // Because we need to matched preOrder
    // we make a previoud node = NULL initially
    // we go to right till there is right != NULL
    // if node == NULL we return
    // then we go to the left till its not null
    // now we have done both right and left, we make node->right = prev, node->left = NULL and prev = node
    // This way we get a LL which matches the preOrder of BT
    // at last we return prev as first node of our LL
    // TC: O(n), SC: O(n)
    TreeNode<int> *prev = NULL;
    flatten(root, prev);
}

void flattenBinaryTree(TreeNode<int> *root)
{
    // Stack Approach same as Recursion in terms of complexity but no recursion here, its iterative
    // push root in stack
    // now, till stack is not empty
    // pick the stack top say cur
    // go to right, push it
    // go to left, push it
    // if stack is not empty, make cur->right = st.top() now
    // make cur->left = NULL
    stack<TreeNode<int> *> st;
    st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur->right)
        {
            st.push(cur->right);
        }

        if (cur->left)
        {
            st.push(cur->left);
        }

        if (!st.empty())
        {
            cur->right = st.top();
        }

        cur->left = NULL;
    }

    return;
}

void flattenBinaryTree(TreeNode<int> *root)
{
    // Mooris Traversal
    // TC: O(n), SC: O(1)
    // We need to make a connection between the rightest node of root->left and root->right node
    TreeNode<int> *cur = root; // start from root
    while (cur != NULL)
    {
        // if cur ka left exists
        if (cur->left)
        {
            // make a node which will go to rightest node of left subtree of cur
            TreeNode<int> *node = cur->left;
            while (node->right)
            {
                // till node->right is not NULL, right jaate jaao
                node = node->right;
            }
            // now we are at the rightest node, lets make a connect between rightest node and cur->right means rightest node and root->right ka connection
            node->right = cur->right;
            // now to make it a LL, root ka right, root ke left mai point kardo
            cur->right = cur->left;
            // make left point to NULL
            cur->left = NULL;
        }
        // move cur to uska right which is now changed
        cur = cur->right;
    }
}

int main()
{
    return 0;
}