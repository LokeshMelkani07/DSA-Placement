#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Add two numbers represented as Linked Lists

Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:

Input Format:
(Pointer/Access to the head of the two linked lists)

num1  = 243, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or original number and then add them as → 342 + 465 = 807.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // There is no Brute force to this problem
    // we take a dummy node poinitng 0 which is fixed and where dummy->next will point to head of resultant list
    // We take a temp node pointing to dummy, which is not fixed
    // We take l1,l2 as head of list 1 and list 2 resp
    // we take sum = 0, carry = 0
    // for first iteration we check if l1 != null and l2 != null
    // if yes then add l1->val + l2-> val and store in sum
    // To get carry do sum % 10 = last digit which becomes a node in resultant LL
    // To get carry do sum/10 = carry
    // Now move temp = temp->next
    // Do sum = 0 again now start again l1->val + l2-> val + carry and so on till any one become null from l1 and l2 or carry is NULL
    // TC: O(max(length of l1,length of l2)) because we had to travel one of them once completely
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;
        temp->next = newNode;
        temp = temp->next;
    }

    // dummy->next has head of result LL
    return dummy->next;
}

int main()
{
    return 0;
}