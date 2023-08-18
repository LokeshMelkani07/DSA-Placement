#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Count Reverse Pairs
Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Example 1:

Input: N = 5, array[] = {1,3,2,3,1)

Output: 2

Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Example 2:

Input: N = 4, array[] = {3,2,1,4}

Output: 1

Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]
*/

int team(vector<int> &skill, int n)
{
    // Brute force solution
    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // j always > i so j = i+1 to n-1
        for (int j = i + 1; j < n; j++)
        {
            if (skill[i] > 2 * skill[j])
                cnt++;
        }
    }
    return cnt;
}

// Optimised, using merge sort
// Below is the code for merge sort only
// Problem is same as: Count reverse pairs
// We will use merge sort algo here also
// Like we did in count inversion pairs but here we need to write seperate function to count reverse pairs

void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        // whichever is smaller add in the temp first
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // copy all elements of arr1 if some are left
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // copy all elements of arr2 if some are left
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copy temp in the arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{

    int mid = (low + high) / 2;

    if (low >= high)
        return;

    // merge sort left array
    mergeSort(arr, low, mid);
    // merge sort right array
    mergeSort(arr, mid + 1, high);
    // merge both arrays
    merge(arr, low, high, mid);
}

int team(vector<int> &skill, int n)
{
    int low = 0;
    int high = n - 1;
    mergeSort(skill, low, high);
    for (auto i : skill)
    {
        cout << i << " ";
    }
    cout << endl;
    return 1;
}

// Now we apply some modifications in the merge sort code to get the answer
// Problem is same as: Count reverse pairs
// We will use merge sort algo here also
// Like we did in count inversion pairs but here we need to write seperate function to count reverse pairs

/*
Time Complexity: O(2N*logN), where N = size of the given array.
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/

void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        // whichever is smaller add in the temp first
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // copy all elements of arr1 if some are left
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // copy all elements of arr2 if some are left
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copy temp in the arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

// Modification
int countInversion(vector<int> &arr, int low, int mid, int high)
{
    // we will take each element from arr1 in the outer loop
    // we will check each element from arr2 for each element of arr1
    // at the end we will add number of elements from arr2 satisfying our coniditon for each element of arr1
    int right = mid + 1;
    int count = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        count += (right - (mid + 1)); // to get number of element satisfying the condition we do right - (mid+1)
        // as starting index of our arr2 is mid+1 and right is positioned at the element till which our condition satisfies for that arr[i]
    }

    return count;
}

int mergeSort1(vector<int> &arr, int low, int high)
{

    int mid = (low + high) / 2;
    int count = 0; // Modification

    if (low >= high)
        return count;

    // merge sort left array
    count += mergeSort1(arr, low, mid);
    // merge sort right array
    count += mergeSort1(arr, mid + 1, high);
    // Before merging them we will count the pairs by following the conditions
    count += countInversion(arr, low, mid, high);
    // merge both arrays
    merge(arr, low, high, mid);

    return count;
}

int team(vector<int> &skill, int n)
{
    int count = 0;
    int low = 0;
    int high = n - 1;
    count = mergeSort1(skill, low, high); // Modification
    return count;
}

int main()
{
    return 0;
}