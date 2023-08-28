#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/*
K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    // we can store distance and coordinate in vector
    // we need minimum distance for k elements means we need max heap
    // we pop if size>k this way we always maintain lower k values in the heap
    vector<vector<int>> result(k);
    // maxheap storage initialization
    priority_queue<vector<int>> maxHeap;
    // Construction of maxheap
    for (auto &p : points)
    {
        int x = p[0], y = p[1]; // as the other point is origin always so formula reduces easily
        maxHeap.push({x * x + y * y, x, y});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    for (int i = 0; i < k; ++i)
    {
        // In the top vector we have {distance value, coordinate 1, coordinate 2}
        vector<int> top = maxHeap.top();
        maxHeap.pop();
        // top[1] means coordinate 1, top[2] means coordinate 2
        result[i] = {top[1], top[2]};
    }

    return result;
}

int main()
{
    return 0;
}