#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Find intersection of Two Linked Lists

Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.

Example 2:
Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null
Explanation: Here, both lists do not intersect and thus no intersection node is present.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Brute force approach
    // Common intersection point means any common attribute between 2 lists
    // It can be node value but node value is can be repeated so it cannot give us first intersection properly
    // We will use actual node for this purpose
    // We will use each node of second list and start iterating first list and check for that node in first list
    // if found, return else iterate till end and return NULL
    if (headA == NULL || headB == NULL)
    {
        // No intersection point
        return NULL;
    }

    while (headB != NULL)
    {
        ListNode *temp = headA;
        while (temp != NULL)
        {
            if (temp == headB)
            {
                return headB;
            }
            temp = temp->next;
        }
        headB = headB->next;
    }

    return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Optimised approach
    // We can use a set, in which we store the nodes
    // set stores only unique values
    // we do not need them to be sorted so we can use unordered_set
    // We store all values of list1 in set
    // now we traverse list2 and check if any node already found in set return it
    // else after iteration ends, return NULL
    unordered_set<ListNode *> st;

    while (headA != NULL)
    {
        st.insert(headA);
        headA = headA->next;
    }

    while (headB != NULL)
    {
        if (st.find(headB) != st.end())
        {
            return headB;
        }
        headB = headB->next;
    }

    return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // More optimal approach
    // We have 2 dummy nodes, d1 at l1 head and d2 at l2 head
    // We move both pointers together in l1 and l2 resp
    // if l1 becomes NULL, we take it to headB and continue iterating
    // if l2 becomes NULL, we take it to headA and continue iteration
    // What this does is, it reduces the differences between length of both lists and at the end, both dummy nodes are at same nodes of both list
    // So if there is no intersection, thet both points to NULL,otherwise both points to intersection point

    ListNode *dummy1 = headA;
    ListNode *dummy2 = headB;

    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    while (dummy1 != dummy2)
    {
        dummy1 = dummy1 == NULL ? headB : dummy1 = dummy1->next;
        dummy2 = dummy2 == NULL ? headA : dummy2 = dummy2->next;
    }

    return dummy1; // or dummy2;
}

int main()
{
    return 0;
}