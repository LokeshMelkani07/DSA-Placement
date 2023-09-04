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

int main()
{
    return 0;
}