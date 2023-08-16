#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order(i.e., sorted in ascending order).

void nextPermutation(vector<int> &nums)
{
    // Intituion is based on the fact that there is some mountain like symmetry in all lexographic order of any number in dictionary so we use this approach
    // we will first find the break point that is
    // ind1 such that nums[ind1] < nums[ind1+1] for that we need to start travel from second last index so that runtime error do not come
    // if there is no such index means just reverse the array and thats the answer
    // if there exists such index then, find one more index that is just greater than ind1 such that nums[i] > nums[ind1]
    // swap(nums[i],nums[ind1])
    // reverse the array ahead i till last element

    int n = nums.size();
    if (n == 0 || n == 1)
    {
        return;
    }

    int ind1 = -1;
    // finding ind1 i.e break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind1 = i;
            break;
        }
    }

    // if break point not found
    if (ind1 == -1)
    {
        // reverse
        reverse(nums.begin(), nums.end());
        return;
    }
    else
    {
        // break point found
        int ind2;
        for (int j = n - 1; j > ind1; j--)
        {
            if (nums[j] > nums[ind1])
            {
                ind2 = j;
                break;
            }
        }

        // swap
        swap(nums[ind1], nums[ind2]);

        // reverse
        reverse(nums.begin() + ind1 + 1, nums.end());
        return;
    }
}

int main()
{
    return 0;
}