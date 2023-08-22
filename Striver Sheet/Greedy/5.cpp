#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Maximum activities (Same as N meetings in a room)
You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.
*/

struct activity
{
    int start;
    int end;
    int pos;
};

bool comp(struct activity a1, struct activity a2)
{
    if (a1.end < a2.end)
        return true;
    else if (a1.end > a2.end)
        return false;
    else if (a1.pos < a2.pos)
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Same as N meetings in a room
    // Make a DS and store start,end,pos in it
    // We will sort the DS on basis of end time and position in case of same end time
    int n = start.size();
    // struct activity act[n];  //right
    struct activity act[100]; // wrong

    for (int i = 0; i < n; i++)
    {
        act[i].start = start[i];
        act[i].end = finish[i];
        act[i].pos = i + 1;
    }

    sort(act, act + n, comp);

    int endTime = act[0].end;
    int activities = 1;

    for (int i = 1; i < n; i++)
    {
        if (act[i].start >= endTime)
        {
            endTime = act[i].end;
            activities++;
        }
    }

    return activities;
}

int main()
{
    return 0;
}