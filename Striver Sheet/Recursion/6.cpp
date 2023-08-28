#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

Examples:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

bool isSafe(int row, int col, vector<string> board, int n)
{
    // We are placing queens in left->right direction
    // So while placing a queen we need to worry about only 3 directions in the backward direction
    // Check if there is queen in those 3 directions
    int duprow = row;
    int dupcol = col;
    // upward in left
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    // Straight direction in left
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // downward in left
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}
void ways(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    // base case
    if (col == n)
    {
        // If we reach the end col
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        // Place queen in each row
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            // Fill in next col
            ways(col + 1, ans, board, n);
            // backtrack step, remove queen while coming back
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        // fill the chess board with empty cells
        board[i] = s;
    }

    ways(0, ans, board, n);
    return ans;
}

int main()
{
    return 0;
}