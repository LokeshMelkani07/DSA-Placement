#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2D array or matrix
// Questions

// Sprial Print
 vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> mat;
        int startRow = 0;
        int endRow = matrix.size()-1;
        int startCol = 0;
        int endCol = matrix[0].size()-1;
        while(startRow<= endRow && startCol <= endCol)
        {
            for(int i = startRow ; i<= endCol ; i++)
            {
                mat.push_back(matrix[startRow][i]);
            }
            for(int j = startRow+1 ;j<= endRow;j++ )
            {

                mat.push_back(matrix[j][endCol]);
            }
            for(int k = endCol-1; k>=startCol;k--)
            {
                if(startRow == endRow)
                {
                    break;
                }
                mat.push_back(matrix[endRow][k]);
            }
            for(int l = endRow-1 ; l>=startCol+1;l--)
            {
                 if(startCol == endCol)
                {
                    break;
                }
                mat.push_back(matrix[l][startCol]);
            }
            startRow++;
            endRow--;
            endCol--;
            startCol++;
        }
        return mat;
}

// Rotate Image by 90 degrees
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

// Search in a 2D matrix
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
    {
        return false;
    }

    for(int row = 0 ; row < matrix.size();row++)
    {
        for(int col = 0;col<matrix[0].size();col++)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}