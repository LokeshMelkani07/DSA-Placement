#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Find minimum number of coins

Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

Examples:

Example 1:

Input: V = 70

Output: 2

Explaination: We need a 50 Rs note and a 20 Rs note.

Example 2:

Input: V = 121

Output: 3

Explaination: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.
*/

vector<int> MinimumCoins(int n)
{
    // As denominations are already in sorted order
    // We start from the last, that is pick the largest coin first
    // Try to make sum = N using largest coins so that less number of coins needed
    // If n<deno[i] leave that coin value
    // add deno[i] till n>=deno[i]
    // TC: O(n), SC: O(1)
    vector<int> amt{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    for (int i = amt.size() - 1; i >= 0; --i)
    {

        if (amt[i] <= n)
        {

            ans.push_back(amt[i]);
            n = n - amt[i];
            i++;
        }
    }

    return ans;
}

int main()
{
    return 0;
}