#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Binary Search Tree Iterator
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

    BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
    boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
    int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

Example 1:

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
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

// Naive Solution
class BSTiterator
{
public:
    // We are using a stack to store reverse In-order
    // Stack has LIFO property so to store answer in sorted order we do reverse inorder
    // Inorder = left,root,right
    // reverse Inorder = right,root,left
    stack<int> st;
    void inorder(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        inorder(root->right);
        st.push(root->data);
        inorder(root->left);
        return;
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        inorder(root);
    }

    int next()
    {
        // write your code here
        if (st.empty())
            return -1;
        else
        {
            int z = st.top();
            st.pop();
            return z;
        }
    }

    bool hasNext()
    {
        // write your code here
        if (st.empty())
            return false;
        else
            return true;
    }
};

class BSTiterator
{
private:
    stack<TreeNode<int> *> st;

public:
    // Naive Approach
    // We can store the Inorder of the BST and using a pointer we can tell about next() and hasNext()
    // TC: O(n), SC: O(n)
    // Another approach can be to use Stack
    // We use a stack and we do not do inorder traversal or store it in a vector
    // we push root in stack and we put all root->left element in stack till stack is not empty
    // if we get next(), we pick stack top element, we pop it out
    // if st.top() element has right, we go to right and push all its next nodes in stack same as above till node != NULL
    // we use that popped value from stack and return st.top()->value
    // for hasNext(), we check if stack is not empty means there is next element so return true else false
    // TC: O(1), SC: O(n)
    BSTiterator(TreeNode<int> *root)
    {
        // Initialises a BST with root
        pushAll(root);
    }

    int next()
    {
        // Gives the next element in the Inorder of that BST
        TreeNode<int> *tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }

    bool hasNext()
    {
        // Tells whether there is a next element in a Inorder
        if (!st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    void pushAll(TreeNode<int> *node)
    {
        for (; node != NULL; st.push(node), node = node->left)
            ;
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/

// Another solution, same as above but better code
class BSTiterator
{
    stack<TreeNode<int> *> st;

public:
    BSTiterator(TreeNode<int> *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int> *top = st.top();
        st.pop();

        TreeNode<int> *temp = top->right;

        while (temp)
        {
            st.push(temp);
            temp = temp->left;
        }

        return top->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};

int main()
{
    return 0;
}