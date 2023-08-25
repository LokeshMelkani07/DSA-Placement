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
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
Sample Input 1:
1
5
5 -2 9 -7 3

Sample Output 1:
9 5 3 -2 -7

Explanation of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last.

Sample Input 2:
1
5
-3 14 18 -5 30

Sample Output 2:
30 18 14 -3 -5

Explanation of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last.
*/

void insertBottom(stack<int> &st, int num)
{
    // Base case -> when to push?
    // if our st.top is smaller than element, simply push it or if our stack is empty, simply push element
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }

    // Get the top element
    int ele = st.top();
    st.pop();
    // Keep on taking out the top element till base case is satisfied
    insertBottom(st, num);
    // On moving back after hitting the base case, put the top element back to stack
    st.push(ele);
}
void sortStack(stack<int> &stack)
{
    // Check the top of stack
    // pop it out till st.top>x
    // Do it recursively
    // then push the element in its correct position
    if (stack.empty())
    {
        // base case -> stack becomes empty
        return;
    }

    // Get the top element from the stack
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    // Now while going back after hitting the base case, choose the correct position for that number in the stack
    insertBottom(stack, num);
}

int main()
{
    return 0;
}