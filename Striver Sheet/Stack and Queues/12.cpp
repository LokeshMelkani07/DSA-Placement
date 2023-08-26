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
Online Stock Span
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

    For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
    Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

Implement the StockSpanner class:

    StockSpanner() Initializes the object of the class.
    int next(int price) Returns the span of the stock's price given that today's price is price.

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
*/

vector<int> findStockSpans(vector<int> &prices)
{
    // We are given prices of a stock in prices vector
    // Where index of vector represents days number
    // We need to tell for a particular ith day, the number of consecutive days till i when price[j] <= prices[i]
    // We need to include ith day also in that answer
    // Brute force
    // For every i, we move to its left and check consecutive smaller numbers and do count++ and store in ans vector for that ith day
    // TC: O(n2)
    // Optimised approach
    // We will use a stack in which we will store the price,span for each index
    // Check the stack top, if its smaller then add its span in the ans
    int n = prices.size();
    vector<int> ans(n);
    if (n == 1)
        return {1};
    stack<pair<int, int>> st; // To store the indexes
    int span = 1;
    for (int i = 0; i < n; i++)
    {
        span = 1;
        while (!st.empty() && st.top().first < prices[i])
        {
            span += st.top().second;
            st.pop();
        }

        st.push({prices[i], span});
        ans[i] = span;
    }

    return ans;
}

vector<int> findStockSpans(vector<int> &prices)
{
    // Another approach
    // We will take ans vector with 1 initial value as minimum ans can be 1
    // We will store the indexes in the stack
    // Push 0
    // Run a loop from i = 1 to =n-1
    // We will pop out till value of prices at st.top < i
    // if stack becomes empty means no lesser value found for ans[i] += i;
    // if stack not empty then ans[i] += st.top - i - 1
    int n = prices.size();
    vector<int> ans(n, 1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] < prices[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] += i - st.top() - 1;
        }
        else
        {
            ans[i] += i;
        }

        st.push(i);
    }

    return ans;
}

int main()
{
    return 0;
}