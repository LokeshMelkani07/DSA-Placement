#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find the repeating and missing numbers

Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
*/

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Brute force approach
    // we have numbers from 1 to n in the array
    // so we run a outer loop for i = 1 to i=n
    // we run a inner loop to check whether that number is any elment of the array or not
    // we make a count variable and store count of that number
    // After inner loop ends, number having count=2 will be the repeating one and
    // Number with count = 0 will be the missing one
    // if we have found values for both repeating and missing then we break the loop and return the answer
    int n = a.size();
    int repeating = -1, missing = -1;
    // outer loop to check for each number between 1 to n
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        // Inner loop to compare each element of array with number between 1 to n
        for (int j = 0; j < n; j++)
        {
            // count++ if number is found
            if (a[j] == i)
                count++;
        }

        // count =2 means number is repeating
        // count = 0 means number is missing
        if (count == 2)
            repeating = i;
        else if (count == 0)
            missing = i;

        // if we have values for both repeating and missing, then break the loop and return the answer
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }

    return {repeating, missing};
}
/*
vector<int> findMissingRepeatingNumbers1(vector<int> a)
{
    // Better approach
    // we will make a hashmap and store number from 1 to n with 0 value initially
    // we will use a hashmap to store the occurences of all number between 1 to n
    // after storing the count of all elements of array inside hashmap
    // we will now check if occurence in hashmap = 2 or 0 and so same as previous
    int n = a.size();
    int repeating = -1, missing = -1;
    // initialised an array with n+1 elements with 0 value initially
    int hash[n + 1] = {0};

    // store values of array in hashmap
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    // check hashmap now for 1 to n
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}
*/

int main()
{
    return 0;
}
