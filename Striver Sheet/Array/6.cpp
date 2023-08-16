#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Rotate Image by 90 degree

Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
*/

void rotate(vector<vector<int>> &matrix)
{
    // Brute force
    // make another matrix such that store first row of original matrix in last col of it
    // second row in second col of matrix and so one
    // for one row -> third col we can observe
    // (0,0) -> (0,2) and (0,1) -> (1,2) and (0,2) -> (2,2) i.e rotated[i is changing][j = n-i-1] only
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    matrix = rotated;
}

// Optimised approach
void rotate(vector<vector<int>> &matrix)
{
    // Transpose each col and reverse each row
    // we get the answer
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    return 0;
}