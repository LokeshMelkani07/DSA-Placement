#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Sudoku Solver

Problem Statement:
Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

         1. All the rows should be filled with numbers(1 – 9) exactly once.

         2. All the columns should be filled with numbers(1 – 9) exactly once.

         3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.

Note: Character ‘.’ indicates empty cell.
*/

bool isSafe(int row, int col, int board[][9], int val)
{
    // for value 1 to 9 check
    // int n = board[0].size();  // right
    int n = 9; // wrong
    for (int i = 0; i < n; i++)
    {
        // check for the row
        if (board[row][i] == val)
        {
            return false;
        }
        // check for col
        if (board[i][col] == val)
        {
            return false;
        }
        // check for 3*3 matrix
        // This below formula will check for every cell in 3x3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(int board[9][9])
{
    // int n = board[0].size();  // right
    int n = 9; // wrong

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                // empty cell found
                for (int i = 1; i <= 9; i++)
                {
                    // check by placing each value
                    if (isSafe(row, col, board, i))
                    {
                        board[row][col] = i;

                        bool nextSolution = solve(board);
                        if (nextSolution)
                        {
                            // means we have successfully filled the empty cell
                            return true;
                        }
                        else
                        {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                // if we come here means we tried each value from 1 to 9 and could not able to fill it
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int board[][9])
{
    return solve(board);
}

int main()
{
    return 0;
}