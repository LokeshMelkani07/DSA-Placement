#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Stock Buy And Sell

Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

int maxProfit(vector<int> &prices)
{
    // TLE
    // run 2 loops
    // for each ith price
    // check its difference with all the other prices and return the maximum difference
    int n = prices.size();
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (prices[j] > prices[i])
            {
                maxi = max(prices[j] - prices[i], maxi);
            }
        }
    }

    return maxi;
}

// Optimised
int maxProfit1(vector<int> &prices)
{
    // Maintain a variable minPrice and maxPrice
    // minPrice will be min(arr[i],minPrice) which is amount we use to buy
    // maxPrice will be max(maxPrice, arr[i]-minPrice) which is amount we use to sell
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxPrice = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPrice = max(maxPrice, prices[i] - minPrice);
    }

    return maxPrice;
}

int main()
{
    return 0;
}