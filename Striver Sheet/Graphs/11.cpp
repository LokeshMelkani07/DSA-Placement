#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Example 1:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
*/

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node *node, Node *newNode, vector<Node *> &vis)
{
    // mark the node as visited
    vis[newNode->val] = newNode;
    // go to its neightbours
    for (auto it : node->neighbors)
    {
        if (vis[it->val] == NULL)
        {
            // make a new Node
            Node *copy = new Node(it->val);
            // means they are not visited so make a copy of them
            (newNode->neighbors).push_back(copy);
            // call dfs for that new node
            dfs(it, copy, vis);
        }
        else
        {
            // its already visited so copy value in neighbor of newNode
            (newNode->neighbors).push_back(vis[it->val]);
        }
    }
}

Node *cloneGraph(Node *node)
{
    // what we need to do here is we need to clone the graph, do not copy everything
    // just the pos and structure should be same
    // we have a neighbour vector for each node in which we store its neighbour
    // we have to return head of the copied adj list

    // Hume kuch nhi kar rhe simple DFS hai, for ananlogy ori = original, copy = copied we need to make
    // hume ek Node class di hai, where we have val and list of neighbors inside every node
    // Hume adj list ko jaise ka taisa copy krna h
    // Hume root node diya hai ori node humne usse ek naya node bana liya called copy node
    // Hum ek visited array le rhe h jisme hum Nodes store krenge corresponding to each node->val as index of vector
    // Naya node banaya and uske liye dfs call krlia, now what we do in DFS?
    // mark node visited, visit its parents simple
    // humne node ko visited mark krlia
    // phir hum gye orig ke neighbours mai and check kiya agar neighbour visited nhi hai
    // phele make a new Node for our copy and add it in copy->neighbor make dfs call for that copied neighbour node
    // if neighbor phele se hi visited array mai marked hain means hume bas usko apni adj list of copied mai daalna hai so (newNode->neighbors).push_back(vis[it->val]);
    // we do push_back because neighbors is a member of class Node and is a list to store neighbors of a node
    // At the end return head of copied graph
    if (node == NULL)
        return NULL;
    // make a visited array which stors address of node for that index
    vector<Node *> vis(1000, NULL);
    // make a new Node
    Node *newNode = new Node(node->val);
    dfs(node, newNode, vis);
    return newNode;
}
int main()
{
    return 0;
}