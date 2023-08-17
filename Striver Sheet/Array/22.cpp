#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

Example 1:
Input Format: N = 3, nums[] = {3,2,3}
Result: 3
Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

Example 2:
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

Result: 2

Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

Example 3:
Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}

Result: 4
*/

int majorityElement(vector<int> v)
{
    // Brute force
    // Take each element and check if its occurs in array more than n/2 time or not
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j])
                count++;
        }
        if (count > v.size() / 2)
            return v[i];
    }

    return -1;
}

int majorityElement(vector<int> v)
{
    // Optimised approach we can use a Hashmap
    unordered_map<int, int> mpp;

    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }

    for (auto x : mpp)
    {
        if (x.second > v.size() / 2)
        {
            return x.first;
        }
    }

    return -1;
}

int majorityElement(vector<int> v)
{
    // Most optimal algo with o(1) SC
    // We apply Moore's voting algo
    // We will start from beginnning of array, we take element and count variable
    // elements store the current element
    // count stores the count of that element
    // Let element = first element of array
    // As we move forward, we count++ on encountering an element = our current element
    // We do count-- on encountering a different element
    // If count==0 anytime, then element with change to current arr[i] and count = 1, this way
    // we modify count and element, at the end value of our element will give the majority element in the array
    // At the end, again traverse the whole array and make sure to check if element occurs > N/2 times in the array
    int element = v[0], count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element)
        {
            // if element is same as v[i]
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            // set count = 1 and change the element to v[i]
            count = 1;
            element = v[i];
        }
    }

    int cnt1 = 0;
    // check if element occur >N/2 times or not
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element)
            cnt1++;
    }

    if (cnt1 > v.size() / 2)
        return element;

    return -1;
}

int main()
{
    return 0;
}