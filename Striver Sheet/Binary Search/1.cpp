#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Median of Row Wise Sorted Matrix
Problem Statement: Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.

Assume – r*c is odd

Examples:

Example 1:
Input:
r = 3 , c = 3
1 4 9
2 5 6
3 8 7
Output: Median = 5
Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9
So, median = 5

Example 2:
Input:
r = 3 , c = 3
1 3 8
2 3 4
1 2 5
Output: Median = 3
Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8
So, median = 3
*/

int median(vector<vector<int>> &matrix, int m, int n)
{
    // Brute force approach
    // We are given m and n are always odd means size of the array is odd as The product of two odd numbers is an odd number.
    // In an sorted array of odd number we know median is arr[size/2] element
    // We store all elements of the matrix in a 1D array and return arr[size/2] element
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }

    sort(ans.begin(), ans.end());
    return ans[ans.size() / 2];
}

int countsmallerthanequalto(vector<int> &row, int value)
{
    // Here we apply binary search on the sorted row-wise order given to us
    // We need to find the index of the element > value
    // As we know array is sorted so if we get such element
    // our low points to index of first such element and as its a 0-based indexing means index = number of elements <= value
    // 1 3 5 5 5 6 6 is our array and value = 5
    // we need to find index of element > 5
    // at the end of the binary search our low = 5 i.e arr[low] = 6
    // as its 0-based indexing so number of element before 6 which are <= value are also 5 so return low
    // we add this low in the count which tells number of element <= value in that row
    int low = 0;
    int high = row.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (row[mid] <= value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}
int median(vector<vector<int>> &matrix, int m, int n)
{
    // Optimised approach
    // We are given m and n are always odd means size of the array is odd as The product of two odd numbers is an odd number.
    // In an sorted array of odd number we know median is arr[size/2] element
    // We will use a approach written below
    // We know if x is median then number of element <= x will be same as number of elements >= x
    // x1,x2,x3,x,x4,x5,x6  where x3<=x and x4>=x
    // and we know our search space will be anywhere between 1 to 10^9 this is max we can go
    // everytime we find a mid we check how many elements in the matrix are <= mid
    // we do that checking by using binary search only, using row-wise sorted order
    // once we find number of elements <= mid say t
    // we check if t <= (n*m)/2 means low = mid+1 else high = mid-1
    // at the end we return low as the answer
    // Time Complexity: O(row*log col) since the upper bound function takes log c time.
    // Space Complexity: O(1) since no extra space is required.
    int low = 1;
    int high = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // we can also write (int mid = (l + h) >> 1) in bit manner
        // now we have got the mid so count number of elements
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            // We need to find the index of the element > value
            count += countsmallerthanequalto(matrix[i], mid);
            // we add this low in the count which tells number of element <= value in that row
        }

        if (count <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    return 0;
}