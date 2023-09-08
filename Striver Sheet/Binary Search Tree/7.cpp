#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Floor in BST
You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST  which is smaller than or equal to  ‘X’.
Note :‘X’ is not smaller than the smallest node of BST .
Sample Input 1:

2
10 5 15 2 6 -1 -1 -1 -1 -1 -1
7
2 1 3 -1 -1 -1 -1
2

Sample Output 1:

6
2

Explanation of Sample Input 1:

In the first test case, the BST looks like as below:

The greatest value node of the BST which is smaller than or equal to  7 is 6.

In the second test case, the BST looks like as below:

The greatest value node of the BST which is smaller than or equal to  2 is 2.

Sample Input 2:

2
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
15
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
8

Sample Output 2:

15
6
*/

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    // We will make use of a simple property of BST that
    // Everything on left of a node in BST is smaller than node
    // Everything on right of a node in BST is greater than node
    // We see key and start searching in the BST
    // if key is greater we go to right of node but we make sure to store the value in a variable as this can be our possible answer
    // if key is smaller we go to left of node
    // we do this till root != NULL
    int floor = -1;
    while (root)
    {
        if (root->val == X)
        {
            floor = root->val;
            return floor;
        }

        if (X > root->val)
        {
            // we need  a value <= X so we store this answer as it can be a possible one
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}

int main()
{
    return 0;
}
