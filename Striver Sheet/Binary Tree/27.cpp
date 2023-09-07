#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Children Sum Property
Return true if all non-leaf nodes in a given binary tree have a value that is equal to the sum of their child nodes, otherwise return false..
Sample Input 1:

4
5 3 2 3 -1 -1 -1 -1 -1

Sample Output 1:

true

Explanation Of Sample Input 1:

Node 1: The sum of its child nodes is 3 + 2 = 5, which is equal to its value.
Node 2: The sum of its child nodes is 3, which is equal to its value.
Node 3: It is a leaf node with no child nodes, so the condition is satisfied.
Node 4: It is a leaf node with no child nodes, so the condition is satisfied.

Sample Input 2:

6
7 3 4 3 -1 2 3 -1 -1 -1 -1 -1 -1

Sample Output 2:

false

Explanation Of Sample Input 2:

Node 1: The sum of its child nodes is 3 + 4 = 7, which is equal to its value.
Node 2: The sum of its child nodes is 3, which is equal to its value.
Node 3: The sum of its child nodes is 2 + 3 = 5, which is not equal to its value 4, so the condition is not satisfied. Hence the answer is false
*/

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void isParentSum1(Node *root)
{
    // if Question was like to make a BT from the given BT which follows Chilren sum property by increasing the values by atleast 1
    // Chilren sum property means node value = left child value + right child value
    /*
                   40
                 /    \
                10     20
               /  \   /  \
              2    5 30  40
    is our tree
    */
    // What we do is we are standing at root, we go to root->left and root->right we check value
    // root ka left = 10 and root right = 20 so 10+20 = 30 != 40 and is <40
    // so make root->left and root->right = 40
    // now we go to root->left i.e 10 which is 40 now
    // we check 40->left = 2 and 40->right = 5 so 2+5<40
    // make them also 40 each so now we go to 10->left
    // we are at 2 which is now 40, its left and right is NULL so we come back
    // we go to 10->right i.e 5 which is now 40
    // again NULL we come back now 40+40 = 80 so we update 10 vala node as 80
    // now we go to root->right and do the same
    // This was we make a BT which follows Chilren sum property
    // 🥥 if both children sum is less than parent, make children's value to parent's value.
    // 🥥 if both children values sum is greater than or equal to parent, make parent's value to children's sum.
    // 🥥 recursively go left and right. Traversal type: DFS.
    // 🥥 when coming back up the tree, take children sum and replace it in parent.
    // 🥥 at any point we reach null, just return (base case)
    // 🥥 Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.

    // if root is NULL return
    if (root == NULL)
        return;
    // child variable is to do sum of children value and compare with root ki value
    int child = 0;
    if (root->left)
    {
        // add left child ki value
        child += root->left->data;
    }
    if (root->right)
    {
        // add right child ki value
        child += root->right->data;
    }

    // if both children ke sum ki value is greater than root ki value then update root ki value
    if (child >= root->data)
        root->data = child;
    else
    {
        // if we are in else-block means root ki value is bigger than children ke sum ki value
        // if root->left exist krta h toh uski value equal to root ki value krdo and root->right ka bhi same hi krdo
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    // children ki value root ke equal krdi toh ab left child pe jao and same krdo
    isParentSum1(root->left);
    // left se aagye toh ab right child ke jaake same krdo
    isParentSum1(root->right);

    // ab vapas parent ke paas aane se phele check krdo ki bacho ke sum ki value equal to parent hai ya nahi?
    // if nhi h toh parent ki value equal to sum of left child + right child krdo
    // uss kaam ke lie, we will use total variable
    int total = 0;
    // left child exist karta hai toh value bhardo total mai and same with right
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    // if left child ya right child leaf node nahi h toh root ki value modify krdo
    if (root->left || root->right)
        root->data = total;
}

bool isParentSum(Node *root)
{
    // Original Question: If the BT follows Children Sum property return true, if not return false
    if (!root)
    {
        return true; // An empty tree satisfies the condition.
    }

    if (!root->left && !root->right)
    {
        return true; // Leaf nodes always satisfy the condition.
    }

    int leftValue = root->left ? root->left->data : 0;
    int rightValue = root->right ? root->right->data : 0;

    if (root->data != leftValue + rightValue)
    {
        return false; // Condition not satisfied for the current node.
    }

    // Recursively check the left and right subtrees.
    return isParentSum(root->left) && isParentSum(root->right);
}

int main()
{
    return 0;
}