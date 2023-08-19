#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Delete given node in a Linked List : O(1) approach

Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

Examples:

Example 1:
Input:
 Linked list: [1,4,2,3]
       Node = 2
Output:
Linked list: [1,4,3]
Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].

Example 2:
Input:
 Linked list: [1,2,3,4]
       Node = 1
Output: Linked list: [2,3,4]
Explanation:
 Access is given to node 1. After deleting nodes, the linked list will be modified to [2,3,4].
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNode(ListNode *node)
{
    // Just copy value of node->next in the node
    // points node->val = node->next->val
    // node->next = node->next->next
    // this is the answer
    // we can also check if node->next->next is NULL in that case, we assign node->next->next = NULL
    if (node->next == NULL)
    {
        delete node;
    }
    swap(node->val, node->next->val); // as we are directly given address of node to be deleted not given head node
    ListNode *temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main()
{
    return 0;
}