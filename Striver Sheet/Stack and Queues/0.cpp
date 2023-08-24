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
Implement Stack using Array
Problem statement: Implement a stack using an array.
Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

Example:
Explanation:

push(): Insert the element in the stack.
pop(): Remove and return the topmost element of the stack.
top(): Return the topmost element of the stack
size(): Return the number of remaining elements in the stack.
*/

// Stack class.
class Stack
{
private:
    int top1;
    int size;
    int *arr;

public:
    Stack(int capacity)
    {
        size = capacity;
        top1 = -1;
        arr = new int[capacity];
    }

    void push(int num)
    {
        if (!isFull())
        {
            top1++;
            arr[top1] = num;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        top1--;
        int num = arr[top1 + 1];
        return num;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return arr[top1];
    }

    int isEmpty()
    {
        return top1 == -1;
    }

    int isFull()
    {
        return top1 + 1 == size;
    }
};

int main()
{
    return 0;
}
