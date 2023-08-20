#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/*
Detect a Cycle in a Linked List
Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

Return true if there is a cycle in the linked list. Otherwise, return false.

Examples:

Example 1:
Input:
 Head = [1,2,3,4]
Output:
 true
Explanation: Here, we can see that we can reach node at position 1 again by following the next pointer. Thus, we return true for this case.

Example 2:
Input:
 Head = [1,2,3,4]
Output:
 false
Explanation: Neither of the nodes present in the given list can be visited again by following the next pointer. Hence, no loop exists. Thus, we return false.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{
    // Brute force
    // We can make use of hashing
    // we will use unordered_set
    // we will traverse whole list1 till NULL
    // everytime we check that node in set. if found we return true
    // if not yet, then insert in set and move pointer->next
    // if loop ends we are out, return false
    // TC: O(n), SC: O(n)
    unordered_set<ListNode *> st;
    while (head != NULL)
    {
        if (st.find(head) != st.end())
        {
            return true;
        }
        st.insert(head);
        head = head->next;
    }

    return false;
}

bool hasCycle(ListNode *head)
{
    // Optimal approach
    // we will use a fast and slow pointer
    // both start at head, fast moves 2 steps forward, slow moves 1 step forwards
    // Till the end of the list, if both collide once means cycle detected
    // if not, then cycle not present
    // TC: O(n), SC:O(1) now we do not use any set or map now
    ListNode *fast = head;
    ListNode *slow = head;

    // edge case
    if (head == NULL)
    {
        return false;
    }

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}