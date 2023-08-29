#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Median in a stream
Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.

Sample Input 1:

3
3
1 2 3
2
9 9
1
4

Sample Output 1:

1 1 2
9 9
4

Explanation for Sample Input 1:

For test case 1
After reading first element of stream , Median of [1] is 1
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2.

Sample Input 2:

2
3
5 3 8
2
3 8

Sample Output 2:

5 4 5
3 5

Explanation for Sample Input 2:

For test case 1
After reading first element of stream, Median of [5] is 5
After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
So the output will be 5 4 5.
*/

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callMedian(int element, priority_queue<int> &maxH, priority_queue<int, vector<int>, greater<int>> &minH, int &median)
{
    // we will write a switch case based on size of heaps
    switch (signum(maxH.size(), minH.size()))
    {
    case 0:
        if (element > median)
        {
            // 0 means size of a==b
            // go to right part of array means min heap
            minH.push(element);
            // case of odd as now right become n+1 so min heap has n+1 element so
            median = minH.top();
        }
        else
        {
            // less than median means go to left array i.e max heap
            maxH.push(element);
            // case of odd as now left become n+1 so max heap has n+1 element so
            median = maxH.top();
        }
        break;
    case 1:
        if (element > median)
        {
            // case 1 means size of maxH is n and size of minH is n-1
            // ele > median means go to right part, minH
            minH.push(element);
            // case of even now
            median = (maxH.top() + minH.top()) / 2;
        }
        else
        {
            // go to left part i.e maxH
            // but maxH is already n sized if we put one more elemnt its size becomes n+1
            // now difference in size of maxH and minH become 2 which creates a imbalance
            // so first take maxH.top and put in minH then push elemnt in maxh
            minH.push(maxH.top());
            maxH.pop();
            maxH.push(element);
            // size of both become n so its case of even
            median = (maxH.top() + minH.top()) / 2;
        }
        break;

    case -1:
        if (element > median)
        {
            // case -1 means size of minH > size of maxH
            // element > median means go to right part i.e minH
            // minH has size of n already and maxH has size of n-1 already
            // adding one more element in minH creates an imbalance so to balance out
            // push minH.top() in maxH and then push element in minH
            maxH.push(minH.top());
            minH.pop();
            minH.push(element);
            median = (maxH.top() + minH.top()) / 2;
        }
        else
        {
            // Put in maxH simply
            maxH.push(element);
            median = (maxH.top() + minH.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{

    // Brute force approach
    // We know to find the median
    // if size of array is odd, median = arr[size/2]
    // if size of array is even, median = (arr[size-1/2] + arr[size/2])/2
    // But this formula holds good only on sorted arrays
    // So one approach we can think of is, sort the array and app;y above formula
    // We have many sorting algos which one to use?
    // This is a running stream so everytime we sort array, one new element gets added
    // we need to use a algo where we do not disturb the previous sorted elements much
    // So we can think of insertion sort, which has a n^2 TC on worst case
    // Pick the new element and insert it in its right position
    // This way we sort the array and apply above formula to get the median

    // Another approach can be use
    // Heap
    // Let say we have an array [left part, median, right part]
    // We know left part< median always and right part > median always
    // In case array size is odd, means case 1: left has size of n-1 and right has size of n
    // or case 2: right has size of n-1 and left has size of n
    // In case array size is even, means case 3: left has size of n and right has size of n
    // So here we have 3 cases
    // we will use signum(a,b) function which return
    // a==b, returns 0
    // a>b, returns 1
    // a<b, returns -1
    // We need left part < median means for left part we can use a max heap so that (median-1)th is maximum of left element array
    // We need right part> median means for right part we can use a min heap so that (median+1)th is minimum of right element array
    // if size of max heap == size of min heap means its even size so median is (maxH.top() + minH.top()) /2
    // if size of max heap is n-1 and min heap is n means odd size so median = maxH.top()/2
    // if size of max heap is n and min heap is n-1 means odd size so median = minH.top()/2
    // TC: O(nlogn)
    vector<int> ans;
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int median = 0;
    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxH, minH, median);
        ans.push_back(median);
    }

    return ans;
}

int main()
{
    return 0;
}