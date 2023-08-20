#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/*
Starting point of loop in a Linked List

Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Examples:

Example 1:
Input:
 head = [1,2,3,4,3,6,10]
Output:
tail connects to node index 2


Example 2:
Input:
 head = [1,2]
Output:
 no cycle

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head)
{
    // Brute force
    // Using hashing
    // We store all the nodes in the hashmap
    // While stroing we check if it already exits in the hashset
    // if yes, then that is our head of cycle
    // if we reach null means there is not cycle so return NULL
    // TC: O(N), SC:O(N)
    unordered_set<ListNode *> mpp;
    while (head != NULL)
    {
        if (mpp.find(head) != mpp.end())
        {
            return head;
        }
        mpp.insert(head);
        head = head->next;
    }

    return NULL;
}

ListNode *detectCycle(ListNode *head)
{
    // Optimised approach
    // TC: O(N), SC: O(1)
    // We will make use of slow, fast, entry pointer. all pointing to head initially
    // We first find collisiion point using slow anf fast
    // move slow by 1 and fast by 2 unit till fast-> next or fast->next->next != NULL
    // if it becomes NULL means there is no cycle return NULL
    // if not then we get collision point where slow==fast
    // from that point move slow and entry till slow != entry
    // return entry

    // edge case
    if (head == NULL || head->next == NULL)
    {
        // no cycle
        return NULL;
    }

    ListNode *entry = head;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // collision point found
        {
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // or slow
        }
    }

    return NULL;
}

int main()
{
    return 0;
}