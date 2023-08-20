#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Reverse Linked List in groups of Size K

Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Examples:
Example 1:
Input:
 head = [1,2,3,4,5,6,7,8] k=3, 1->2->3->4->5->6->7->8
 means 1,2,3 are group of 3 (reverse them in itself), 4,5,6 are group of 3 (reverse them in itself) and 7,8 are group of 2 so leave them as it is
Output:
 head = [3,2,1,6,5,4,7,8]
 3->2->1->6->5->4->7->8

Example 2:
Input:
 head = [1,2,3,4,5,6,7,8] k=2
Output:
 head = [2,1,4,3,6,5,8,7]
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    // Refer to the video, its a complex problem: https://youtu.be/Of0HPkk3JgI
    // We create a dummy node and pre node
    // dummy -> next = head and we do not move dummy
    // we create curr, nex which are at dummy initially
    // TC : O(n/k*k) = o(n)
    // SC : O(1)
    if (head == NULL || k == 1)
    {
        return head;
    }
    // Making a dummy node
    ListNode *dummy = new ListNode(0);
    // Pointing dummy node->next to head
    dummy->next = head;
    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    // First count the number of nodes in the LL
    int count = 0;
    while (cur->next != NULL)
    {
        // count has the number of nodes
        count++;
        cur = cur->next;
    }
    // now till count>=k means we are able to make group of k, reverse node in group of k
    while (count >= k)
    {
        // cur should be pointing at first node of 'K' group of nodes initially
        cur = pre->next;
        // nex should be pointing at second node of 'K' group of node i.e cur->next
        nex = cur->next;
        // Make k-1 iterations to fix the links that is if k=3 means we have ti0change only 2 links
        for (int i = 1; i < k; i++)
        {
            // Use pen paper to understand this on given example 1
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        // At the end first 'k' group is done, move pre to cur and look for next group
        pre = cur;
        // Reduce count by that many nodes
        count -= k;
    }

    // dummy->next will point to head of new LL
    return dummy->next;
}

int main()
{
    return 0;
}