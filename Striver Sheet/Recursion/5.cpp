#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
Permutation Sequence
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"

Example 3:

Input: n = 3, k = 1
Output: "123"
*/

string getPermutation(int n, int k)
{
    // Refer to notes for understanding
    /*
    Time Complexity: O(N) * O(N) = O(N^2)
    Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

    Space Complexity: O(N)
    Reason: We are storing  the numbers in a data structure(here vector)
    */
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k - 1;
    string ans = "";
    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main()
{
    return 0;
}
