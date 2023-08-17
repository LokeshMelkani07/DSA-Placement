#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Grid Unique Paths | Count paths from left-top to the right bottom of a matrix

Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.
*/

// Brute approach using recursion
int countPath(int i, int j, int m, int n)
{
    // if we reach the end of matrix, return 1
    if (i == (m - 1) && j == (n - 1))
        return 1;
    // if we reach out of bound of matrix, return 0
    // else, count paths on going right and all path on going down
    if (i >= m || j >= n)
        return 0;
    else
        return countPath(i + 1, j, m, n) + countPath(i, j + 1, m, n);
}
int uniquePaths(int m, int n)
{
    // Brute approach using recursion
    // starting from 0,0 position
    return countPath(0, 0, m, n);
}

// DP solution
// The only change in the dynamic programming solution is whenever we are returning answers we store them in the matrix A[i][j] and wherever we are making a recursive call we simply check if that state is already visited or not in other words we’ll check if A[i][j] is -1 or not if it is not -1 that means that there is a subproblem which is repeating. Now instead of recomputing the subproblem, we’ll return the value at A[i][j].
int countPath(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // if we reach the end of matrix, return 1
    if (i == (m - 1) && j == (n - 1))
        return 1;
    // if we reach out of bound of matrix, return 0
    // else, count paths on going right and all path on going down
    if (i >= m || j >= n)
        return 0;
    // check if dp[i][j] has some answer already or not
    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = countPath(i + 1, j, m, n, dp) + countPath(i, j + 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    // Brute approach using recursion
    // starting from 0,0 position
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int num = countPath(0, 0, m, n, dp);
    if (m == 1 && n == 1)
    {
        return num;
    }
    return dp[0][0];
}

// Combinatorics Solution
int uniquePaths(int m, int n)
{
    // Combinatorics Solution
    // Intuition: If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.
    // Max we are moving is m-1 steps rightwards and n-1 steps downwards
    // So total step are m-1+n-1 = m+n-2
    // calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main()
{
    return 0;
}