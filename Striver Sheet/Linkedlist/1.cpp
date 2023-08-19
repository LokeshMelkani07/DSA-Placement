#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    // Naive Approach
    // we will travserse the LL for first time and keep track of all number of nodes say n
    // we again traverse whole LL but this time only for n/2 times and get the middle node
    ListNode *temp = head;
    int n = 0;
    while (temp)
    {
        // Get the count
        n++;
        temp = temp->next;
    }

    temp = head;
    for (int i = 1; i <= n / 2; i++)
    {
        temp = temp->next;
    }

    // At the end, temp is at middle node
    return temp;
}

ListNode *middleNode(ListNode *head)
{
    // Tortoise-Hare-Approach
    // Optimised approach
    // we will make use of 2 pointers, slow and fast
    // slow move by one step and fast move by 2 steps
    // we do this till our fast and fast->next are not NULL
    // at the end our slow will be at the middle node of the Linkedlist
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}