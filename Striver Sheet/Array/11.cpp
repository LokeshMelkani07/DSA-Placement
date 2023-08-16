#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Hit most Balloons
You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point. When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst. Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.
*/

int mostBalloons(int N, pair<int, int> arr[])
{
    // The approach will be
    // An arrow never takes zig-zag path, it always travels in staright line
    // all points lying on a straight line will have same slope so
    // we will use formula for slope = y2-y1/x2-x1
    // we will use a map to store slope and count of element having that slope means number of ballons

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        // let us take our starting point
        int x1 = arr[i].first;
        int y1 = arr[i].second;
        // We use count to store overlapping ballons
        int count = 0;
        // unordered_map to store slope and count
        unordered_map<double, int> mpp;
        // For every point x1,y1 we will check other elements on matrix for slope so use another loop
        for (int j = 0; j < N; j++)
        {
            int x2 = arr[j].first;
            int y2 = arr[j].second;
            // check if same point lies one above another then we can burst 2 ballons simulatenously
            // so to take this case into the account we do
            if (x1 == x2 && y1 == y2)
            {
                // means same point so
                count++;
                continue;
            }
            else
            {
                double numerator = (double)(y2 - y1);
                double denominator = (double)(x2 - x1);
                double slope = numerator / denominator;
                mpp[slope]++;
            }
            for (auto x : mpp)
            {
                // we do x.second + count so that we add overlapping case and slopes count both
                // ans get maximum of it
                ans = max(ans, x.second + count);
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}