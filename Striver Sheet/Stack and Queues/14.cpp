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
Next Smaller Element
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.
Example:
If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

*/

vector<int> nextSmallerElement(vector<int> &a, int n)
{
    // Brute force, we can pick one element and check all element towards its right
    // This approach will be O(n2)
    // Optimised approach, we will use a stack
    // We will start from end of the array so that our processing time reduces
    // We push -1 in the stack initially because as we are processing from the end of the array so for the last element, next smaller is -1
    // if our st.top < i we got the answer
    // otherwise we pop out till we get the smaller element at top of stack
    // everytime we push a[i] in the stack
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= a[i])
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(a[i]);
    }

    return ans;
}

int main()
{
    return 0;
}