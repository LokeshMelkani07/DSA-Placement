#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Brute force approach
    // Just do normal linear search for each element in matrix but this gives TLE
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    // As it is given that the martix so sorted in row and col manner
    // So we can apply binary search also
    int n = matrix.size();
    int m = matrix[0].size();

    if (n == 0)
    {
        return false;
    }

    int start = 0;
    int end = (m * n) - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // this is an imaginary index of a 1D array. to use it for our 2D array we do mid/m and mid%m

        // we do mid/m and mid%m to get the index of teh element because we do not have a temporary array in which are storing the values
        // so mid/m gives us row value
        // mid%m gives us col value
        // where m is col size
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        if (matrix[mid / m][mid % m] < target)
        {

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main()
{
    return 0;
}