#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
K-th largest Number BST
You are given a binary search tree of integers with 'N' nodes. Your task is to return the K-th largest element of this BST.
If there is no K-th largest element in the BST, return -1.
A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

Sample Input 1 :

2
3
3 1 5 -1 2 -1 6 -1 -1 -1 -1
2
2 1 -1 -1 -1

Sample Output 1:

3
1

Explanation for Sample 1:

Test Case 1:
The sorted array corresponding to the first test case will be [1, 2, 3, 5, 6]. The 3rd largest element will be 3.

Test Case 2:
The sorted array corresponding to the second test case will be [1, 2]. The 2nd largest element will be 1.

Sample Input 2 :

1
5
10 -1 20 -1 30 -1 40 -1 -1

Sample Output 2:

-1
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

void rec(TreeNode<int> *root, int &k, int &cnt, int &ans)
{
    if (root == NULL)
        return;
    rec(root->right, k, cnt, ans);
    cnt++;
    if (cnt == k)
        ans = root->data;
    rec(root->left, k, cnt, ans);
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    // if normal inorder gives us sorted array (ascending order)
    // then reverse inorder will give us sorted array in descending order
    // so we take a count variable to store the count and a ans variable to store answer
    // if count = k, we have the kth largest element so ans = root->data
    int ans = -1;
    int cnt = 0;
    rec(root, k, cnt, ans);
    return ans;
}

int main()
{
    return 0;
}