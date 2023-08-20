#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Rotate a Linked List

Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

Examples:

Example 1:
Input:
    head = [1,2,3,4,5]
    k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.

Example 2:
Input:
    head = [1,2,3]
    k = 4
Output:
head = [3,1,2]
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    // Brute force approach Gives TLE
    // We will pick the end node of the linkedlist
    // for every k we pick end node and bring it to the first
    // We keep on doing this k times
    // return head of the rotated LL
    // TC: O(n*k) because we are traversing n times to reach end and we do it k times
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    for (int i = 0; i < k; i++)
    {
        ListNode *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        // till now temp is at second last node
        ListNode *end = temp->next; // end poiniting to end node now
        temp->next = NULL;          // mark second last node->next = NULL
        end->next = head;           // mark end->next to head means bring it to the front
        head = end;                 // make new node as head
    }

    return head; // return head
}

ListNode *rotateRight(ListNode *head, int k)
{
    // Optimised approach
    // In the previous solution if k is very large like 1000000 it gives TLE
    // There can be 2 cases either k<Length of LL or k>=length of LL
    // Let say Length of LL is 5, and k = 5 then after 5 roatations we get back the original LL
    // if K = multiple of 5, then also same answer
    // So if k = multiple of Length of LL then no need to rotate it
    // if Length of LL = 5, K = 12 then we can say in first 10 rotations we will get back same LL, so we just need to do extra 2 rotations
    // if k>=len, we can do k%10
    // Now algo starts
    // Traverse the length of LL, get the length
    // Point the end node->next to head
    // Now travel length-k nodes from head say we reach temp node now
    // Move head to temp->next
    // do temp->next = NULL and our job is done
    // TC: O(n), SC: O(1)

    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }

    // compute the length
    int len = 1;
    ListNode *cur = head;
    while (cur->next != NULL)
    {
        len++;
        cur = cur->next;
    }

    // Now we have the length
    cur->next = head;
    // say k = 12, len = 5
    k = k % len; // k = 2 as first 10 rotations are waste as 10 is multiple of 5
    k = len - k; // say k = 5 - 2 = 3 come to 3rd node

    while (k)
    {
        cur = cur->next;
        k--;
    }

    head = cur->next;
    cur->next = NULL;

    return head;
}

int main()
{
    return 0;
}
