#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Rat in a Maze

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

Note: In a path, no cell can be visited more than one time.

Print the answer in lexicographical(sorted) order

Examples:
Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}}

Output: DDRDRR DRDDRR

Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Example 2:

Input: N = 2
       m[][] = {{1, 0},
                {1, 0}}

Output:
 No path exists and the destination cell is blocked.
*/

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &vis, vector<string> &ans)
{
    // we have 3 conditions
    // x and y should be inside matrix
    // arr[x][y] should not be visisted already i.e vis[x][y] != 1
    // arr[x][y] should be a valid box to move upon
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] == 1 && arr[newx][newy] != 1)
    {
        return false;
    }
    else
    {

        return true;
    }
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visisted, vector<string> &ans, string path)
{
    // base case will be when we reach our destination
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // We have Down, left, right, up as possible movements
    // We need to return answer in lexiographic order which is D,L,R,U so we move in this pattern only

    // Down means row+1, col
    if (isSafe(x + 1, y, arr, n, visisted, ans))
    {
        visisted[x][y] = 1;
        solve(x + 1, y, arr, n, visisted, ans, path + "D");
        // Backtrack step
        visisted[x][y] = 0;
    }

    // Left means row+1, col
    if (isSafe(x, y - 1, arr, n, visisted, ans))
    {
        visisted[x][y] = 1;
        solve(x, y - 1, arr, n, visisted, ans, path + "L");
        // Backtrack step
        visisted[x][y] = 0;
    }

    // Right means row+1, col
    if (isSafe(x, y + 1, arr, n, visisted, ans))
    {
        visisted[x][y] = 1;
        solve(x, y + 1, arr, n, visisted, ans, path + "R");
        // Backtrack step
        visisted[x][y] = 0;
    }

    // Up means row+1, col
    if (isSafe(x - 1, y, arr, n, visisted, ans))
    {
        visisted[x][y] = 1;
        solve(x - 1, y, arr, n, visisted, ans, path + "U");
        // Backtrack step
        visisted[x][y] = 0;
    }

    return;
}
vector<string> findPath(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visisted(n, vector<bool>(n, 0));
    if (arr[0][0] == 0)
    {
        // edge case
        // if starting point is not visitable means we can't even stand at starting point
        return ans;
    }
    string path = "";
    solve(0, 0, arr, n, visisted, ans, path);
    return ans;
}

int main()
{
    return 0;
}