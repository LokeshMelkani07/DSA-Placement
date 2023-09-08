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
Serialize and Deserialize Binary Tree
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // TC : O(n)  SC : O(n)
    // Serialise means convert tree to string or a file
    // De-Serialise means convert the string back to tree or read back from the file
    // We are using Level Order here
    string serialize(TreeNode *root)
    {
        // Just do simple level order
        // if there is NULL, push # in the string
        if (!root)
            return "";

        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode == NULL)
                s.append("#,");
            else
                s.append(to_string(curNode->val) + ',');
            if (curNode != NULL)
            {
                // don't check if left and right are NULL because we need NULL values also this time so just push them
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // StringStream convert the string to object so we can read the characters from the string using getline
        if (data.size() == 0)
            return NULL;

        // stringstream s(data);

        string str;
        // everytime we do getline, it picks up a character using (,) as delimeter and store into str

        // getline(s, str, ','); // pick one character

        // everytime we do getline then stream s reads a character from string str considering ',' as a decimeter
        // Everytime we pick a element till we encounter comma (,) we make a node
        // we push it in stack
        // now we pick stack top and pop it, go to left, make a node push it in stack
        // now we go to stack top ka right, do the same
        // now pick again stack top i.e prev top ka right will come and do the same
        TreeNode *root = new TreeNode(stoi(str)); // make node of that previously picked character
        // stoi() is a standard library function that turns a string into an integer
        queue<TreeNode *> q;
        q.push(root); // push that character in queue
        while (!q.empty())
        {

            // take out front element
            TreeNode *node = q.front();
            q.pop();

            // pick next character from string

            // getline(s, str, ',');

            // if that character is # means its NULL so
            if (str == "#")
            {
                // make node->left as NULL
                node->left = NULL;
            }
            else
            {
                // else its a character so make a new node
                TreeNode *leftNode = new TreeNode(stoi(str));
                // put new node in left
                node->left = leftNode;
                // push new node into stack
                q.push(leftNode);
            }

            // everytime we do getline then stream s reads a character from string str considering ',' as a decimeter
            // sameway do for node->right
            // getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        // At the end return root of tree formed
        return root;
    }
};

int main()
{
    return 0;
}