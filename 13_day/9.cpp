#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 10
// Lecture40: Rat in a Maze Problem
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

/*
Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.

Example 2:

Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.

Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

*/

   bool isSafe(vector<vector<int>> visited,int n,vector<vector<int>> m,int x,int y)
    {
        // Check those 3 conditions before making any step further
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1)
        {
            return true;
        }
        else{
          return false;
        }
    }

    void solve(vector<vector<int>> m,int n,int x,int y,vector<string> &ans,string path,vector<vector<int>> visited)
    {
        // base case
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }

        // Mark visited 1
        visited[x][y] = 1;

        // Down
        int newx = x+1;
        int newy = y;

        if(isSafe(visited,n,m,newx,newy))
        {
            path.push_back('D');
            solve(m,n,x,y,ans,path,visited);
            // Backtracking step
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y-1;

        if(isSafe(visited,n,m,newx,newy))
        {
            path.push_back('L');
            solve(m,n,x,y,ans,path,visited);
            // Backtracking step
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y+1;

        if(isSafe(visited,n,m,newx,newy))
        {
            path.push_back('R');
            solve(m,n,x,y,ans,path,visited);
            // Backtracking step
            path.pop_back();
        }

        // Up
        newx = x-1;
        newy = y;

        if(isSafe(visited,n,m,newx,newy))
        {
            path.push_back('U');
            solve(m,n,x,y,ans,path,visited);
            // Backtracking step
            path.pop_back();
        }

        // While going back mark visited 0
        visited[x][y] = 0;

    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        // If our first call is blocked path means 0 then return empty ans
        if(m[0][0] == 0)
        {
            return ans;
        }

        string path = "";
        vector<vector<int>> visited = m;
        // x and y coordinate of source
        int srcx = 0;
        int srcy = 0;
        // Initialise the visited matrix by 0
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                visited[i][j] = 0;
            }
        }
        solve(m,n,srcx,srcy,ans,path,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main()
{
    return 0;
}