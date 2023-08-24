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
Next Greater Element Using Stack

Problem Statement: Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn’t exist, return -1 for this element.

Examples:

Example 1:
Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}
Output: 10,-1,6,6,2,6,7,7,9,9,10

Explanation: For the first element in A ,i.e, 3, the greater element which comes next to it while traversing and is closest to it is 10. Hence,10 is present on index 0 in the resultant array. Now for the second element,i.e, 10, there is no greater number and hence -1 is it’s next greater element (NGE). Similarly, we got the NGEs for all other elements present in A.


Example 2:
Input:  N = 6, A[] = {5,7,1,7,6,0}
Output: 7,-1,7,-1,7,5
*/

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    // We will start traversing from the end of the array
    // We will check stack top, if thats smaller than current element we pop it out till we have st.top>arr[i]
    // if in this process stack becomes empty means that element has no NGE so -1 for that index in answer array
    // and push that element in the stack
    // if we get a stack.top then store it in answer array
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    return 0;
}