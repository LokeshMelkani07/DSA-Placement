#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Check if given Linked List is Plaindrome

Check if the given Linked List is Palindrome

Problem Statement: Given the head of a singly linked list, return true if it is a palindrome.

Examples:

Example 1:
Input: head = [1,2,3,3,2,1]
Output:
 true
Explanation: If we read elements from left to right, we get [1,2,3,3,2,1]. When we read elements from right to left, we get [1,2,3,3,2,1]. Both ways list remains same and hence, the given linked list is palindrome.

Example 2:
Input:
 head = [1,2]
Output:
 false
Explanation: When we read elements from left to right, we get [1,2]. Reading from right to left, we get a list as [2,1]. Both are different and hence, the given linked list is not palindrome.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    // Brute force
    // TC: O(n), SC: O(n)
    // Store all node values in an Data structure, say array
    // Now check if that array is an palindrome or not

    vector<int> arr;

    while (head != NULL)
    {
        arr.push_back(head->val);
        head = head->next;
    }

    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return false;
        }
    }

    return true;
}

// Optmised approach
ListNode *reversedList(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *nex = NULL;
    while (head != NULL)
    {
        nex = head->next;
        head->next = pre;
        pre = head;
        head = nex;
    }
    // head of reversed list
    return pre;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // middle node
    return slow;
}

bool isPalindrome(ListNode *head)
{
    // Optmised approach
    // We will first find the middle of the LL using slow and fast pointer
    // We will reverse the LL from middle->next vala node
    // We put dummy pointer to head of LL
    // we put one pointer say slow at head of reversed LL
    // we check if slow==dummy we move both ahead
    // if till slow==NULL, both slow==dummy means its a palindrome else not
    // TC: O(N/2) + O(N/2) + O(N/2) to find middle,reverse that middle and check palindrome
    // SC: O(1)
    ListNode *dummy = head;
    ListNode *middle = middleNode(head);
    ListNode *reversedHead = reversedList(middle->next);

    while (reversedHead != NULL)
    {
        if (dummy->val == reversedHead->val)
        {
            dummy = dummy->next;
            reversedHead = reversedHead->next;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}