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
Immediate Smaller Element
For each element in the array, check whether the immediate right element of the array is smaller or not.
If the next element is smaller, update the current index to that element. If not, then  -1. The last element does not have any elements on its right.
Example:
Input: 'a' = [4, 7, 8, 2, 3, 1]

Output: Modified array 'a' = [-1, -1, 2, -1, 1, -1]

Explanation: In the array 'a':
4 has 7 on its right. Since 7 is not smaller, we update 4 to -1.

7 has 8 on its right. Since 8 is not smaller, we update 7 to -1.

8 has 2 on its right. Since 2 is smaller than 8, we update 8 to 2.

2 has 3 on its right. Since 3 is not smaller, we update 2 to -1.

3 has 1 on its right. Since 1 is smaller than 3, we update 3 to 1.

1 does not have any element on right. So we update 1 to -1.

*/

void immediateSmaller(vector<int> &a)
{
    // Brute force
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            a[i] = a[i + 1];
        else
            a[i] = -1;
    }

    a[a.size() - 1] = -1;
}

void immediateSmaller(vector<int> &a)
{
    // Optimised Approach
    // We will start from the end of the array
    // We will use a stack
    // Push last element i.e a[n-1] in the stack initially
    // Now start processing from n-2 till i>-1
    // if stack top is smaller than a[i] means we have got the immediate smaller
    // pop it out and store in the answer, push a[i] in stack
    // else, pop it out and store -1 for that a[i]
    // At the end, a[n-1] = -1 because for last element there is not immediate smaller
    int n = a.size();
    stack<int> st;
    st.push(a[n - 1]);
    int i = n - 2;

    while (i > -1 && !st.empty())
    {
        if (st.top() < a[i])
        {
            // st.top is smaller than a[i] means its the immediate smaller
            int element = a[i];
            a[i] = st.top();
            st.pop();
            st.push(element);
        }
        else
        {
            // there is no immediate smaller for a[i] so store -1 and push in stack
            st.pop();
            st.push(a[i]);
            a[i] = -1;
        }

        i--;
    }

    // Last element has no immmediate smaller so -1

    a[n - 1] = -1;
}

int main()
{
    return 0;
}