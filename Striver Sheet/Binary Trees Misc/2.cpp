#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

/*
Count Distinct Element in Every K Size Window
You are given an array ‘ARR’ of size ‘N’ and an integer ‘K’. Your task is to find the total number of distinct elements present in every ‘K’ sized window of the array. A ‘K’ sized window can also be viewed as a series of continuous ‘K’ elements present in the sequence.
Note:
1. The size of ‘ARR’ will always be greater than or equal to the ‘K’.
2. Here window refers to a subarray of ‘ARR’. Hence ‘K’ sized window means a subarray of size ‘K’.
3. You are not required to print the output explicitly. It has already been taken care of. Just implement the function and return an array of the count of all distinct elements in the ‘K’ size window.
Example:
Consider ARR = [ 1, 2, 1, 3, 4, 2, 3 ] and K = 3.
As per the given input, we have a sequence of numbers of length 7, and we need to find the number of distinct elements present in all the windows of size 3.

Window-1 has three elements { 1, 2, 1 } and only two elements { 1, 2 } are distinct because 1 is repeating two times.
Window-2 has three elements { 2, 1, 3 } and all three elements are distinct { 2, 1, 3 }.
Window-3 has three elements { 1, 3, 4 } and all three elements are distinct { 1, 3, 4 }.
Window-4 has three elements { 3, 4, 2 } and all three elements are distinct { 3, 4, 2 }.
Window-5 has three elements { 4, 2, 3 } and all three elements are distinct { 4, 2, 3 }.

Hence, the count of distinct elements in all K sized windows is { 2, 3, 3, 3, 3 }.

*/

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // We will use hashmap
    // First we will store first k element in hashmap and hashmap.size gives us first element of ans vector
    // now we run a loop from k to arr.size()
    // we remove first element of window and add new element everytime
    // so we need to decrease frequency of removed element
    // and increase frequency of added element
    // everytime we store mp.size in answer
    vector<int> ans;
    unordered_map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }

    ans.push_back(mpp.size());

    // now add one element and remove on element from map
    for (int j = k; j < n; j++)
    {
        // for window of size k, our first element always lies in index j-k
        if (mpp[arr[j - k]] == 1)
        {
            // if its  freq is 1, remove it from map
            mpp.erase(arr[j - k]);
        }
        else
        {
            // else decrease its frequency
            mpp[arr[j - k]]--;
        }

        // add new element
        mpp[arr[j]]++;
        ans.push_back(mpp.size());
    }

    return ans;
}

int main()
{
    return 0;
}