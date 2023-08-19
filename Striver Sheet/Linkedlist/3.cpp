#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Remove N-th node from the end of a Linked List

Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

Example 1 :

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [7,6,9,4,13,2,8], n = 6
Output: [7,9,4,13,2,8]
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Naive Approach
    // TC: O(2n), SC: O(1)
    // We will take a dummy node at head and travel entire LL to calculate number of nodes let say its k
    // Now we do n-k = x (say) so we need to delete the next node to x in the linkedlist
    // We take another node temp = head and move till x,
    // now delNode = temp->next;
    // temp->next = temp->next->next
    // delete(delNode)
    // But there is edge case, what if n = K i.e we have to delete the first node
    // In that case just do temp= head->next;
    // delete(head);
    ListNode *dummy = head;
    ListNode *temp = head;
    int k = 0;
    while (dummy != NULL)
    {
        k++;
        dummy = dummy->next;
    }

    // edge case
    if (n == k)
    {
        // delete head
        head = head->next;
        return head;
    }
    int x = k - n;
    int cnt = 1;

    while (cnt != x)
    {
        temp = temp->next;
        cnt++;
    }

    ListNode *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);

    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Optmised approach
    // TC: O(n), SC: O(1)
    // We make a dummy node pointing its next to the head
    // We make a slow and fast pointer both at dummy initially
    // We move fast pointer to n steps forward
    // Now we move both slow and fast pointer by 1 step each till fast->next != NULL or fast is not at the last node
    // Now our slow pointer is standing at node, whose next node is to be deleted
    // So slow->next = slow->next->next and return dummy->next as answer
    // This automatically handles our edge case also
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    int cnt = 0;
    while (cnt != n)
    {
        fast = fast->next;
        cnt++;
    }

    // Now move both fast and slow
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *delNode = slow->next;
    // In C++ execution is always from Left to Right
    slow->next = slow->next->next;
    delete (delNode);

    return dummy->next;
}

int main()
{
    return 0;
}