#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// Preorder Traversal using Morris Traversal

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void MoorisPreorder(TreeNode *node, vector<int> &ans)
{
    TreeNode *cur = node;
    // we will stop when our cur points to NULL
    while (cur != NULL)
    {
        // first case, check left if not present then print and move to right
        if (cur->left == NULL)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            // cur ka left is not null so go to right most of left subtree
            TreeNode *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }

            // When we reach the righest of node of left subtree
            // There exists 2 cases
            // Either, rightest node points to NULL
            if (temp->right == NULL)
            {
                // In this case make a thread
                temp->right = cur;
                // While we are making the thread, we are at the cur so before going to left, store cur
                ans.push_back(cur->data);
                // and move cur to its left
                cur = cur->left;
            }
            else
            {
                // Rightest points to cur already,remove it and store cur->data and go to right node
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Morris PreOrder Traversal
    // PreOrder is root left right
    // Difference between normal Preorder and Morris Preorder Traversal is
    // Normal Traversal takes O(n) TC and O(n) SC
    // Whereas Morris takes O(n) TC but O(1) SC
    // It uses Threaded Binary tree
    // In-order Morris Traversal:
    // Check these 3 cases for Morris Inorder Traversal
    // 🌳 1st case: if left is null, print current node and go right
    // 🌳 2nd case: before going left, make right most node on left subtree connected to current node so that there exist a thread using which we can come directly to current node after a successful traversal of left subtree, print the cur node then go left
    // 🌳 3rd case: if thread is already pointed to current node or if there already exists a thread means we ahev visited that arena, then remove the thread and go to right of current node
    vector<int> ans;
    MoorisPreorder(root, ans);
    return ans;
}

int main()
{
    return 0;
}