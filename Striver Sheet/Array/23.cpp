#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array

Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no
such element exists, return an empty vector.

Example 1:
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

Example 2:
Input Format:  N = 6, array[] = {11,33,33,11,33,11}
Result: 11 33
Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.
*/

vector<int> majorityElement(vector<int> v)
{
    // Optimised approach using hashmap
    unordered_map<int, int> mpp;
    vector<int> ans;
    // floor(n/3) + 1 means for any number to be majority, it had to repeat > floor(n/3) times
    // floor(n/3) + 1 will be number of least occurence of a majority element so as soon we get it, store in the array
    // if we have one element in the array already, break out
    int mini = int(v.size() / 3) + 1;

    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;

        if (mpp[v[i]] == mini)
        {
            ans.push_back(v[i]);
        }
        if (ans.size() == 2)
            break; // means element has repeated in the ans array, we needed only 1 element so break out
    }

    // given in the question to sort the majority element array
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    return 0;
}