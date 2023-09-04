#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
All Tree Traversals in one go
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.
Sample Input 1 :

1 2 3 -1 -1 -1  6 -1 -1

Sample Output 1 :

2 1 3 6
1 2 3 6
2 6 3 1

Explanation of Sample Output 1 :

 The given binary tree is shown below:

Inorder traversal of given tree = [2, 1, 3, 6]
Preorder traversal of given tree = [1, 2, 3, 6]
Postorder traversal of given tree = [2, 6, 3, 1]

Sample Input 2 :

1 2 4 5 3 -1 -1 -1 -1 -1 -1

Sample Output 2 :

5 2 3 1 4
1 2 5 3 4
5 3 2 4 1

Explanation of Sample Output 2 :

The given binary tree is shown below:

Inorder traversal of given tree = [5, 2, 3, 1, 4]
Preorder traversal of given tree = [1, 2, 5, 3, 4]
Postorder traversal of given tree = [5, 3, 2, 4, 1]
*/

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // We will use a stack to store node*,num
    // num will be having value 1,2,3
    // when we first insert a node in stack mark it num = 1
    // when we extract the stack top
    // if top is num = 1 then store it in preorder, increment 1->2 and check its left and if left exists, push node->left in stack with num = 1
    // num = 1 means we are traversing it for the first time
    // if top is num = 2 then store in Inorder, increment 2->3 and check its right and if right exists, push node->right in stack with num = 1
    // if top is num = 3 then store in postOrder and pop it out of stack completely
    // TC: O(3*n) as we traverse each element 3 times and SC is also O(3*n) for stack
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int> In;
    vector<int> post;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            In.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }

    ans.push_back(In);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}

int main()
{
    return 0;
}