#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Job Sequencing Problem

Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

Examples

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60

Example 2:

Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}

Output: 2 127

Explanation: The  first and third job both having a deadline 2 give the highest profit.
Profit = 100 + 27 = 127
*/

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[2] > b[2])
        return true;
    return false;
}
vector<int> jobScheduling(vector<vector<int>> &Jobs)
{
    // {job id, job deadline, job profit}
    // Each job takes 1 unit time so let say JobA has deadline = 6 we can finish that on any of the 1,2,3,4,5,6 day
    // Means we can finish it in 6 days and generally we tend to perform job in the last deadline day
    // What we can do is, to max profit, we sort the array based on profit in descending order
    // We see max deadline and make array of that size initialised with -1
    // we use index of that array as deadline date and store job id in it
    // We make a variable to store profit
    // Let say max deadline is 6 so we make a array of size 6
    // Let say 6th block is already occupied, now we have another job of deadline  = 6 so we can check in the array if any other block before 6 is empty or not
    // and assign that job on that day
    // if a job has deadline = 4, we traverse the array from 4th block backward and check the empty day and assign the job
    sort(Jobs.begin(), Jobs.end(), comp);
    int n = Jobs.size();

    // make a array of max deadline size
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, Jobs[i][1]);
    }

    // int arr[maxi + 1]; // right
    int arr[1000]; // wrong

    // Initialise it with -1
    for (int i = 0; i <= maxi; i++)
    {
        arr[i] = -1;
    }

    // Start traversing
    arr[0] = Jobs[0][0];
    int countJobs = 0;
    int Profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = Jobs[i][1]; j >= 0; j--)
        {
            if (arr[j] == -1)
            {
                countJobs++;
                Profit += Jobs[i][2];
                arr[j] = Jobs[i][0];
                break;
            }
        }
    }

    return {countJobs, Profit};
}

int main()
{
    return 0;
}