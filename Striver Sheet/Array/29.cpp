#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Longest Consecutive Sequence in an Array

Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]

Output: 4

Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/

bool linearSearch(vector<int> &a, int target)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return true;
        }
    }

    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    // Brute force
    // We can do linear search
    // we maintain a longest variable to get longest sequence
    // For an element x, we can search for x+1 using linear search
    // we maintain a count variable
    // we go on to search for x+1 everytime till its not found and at the end get max length
    int n = a.size();
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int ele = a[i];
        int count = 0;
        while (linearSearch(a, ele) == true)
        {
            ele = ele + 1;
            count += 1;
        }
        longest = max(longest, count);
    }

    return longest;
}

int longestSuccessiveElements(vector<int> &a)
{
    // Better approach
    // we will sort the array
    // We will use count,lastSmaller,longest variables to store
    // lastSmaller = tells the last element we had in the array initally INT_MIN
    // count = tells number of element in the sequence which follows the condition of consecutiveness initially 0
    // longest = tells us about the length of the longest sequence initally 1
    // we run a loop to reach each element
    // Time Complexity: O(NlogN) + O(N), N = size of the given array.
    // Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
    // Space Complexity: O(1), as we are not using any extra space to solve this problem.
    int n = a.size();
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, count);
    }

    return longest;
}

int longestSuccessiveElements(vector<int> &a)
{
    // Most optimal approach
    // We will use set data structure
    // same as brute force
    // we will store all elements in the set
    // we will check if a[i]-1 is not in the set then we will check for a[i]+1 in the set
    // we will again use longest and count variable
    unordered_set<int> st;
    int count = 0;
    int longest = 1;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        // insert all elements of array inside set
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        // finding inside set
        if (st.find(it - 1) == st.end())
        {
            // means element not found
            int count = 1;
            int x = it;
            // check for ele+1 till we get consecutive numbers
            while (st.find(x + 1) != st.end())
            {
                // do count++ everytime
                count++;
                // and move value of x
                x = x + 1;
            }

            // get such longest sequence
            longest = max(longest, count);
        }
    }

    // return longest sequence
    return longest;
}

int main()
{
    return 0;
}