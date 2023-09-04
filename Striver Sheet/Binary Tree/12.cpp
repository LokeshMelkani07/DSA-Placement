#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Maximum Width In Binary Tree
You have been given a Binary Tree of integers. You are supposed to return the maximum width of the given Binary Tree. The maximum width of the tree is the maximum width among all the levels of the given tree.
The width of one level is defined as the length between the leftmost and the rightmost, non-null nodes in the level, where the null nodes in between the leftmost and rightmost are excluded into length calculation.
Sample Input 1 :

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

Sample Output 1 :

3

Explanation of Sample Input 1 :

The maximum width will be at the third level with the length of 3, i.e. {4, 5, 6}.
Sample Input 2 :

2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1

Sample Output 2 :
3
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

int getMaxWidth(TreeNode<int> *root)
{
    // Number of nodes between first and last node of any level is its width (including first and last node)
    // if between any 2 nodes in a level, there are no right or left node for a particular node in previous level
    // we have to assume a node there also, because we need max width so we need to consider a full binary tree if we have a first and a last node in a level
    // Here we need to see for number of nodes between first and last node for each level
    // So, level order traversal can be used here
    // if we can do indexing in such a way that root has index=1, nevel level has index 2 and 3 (left to right) and so on
    // This way we have a tree whose each level is indexed, so get width for a particular level, we do (last index - first index + 1)
    // Indexing will be in such a way that
    // if we use (0-based indexing) then root has index = 0 say i, left = 2*i+1 and right = 2*i + 2
    // if we use (1-based indexing) then root has index = 1 say i, left = 2*i and right = 2*i+1 (intuition of formula: Segament tree, as each node has 2 children)
    // but if we take this way of indexing, In a skew tree, we might get overflow in worst case
    // so we need to take value of i in such a way that each level index start from 1,2,3,4,5....
    // So we need to modify our value of i in that way
    // i = i - min, where min = minimal index value in that level
    // left = 2*i+1 and right = 2*i+2
    // for level order we need a queue of pair<node,index> initally <root,0> as we start with index = 0
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        // min element in each level
        int mmin = q.front().second;
        // to store first and last index
        int first, last;

        // the below loop will run for each level once
        // say we are first at root, once we have stored the width for level of root
        // we pop it out and push root->left and root->right
        // now we run below loop for size = 2 for above 2 newly pushed elements
        // now we pop them out and store their left and right and so on
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front().first;
            // we do - mmin to avoid that overflow situation
            long index = q.front().second - mmin;
            q.pop();

            // for first node
            if (i == 0)
                first = index;
            // for last node
            if (i == size - 1)
                last = index;

            if (node->left)
                q.push({node->left, index * 2 + 1});
            if (node->right)
                q.push({node->right, index * 2 + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main()
{
    return 0;
}