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
Area of largest rectangle in Histogram

Problem Statement: Given an array of integers heights representing the histogram’s bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

Example:

Input: N =6, heights[] = {2,1,5,6,2,3}

Output: 10

*/

int largestRectangle(vector<int> &heights)
{
    // Brute force
    // Area of each block is width*height
    // For each bar, we need to get the left max and right max
    // Area = width* (right[i]-left[i]+1)
    // We will find a left smaller and right smaller and apply the formula
    // For every heights[i] we do so and get the maxArea
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        int leftSmaller = i;
        int rightSmaller = i;
        while (leftSmaller >= 0 && heights[i] <= heights[leftSmaller])
            leftSmaller--;
        while (rightSmaller < n && heights[i] <= heights[rightSmaller])
            rightSmaller++;

        // The below formula modifies a little bit because now we are starting index from i in leftSmaller and rightSmaller
        maxArea = max(maxArea, heights[i] * (rightSmaller - leftSmaller - 1));
    }

    return maxArea;
}

int largestRectangle(vector<int> &heights)
{
    // Optimised approach
    // To calculate leftSmaller and rightSmaller
    // Instead of using 2 loops, we will make use of stack
    // We will create 2 array left and right to store both
    // We find leftSmaller from starting of heights array and rightSmaller from end of heights array
    // For leftSmaller, we check stack top and pop it out till height[st.top()] >= height[i] because we need leftSmaller
    // In doing so if stack becomes empty, means no left smaller so first index is itself the smallest
    // push that i in stack else we get the leftSmaller, left[i] = st.top()+1
    // We do +1 because if leftSmaller is at index = 1 means our boundary is from index 2 i.e from index 2 to index i we can take area
    // For rightSmaller
    // We start from end of array and if st.empty() then means no right smaller so last index is itself the smallest in right
    // push that i in stack else we get the rightSmaller, right[i] = st.top()-1
    // We do -1 because if rightSmaller is at index = 6 means our boundary is from index 2 i.e from index 5 to index i we can take area
    // At the end do heights[i]*(right[i]=left[i]+1)
    // Time Complexity: O( N )
    // Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array
    stack<int> st;
    int n = heights.size();
    vector<int> left(n), right(n);
    // LeftSmaller
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty())
            left[i] = 0;
        else
            left[i] = st.top() + 1;
        st.push(i);
    }

    // Empty the stack
    while (!st.empty())
    {
        st.pop();
    }

    // RightSmaller
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty())
            right[i] = n - 1;
        else
            right[i] = st.top() - 1;
        st.push(i);
    }

    // Calculate area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
    }

    return maxArea;
}

int main()
{
    return 0;
}