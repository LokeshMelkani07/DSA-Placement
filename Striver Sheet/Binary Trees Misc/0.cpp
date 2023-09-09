#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

/*
Convert A Given Binary Tree To Doubly Linked List
Given a Binary Tree, convert this binary tree to a Doubly Linked List.
A Binary Tree (BT) is a data structure in which each node has at most two children.
A Doubly Linked List contains a previous pointer, along with the next pointer and data.
The order of nodes in Doubly Linked List must be the same as Inorder of the given Binary Tree.
The doubly linked list should be returned by taking the next pointer as right and the previous pointer as left.
You need to return the head of the Doubly Linked List.
Note:
You are not required to print the expected output, and it has already been taken care of. Just implement the function.
Sample Input 1 :

2
3 1 5 -1 2 -1 -1 -1 -1
9 6 10 4 7 -1 11 -1 -1 -1 -1 -1 -1

Sample Output 1 :

1 2 3 5
4 6 7 9 10 11

Explanation of Input 1 :

Here we have 2 test cases; hence there are 2 binary trees.

Test Case 1 :

We can see that the inorder traversal of the given tree is: 1 2 3 5.


Test Case 2 :

We can see that the inorder traversal of the given tree is: 4 6 7 9 10 11.

Sample Input 2 :

2
4 6 -1 5 -2 -1 -1 -1 -1
1 2 3 4 4 -1 4 -1 -1 -1 -1 -1 -1

Sample Output 2 :

5 6 -2 4
4 2 4 1 3 4
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

void solve(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prev, BinaryTreeNode<int> *&head, int &count)
{
    // Simple Inorder
    if (!root)
        return; // root is NULL, return

    // go left
    solve(root->left, prev, head, count);

    // solve
    if (count == 0)
    {
        // first node
        head = root;
        prev = root;
        count = 1;
    }
    else
    {
        // not the first node so change pointers
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    // go right
    solve(root->right, prev, head, count);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // We know a doubly LinkedList has a (data,next,prev)
    // next should point to next node of Inorder
    // prev should point to previous node of Inorder
    // We simply do a inorder traversal
    // we take a prev and head both NULL initially
    // we take a variable count = 0, which checks if we come on first node of inorder
    // we point head and prev to that root, that node will be our head of DLL
    // now next next of Inorder comes, we set pointers
    // we do prev and head which are at first node of Inorder
    // prev->right = root (root is currently at second node of Inorder)
    // prev->right->left = prev (means prev point of root should point of previous node in Inorder)
    // move previous, prev = prev->right or prev = root, as head will remain there because we need to return head of DLL formed
    // TC: O(n), SC: O(height of tree)
    BinaryTreeNode<int> *head = NULL;
    BinaryTreeNode<int> *prev = NULL;
    int count = 0;
    solve(root, prev, head, count);
    return head;
}

int main()
{
    return 0;
}
