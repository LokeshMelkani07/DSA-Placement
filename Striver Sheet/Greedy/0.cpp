#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
N meetings in one room

Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

Example:

Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

Output: 1 2 4 5
*/

struct meeting
{
    int start;
    int end;
    int pos;
};

bool static comp(struct meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // We will choose those meeting which finished earlier because this way we can do more meetings in a single room
    // We will take a data structure to store <start time, finish time, position of meeting in array>
    // We will traverse whole array and store all meetings in the DS
    // Now we sort the DS in order of increasing end time of meeting i.e ascending order
    // While storing in DS, if a meeting has same ending time as other, we store the first one first
    // We will maintain a variable endTime which stores the end time of previous selected meeting
    // We can only choose a meeting if its start time> endTime variable
    // We will start traversing the DS, and go till end considering endTime variable condition
    // TC: O(n) + O(nlogn) + O(n) = o(nlogn)
    // SC: O(n)
    // How to store Data Triplet in a Vector in C++?
    // To store three elements in a single cell of a vector we will creating a user defined structure and then make a vector from that user defined structure.
    int n = start.size();
    // struct meeting meet[n]; // right
    struct meeting meet[10]; // wrong
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }

    // sort the structure
    sort(meet, meet + n, comp);

    int endTime = meet[0].end;
    vector<int> answer;

    answer.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > endTime)
        {
            endTime = meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }

    return answer.size();
}

int main()
{
    return 0;
}
