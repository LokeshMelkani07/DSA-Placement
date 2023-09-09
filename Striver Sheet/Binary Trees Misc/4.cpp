#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

/*
Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
*/

void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, int sr, int sc, int initColor, int xDir[], int yDir[], int newColor)
{
    // first colour the new block
    ans[sr][sc] = newColor;
    int currentRow = sr;
    int currentCol = sc;
    int n = image.size();    // for col
    int m = image[0].size(); // for row

    // now check in 4 direction
    for (int i = 0; i < 4; i++)
    {
        int nRow = currentRow + xDir[i];
        int nCol = currentCol + yDir[i];

        // Validate the 4 directional block
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initColor && ans[nRow][nCol] != newColor)
        {
            dfs(ans, image, nRow, nCol, initColor, xDir, yDir, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // We have a block in a matrix with some old colour
    // we need to check 4-directionally and colour all connected blocks with same new colour
    // how to check connectivity?
    // the block having same initial value as image[sr][sc] will be connected ones
    // we will use a dfs approach
    // we first take initial colour and store it somewhere
    // we colour image[sr][sc] and now we check in 4 direction of it, if block has same prev value, if its valid index and if its not already coloured we colour it
    // we will make a copy of image matrix and store in our answer
    // TC: O(n*m), SC: O(n*m) + O(n*m)
    vector<vector<int>> ans = image;
    // these xDirection and yDirection will help us in going to 4 directions
    int xDirection[] = {-1, 0, +1, 0};
    int yDirection[] = {0, +1, 0, -1};
    int initialColour = image[sr][sc];
    dfs(ans, image, sr, sc, initialColour, xDirection, yDirection, color);
    return ans;
};

int main()
{
    return 0;
}