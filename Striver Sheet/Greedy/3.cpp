#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Fractional Knapsack Problem : Greedy Approach

Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00
*/

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return ((double)a.second / a.first) > ((double)b.second / b.first);
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // We have {weight, value} and max weight knapsack can withstand i.e w
    // We first find out weight/value for each element of items
    // Let say w = 50, we have {{60,10},{100,20},{120,30}}
    // We can first take 60 now 50-10 = 40 left
    // we take 100 so now 40-20 = 20 left
    // We can take fraction of 120 i.e 30 -> 120 then 1 -> 120/30 and 20 -> 4*20 = 80
    // so we can take 20 fraction from 120
    // This way we can proceed but if we check weight/value ratio for each we get {6,5,4}
    // We sort the weight/val in descending order
    // We take the value add it and check it does not exceed w and at same time value maximizes
    // if our arr[i]>leftOverWeight we do take it fraction using its weight/value ratio
    // TC: O(nlogn) + O(n), SC: O(1)
    // Make sure to take currValue as double because we are takinf fraction so it can come in decimals also

    sort(items.begin(), items.end(), comp);

    int currWeight = 0;
    double currValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            currValue += items[i].second;
        }
        else
        {
            int remain = w - currWeight;
            currValue += (items[i].second / (double)items[i].first) * (double)remain;
            break;
        }
    }

    return currValue;
}

int main()
{
    return 0;
}