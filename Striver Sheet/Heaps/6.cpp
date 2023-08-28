#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
Sum of elements between k1'th and k2'th smallest elements
Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

Example 1:
Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20
12,14. Their sum = 26.

Example 2:

Input
N = 6
A[] = {10, 2, 50, 12, 48, 13}
K1= 2, K2 = 6
Output:
73
*/

long long kthsmallest(long long A[], long long N, long long K)
{
    // we need kth smallest so we take max heap
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(A[i]);
        if (pq.size() > K)
        {
            pq.pop();
        }
    }
    return pq.top();
}
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
    long long index1 = kthsmallest(A, N, K1);
    long long index2 = kthsmallest(A, N, K2);

    // Find the k1 smallest element, k2th smallest element
    // Add all numbers whose value>k1th && value<k2th

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > index1 && A[i] < index2)
        {
            sum += A[i];
        }
    }

    return sum;
}

int main()
{
    return 0;
}