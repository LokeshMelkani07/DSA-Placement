#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

/*
Vertical Order Traversal of a Binary Tree
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.



Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
*/

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<vector<int>> verticalOrderTraversal(TreeNode<int> *root)
{
    // We will make vertical line from root
    // In left we do lineNumber - 1
    // In right we do lineNumber + 1
    // We will also give each node a level in horizontal like level 0 for root node
    // level 1 for next level of node and so on
    // if 2 nodes are overlapping we need to store one with smaller value first and then the bigger value
    // 2 nodes can have same value so we need to keep this in mind also
    // we will use a queue to store <node,vertical level, horizontal level> for each node
    // To get element order we use map<int (for vertical order) , map<int (for horizontal level), multiset<int> (for list of elemens in order keeping in mind for duplicate value cases)>>
    // Now taking the first element store it in queue and map
    // Now just do level order traversal, move to its left and store in queue and map
    // Not move to right and do the same
    // now get the top element of queue and perform the same
    // on moving left, vertical order get --, hori order inc by 1
    // on moving right, vertical order get ++, hori order inc by 1
    // TC: O(n), SC: O(n)
    map<int, map<int, multiset<int>>> mpp;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *cur = it.first;
        int vertical = it.second.first;
        int horizontal = it.second.second;
        mpp[vertical][horizontal].insert(cur->data);

        if (cur->left != NULL)
        {
            q.push({cur->left, {vertical - 1, horizontal + 1}});
        }

        if (cur->right != NULL)
        {
            q.push({cur->right, {vertical + 1, horizontal + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto it : mpp)
    {
        vector<int> col;
        for (auto x : it.second)
        {
            col.insert(col.end(), x.second.begin(), x.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main()
{
    return 0;
}
