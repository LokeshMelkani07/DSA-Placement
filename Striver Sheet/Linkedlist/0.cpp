#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Reverse a Linked List

Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples:

Input Format:
head = [3,6,8,10]
This means the given linked list is 3->6->8->10 with head pointer at node 3.

Result:
Output = [10,6,8,3]
This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    // we will use the approach of 3 pointer, one pointing to head, a dummy node pointing to NULL initially, nextNode pointer pointing to head->next
    // In each iteration we change head->next = dummy, dummy = head, head = nextNode, nextNode = nextNode->next
    // We do this till head != NULL
    // At the end, dummy node is head of reversed linkedlist
    if (head == NULL)
        return NULL;
    ListNode *slow = NULL;
    ListNode *fast = head;
    ListNode *fastest = head->next;
    while (fast != NULL)
    {
        fast->next = slow;
        slow = fast;
        fast = fastest;
        if (fastest != NULL)
            fastest = fastest->next;
    }
    return slow;
}

ListNode *reverseList1(ListNode *&head)
{
    // Recursive approach

    if (head == NULL || head->next == NULL)
        return head;

    ListNode *nnode = reverseList1(head->next);
    // Let say LL is like 1->2->3->4->NULL, head is 1
    // Below statement says head->next->next means 2->next = head i.e 1
    head->next->next = head;
    // head->next means the last node of reversed LL i.e 1 ka next = NULL
    head->next = NULL;
    return nnode;
}

int main()
{
    return 0;
}
