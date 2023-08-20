#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Flattening a Linked List

Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

(i) a next pointer to the next node,

(ii) a bottom pointer to a linked list where this node is head.

Each of the sub-linked-list is in sorted order.

Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every
node in a single level.
(Note: | represents the bottom pointer.)


Input:
5 -> 10 -> 19 -> 28
|          |
7          22
|          |
8          50
|
30
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
*/

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr){};
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child){};
};

Node *mergeLL(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }

    // if anyone of the list is left, just append it jaise ke taisa to teh temp
    if (a)
    {
        temp->child = a;
    }
    else
    {
        temp->child = b;
    }

    return res->child;
}

Node *flattenLinkedList(Node *head)
{
    // Optimal approach
    // We will take last 2 LL i.e let say we have L1->L2->L3->L4 and L1,L2,L3,L4 has some sub-LL at their child as well
    // We use recursion and move to L3 and L4
    // we create a merge function that gives root of merged LL
    // Now we merge L3 and L4 into single LL say L5
    // Now we merge L2 and L5 into single say L6
    // Merge L1 and L6 into single LL say L7 and we get final answer as root of flattened LL
    if (head == NULL || head->next == NULL)
    {
        // move till last LL
        return head;
    }

    // Put merged LL to next to root
    head->next = flattenLinkedList(head->next);

    // merge them into single and return their head
    head = mergeLL(head, head->next);

    // return the final head
    return head;
}

int main()
{
    return 0;
}