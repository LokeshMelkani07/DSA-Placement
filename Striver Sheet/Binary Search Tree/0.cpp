#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:

Input: root = []
Output: []
*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    // What we will do is we will make use of Level Order Traversal
    // We will pick our node from queue everytime and pop it from queue and check if there is something in q.front() then put node->next = q.front()
    // if there is no element in queue means size==1 put node->next = NULL
    // now if node->left exists, then store in queue
    // if node->right exists, store in queue
    if (root == NULL)
        return NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz)
        {
            Node *node = q.front();
            q.pop();
            if (sz == 1)
            {
                node->next = NULL;
            }
            else
            {
                node->next = q.front();
            }
            sz--;
            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    return root;
}

int main()
{
    return 0;
}