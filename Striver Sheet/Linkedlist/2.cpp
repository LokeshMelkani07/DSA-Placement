#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Merge two sorted Linked Lists

Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}

Output :
{1,2,3,5,7,8,10,10}
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    // Recursive Approach
    // if l1 is NULL means we only have l2 so return it and vice-versa
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    // if value of l1 is smaller than l2
    if (l1->val < l2->val)
    {
        // we will include l1 in our answer and we call merge(l1->next,l2) by saying that, mai l1 use kar rha hu, recrusion tum l1->next se leke and l2 tak ek sorted list laake dedo and l1->next jo maine choose kra tha usme append krdo
        l1->next = merge(l1->next, l2);
        // return l1 at the end
        return l1;
    }
    else
    {
        // else, same case with l2
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    return merge(list1, list2);
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // Optmised approach
    // we can use a dummy node with value -1 or 0
    // we use another node which will travel the list called tail
    // till list1 is not NULL or list2 is not NULL
    // add tail->next to smaller value and move tail to list and move list to its next
    ListNode *ans = new ListNode(-1);
    ListNode *tail = ans;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        // if(list1->val > list2->val)
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    // if list1 is NULL means list2 is yet to be finished
    if (list1 == NULL)
    {
        tail->next = list2;
    }
    else
    {
        // else list2 is NULL means list1 is yet to be finished
        tail->next = list1;
    }

    // At the end ans->next has the head of sorted list
    return ans->next;
}

int main()
{
    return 0;
}