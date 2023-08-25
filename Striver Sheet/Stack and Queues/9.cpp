#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Rotten Oranges : Min time to rot all oranges : BFS

Problem Statement: You will be given an m x n grid, where each cell has the following values :

    2  –  represents a rotten orange
    1  –  represents a Fresh orange
    0  –  represents an Empty Cell

Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten.

Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it’s not possible, return -1.
*/

int orangesRotting(vector<vector<int>> &grid)
{
    // We will use a queue of pairs
    // We will calculate number of non-empty cells
    // We will push rotten {i,j} to queue
    // Make a variable days
    // Now till queue is not empty
    // Add q.size() into count
    // Now till q.size()--
    // take out one orange form queue and check in all 4 directions and mark any fresh orange if available as rotten
    // Push that new orange in queue
    // do days++
    // After coming out of loop, of number of elements inserted in queue during whole process == number of non-empty cell then return days else return -1
    // TC : O(n*n) SC = O(n*n)
    if (grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0; // total elements entered in queue
    int days = 0;
    int total = 0; // total non empty cell
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
                total++; // calculate total
            if (grid[i][j] == 2)
                q.push({i, j}); // push rotten oranges in queue
        }
    }

    // we have created dx and dy for the all 4 direction
    // dx,dy = {{0,1},{0,-1},{1,0},{-1,0}}
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
        int k = q.size();
        count += k; // adding the elements added in queue
        while (k--) // while all element gets tested
        {
            int x = q.front().first;    // i index of rotten orange
            int y = q.front().second;   // j index of rotten orange
            q.pop();                    // pop it out
            for (int i = 0; i < 4; i++) // check for all 4 direction for a particular rotten orange
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // if its invalid or empty cell leave it
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;
                // else mark it as rotten and push in queue
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        // if q is not empty means one cycle is completed days++
        if (!q.empty())
            days++;
    }
    // if total==count means all orange rotten else return -1
    return total == count ? days : -1;
}

int main()
{
    return 0;
}