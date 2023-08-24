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
Implement Queue using Stack

Problem Statement: Given a Stack having some elements stored in it. Can you implement a
Queue using the given Stack?

Queue: A Queue is a linear data structure that works on the basis of FIFO(First in First out). This means the element added at first will be removed first from the Queue.
*/

class Queue
{
    // We will use 2 stacks
    stack<int> input;
    stack<int> output;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        input.push(val);
    }

    int deQueue()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
            return -1;

        int num = output.top();
        output.pop();
        return num;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
            return -1;

        return output.top();
    }

    bool isEmpty()
    {
        return output.empty() && input.empty();
    }
};

int main()
{
    return 0;
}