#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode Questions on 2D Matrix

// Print Like A Wave
// For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int col = 0;col<mCols;col++)
    {
       if(col&1)
       {
           // ODD Index means bottom to top
           for(int i = nRows-1; i>=0; i--)
           {
               ans.push_back(arr[i][col]);
           }
       }
       else{
           // Even Index means Top to Bottom
           for(int i = 0; i<nRows; i++)
           {
               ans.push_back(arr[i][col]);
           }
       }
    }
    return ans;
}

// Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // TC: O(m*n)
        vector<int> ans;
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        int count = 0;
        int total = row_size*col_size;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row_size-1;
        int endingCol = col_size-1;

        while(count<total)
        {
            // Print starting row
            for(int i = startingCol; count<total && i<=endingCol;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Print ending col
            for(int i = startingRow; count<total && i<=endingRow;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;


            // print ending row
            for(int i = endingCol; count<total && i>=startingCol;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // print starting col
            for(int i = endingRow; count<total && i>=startingRow;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;

        }
        return ans;
}

// Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

 void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0;i<size;i++)
        {
            for(int j = 0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i<size;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
 }

// Binary Search in a 2D Array
// You are given an m x n integer matrix matrix with the following two properties:Each row is sorted in non-decreasing order.The first integer of each row is greater than the last integer of the previous row.Given an integer target, return true if target is in matrix or false otherwise.

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col -1;

        int mid = start + (end-start)/2;

        while(start<=end)
        {
            // In 2D array we find arr[mid] using below formula
            int element = matrix[mid/col][mid%col];

            if(element == target)
            {
                return 1;
            }
            if(element < target)
            {
                start = mid+1;
            }
            else{
                end = mid-1;
            }

            mid = start + (end-start)/2;
        }
        return 0;
}

// Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:Integers in each row are sorted in ascending from left to right.Integers in each column are sorted in ascending from top to bottom.
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = col-1;

        while(start<row && end>=0)
        {
            int element = matrix[start][end];

            if(element ==target)
            {
                return 1;
            }

            if(element < target)
            {
                start++;
            }
            else{
                end--;
            }
        }

        return 0;
}

int main()
{
    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {12,13,14,15}
    };
    return 0;
}