#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    // Brute force
    // We will use a unordered_map of<node*,node*> and for each node in LL, we create its copy and store in map
    // We do not a assign anything for now, no next and random
    // In first traversal we just store copy of nodes in map
    // In second traversal, we take each node from map say ori1 is orignial 1 node, copy1 is copy of 1 node
    // we check next and random of ori1, we see next points to ori2 and random points to ori4
    // we assign copy1 ka next to copy2 and random of copy1 to copy4
    // Do till end of LL, if their is next and random means its NULL so assign accordingly
    // TC: O(n)+O(n), SC: O(n)
    unordered_map<Node *, Node *> mpp;

    // 1st iteration
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    Node *t = head;
    while (t != NULL)
    {
        // Assign node to its copy from map
        Node *node = mpp[t];
        // node->next become original ka next if its not NULL else its NULL
        node->next = (t->next != NULL) ? mpp[t->next] : NULL;
        // node->random become original ka random if its not NULL else its NULL
        node->random = (t->random != NULL) ? mpp[t->random] : NULL;
        t = t->next;
    }

    // Head of copy of ori head
    return mpp[head];
}

Node *copyRandomList(Node *head)
{
    // Optimised approach
    // Now we do not store copies in a map
    // Instead, we simulataneously add copy after the orignial node
    // Say 1ori-> 1copy->2ori->2copy->3ori->3copy->NULL
    // for that we first assign 1ori->next = 1copy
    // 1copy->next = 2ori
    // we go on doing this
    // In the next step now, we point random
    // we use a iter = head, iter->next->random = iter->random->next
    // now move iter and go on doing this
    // Now we need to seperate original and copy LL
    // We make a dummy node(0) and iter at head i.e 1ori and front which will be 2 step ahead iter initially at 2ori
    // TC: O(n)+O(n)+O(n) = o(n), TC: O(1)

    Node *temp = head;
    // step 1: make copy
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // step 2: assign random
    Node *itr = head;
    while (itr != NULL)
    {
        if (itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
    // step 3: seperate both lists
    Node *dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
}

int main()
{
    return 0;
}