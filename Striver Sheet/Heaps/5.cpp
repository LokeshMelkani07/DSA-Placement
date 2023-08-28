#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
Connect N Ropes With Minimum Cost
You have been given 'N' ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.
Sample Input 1:
4
4 3 2 6

Sample Output 1:
29

Explanation:

1) If we first connect ropes of lengths 2 and 3, we will left with three ropes of lengths 4, 6 and 5.

2) Now then, if we connect ropes of lengths 4 and 5, we will left with two ropes of lengths 6 and 9.

3) Finally, we connect the remaining two ropes and all ropes are now connected.

Total cost for connecting all ropes in this way is 5 + 9 + 15 = 29  which is the optimized cost.
Now there are other ways also for connecting ropes. For example, if we connect 4 and 6 first (we get three ropes of lengths 3, 2 and 10), then connect 10 and 3 (we get two ropes of length 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38 which is not the optimal cost

Sample Input 2:
5
1 2 3 4 5

Sample Output 2:
33
*/

long long connectRopes(int *arr, int n)
{
    // To get the minimum cost, we need to take 2 rope of minimum length and add them
    // Everytime we need 2 minimum ropes means we can use a min heap
    // We will take top 2 elements, pop them from heap and add them and add that answer in total cost
    // Now we push that answer in heap again
    // Now we again repeat this process and we do this till heap.size()>1
    // If only one element left in the heap, we have our answer, return it
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long ans = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        ans += (first + second);
        pq.push(first + second);
    }

    return ans;
}

int main()
{
    return 0;
}
