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
Maximum of minimum for every window size
You are given an array of ‘N’ integers, you need to find the maximum of minimum for every window size. The size of the window should vary from 1 to ‘N’ only.
Example:
ARR = [1,2,3,4]
Minimums of window size 1 = min(1), min(2), min(3), min(4) = 1,2,3,4
Maximum among (1,2,3,4)  is 4

Minimums of window size 2 = min(1,2), min(2,3),   min(3,4) = 1,2,3
Maximum among (1,2,3) is 3

Minimums of window size 3 = min(1,2,3), min(2,3,4) = 1,2
Maximum among (1,2) is 2

Minimums of window size 4 = min(1,2,3,4) = 1
Maximum among them is 1
The output array should be [4,3,2,1].

*/

vector<int> maxMinWindow(vector<int> arr, int n)
{
    /*
    Brute Force
    We will use two nested loops for sliding on the window of every possible size and one more inner loop to traverse on the window and store the minimum element of the current window in a ‘temp’ variable.
    We will create an array named ‘answer’. The ‘answer[i]’ will store the maximum of all the available minimum of every window size ‘i’.
    If ‘i’ and ‘j’  are the starting and ending indexes of the window then its length = j-i+1.
    So we update our ‘answer[length]’ with the maximum of all the available minimum of every window size ‘i’ with the help of a ‘temp’ variable
    i.e, ‘answer[length]’ = max( answer[length] , temp ).
    Time Complexity
    O(N ^ 3), where ‘N’ is the number of elements present in the array.
    As we ran 3 nested loops in total, 2 for sliding over the window and one for calculating over the answer for the current window. Hence, the overall Time Complexity is O(N ^ 3).
    Space Complexity
    O(1).
    Constant space is being used. Hence, the overall Space Complexity is O(1)
    */

    // Definition: answer[i] will store the maximum of minimum of every window of size 'i'.
    vector<int> answer(n);

    for (int i = 0; i < n; ++i)
    {
        answer[i] = INT_MIN;
    }

    // Sliding on all possible windows
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {

            // Start is the starting index of current window
            int start = i;

            //  End is the ending index of current window
            int end = j;

            // Temp will store minimum element for the current window
            int temp = INT_MAX;
            for (int k = start; k <= end; ++k)
            {
                temp = min(temp, arr[k]);
            }

            int length = end - start;

            // Update the answer of current window length
            answer[length] = max(answer[length], temp);
        }
    }

    return answer;
}

int main()
{
    return 0;
}