#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Set Matrix Zero
/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
*/

/*
Brute force
Mark all rows and col which has matrix[i][j]==0 as -1 separately.
we cannot mark it 0 directly because that may interfare with the problem statement and get us error in answer
after this, mark all blocks with -1 as back to 0 and return that matrix

*/

void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix1(vector<vector<int>> &matrix, int n, int m)
{
    // n is rows
    // m is cols

    // mark all zero vale ki rows and col with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // mark all with -1 as 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// Better approach
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // Make 2 separated arrays row and col
    // if any matrix[i][j]==0, we mark that row[i] and col[j] = 1
    // so that in the final matrix we can make that whole ith row or jth col as 0
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // if any row or col is 1, mark whole as 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
int main()
{

    return 0;
}