#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
K Max Sum Combinations
You are given two arrays/lists A and B and K
You must return ‘K’ distinct maximum and valid sum combinations from all the possible sum combinations of the arrays/lists ‘A’ and ‘B’.
Sum combination adds one element from array ‘A’ and another from array ‘B’.
Sample Input 1 :

3 2
1 3 5
6 4 2

Sample Output 1 :

11 9

Explanation of Sample Output 1 :

For the given arrays/lists, all the possible sum combinations are:
7(1 + 6), 5(1 + 4), 3(1 + 2), 9(3 + 6), 7(3 + 4), 5(3 + 2), 11(6 + 5), 9(5 + 4), 7(5 + 2).

The two maximum sum combinations from the above combinations are 11 and 9.

Sample Input 2 :

2 1
1 1
1 1

Sample Output 2 :

2

Explanation of sample input 2 :

For the given arrays/lists, two possible sum combinations are 2(1 + 1), and 2(1 + 1).

*/

// sum up all element of array 1 with all element of array 2 and store in max heap
// store first k element of max heap in answer vector
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int k)
{
    sort(A.begin(), A.end());
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            pq.push(A[i] + B[j]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    return 0;
}