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
Implement Min Stack : O(2N) and O(N) Space Complexity

Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Examples:

Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[
[ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
]

Result: [null, null, null, null, -3, null, 0, -2]
Explanation:
stack < long long > st
st.push(-2); Push element in stack
st.push(0); Push element in stack
st.push(-3); Push element in stack
st.getMin(); Get minimum element fromstack
st.pop(); Pop the topmost element
st.top(); Top element is 0
st.getMin(); Minimum element is -2
*/

// Implement class for minStack.
class minStack
{
    stack<pair<int, int>> st;
    // We will store <element,min> in stack where min = minimum element till that index
    // TC : O(1), SC : O(n)
public:
    // Constructor
    minStack() {}

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        int mini;
        if (st.empty())
        {
            // stack empty means first element in min currently
            st.push({num, num});
        }
        else if (st.top().second < num)
        {
            st.push({num, st.top().second});
        }
        else
            st.push({num, num});
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;
        int t = st.top().first;
        st.pop();
        return t;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;
        else
            return st.top().first;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;
        else
            return st.top().second;
    }
};

int main()
{
    return 0;
}