#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Implement Queue Using Array

Problem Statement: Implement Queue Data Structure using Array with all functions like pop, push, top, size, etc.

Example:

Input: push(4)
       push(14)
       push(24)
       push(34)
       top()
       size()
       pop()

Output:

The element pushed is 4
The element pushed is 14
The element pushed is 24
The element pushed is 34
The peek of the queue before deleting any element 4
The size of the queue before deletion 4
The first element to be deleted 4
The peek of the queue after deleting an element 14
The size of the queue after deleting an element 3
*/

class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (rear >= 100001)
        {
            return;
        }
        arr[rear] = e;
        rear++;
        return;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear)
            return -1;
        int ans = arr[front];
        arr[front] = -1;
        front++;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return ans;
    }
};

int main()
{
    return 0;
}