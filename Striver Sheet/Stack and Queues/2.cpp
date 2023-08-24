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
Implement Stack using single Queue

Problem Statement: Implement a Stack using a single Queue.

Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

Note: Queue is a data structure that follows the First In First Out (FIFO) rule.
*/

class Stack
{

    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return q.size();
    }

    bool isEmpty()
    {
        if (q.empty())
        {
            return true;
        }

        return false;
    }

    void push(int element)
    {
        q.push(element);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (!q.empty())
        {
            int num = q.front();
            q.pop();
            return num;
        }

        return -1;
    }

    int top()
    {
        if (!q.empty())
        {
            return q.front();
        }

        return -1;
    }
};

int main()
{
    return 0;
}