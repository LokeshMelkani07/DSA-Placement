#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Median of Two Sorted Arrays of different sizes

Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
Examples

Example 1:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result: 3.5
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result: 3
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.
*/

double median(vector<int> &a, vector<int> &b)
{
    // Simple solution can be to store both in a single vector
    // sort that vector
    // median is arr[arr.size()/2] if size = odd
    // median is (arr[size()/2] + arr[size-1/2]) /2 if size = even
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }

    for (int j = 0; j < b.size(); j++)
    {
        ans.push_back(b[j]);
    }

    sort(ans.begin(), ans.end());

    int n = ans.size();
    if (n % 2 == 0)
    {
        return (double)(ans[n / 2.0] + ans[(n - 1) / 2.0]) / 2.0;
    }

    return (double)(ans[n / 2.0]);
}

double median(vector<int> &a, vector<int> &b)
{
    // Optimised approach
    // As both arrays are sorted, we can think of applying binary search
    // We know if length of merged array is 10 (even)
    // there will be 5 element in left half and 5 element in right half
    // median is (max of left half + min of right half) / 2
    // if length is odd, say 11
    // there will be 6 element in left half and 5 element in right half
    // them median is max element of left half
    // Now how to do partition of left half and right half
    // let say n1 = 5, n2 = 5 be length of arr1 and arr2
    // we take 3 element from n1 and 2 element from n2 for left half and so on for right half
    // element we take from n1 in left < element we take from n1 in right as arr1 is sorted
    // sameway for arr2 also
    // Let say l1 = last element of partition we take from arr1 in left half
    // Let say l2 = last element of partition we take from arr2 in left half
    // Let say r1 = last element of partition we take from arr1 in right half
    // Let say r1 = last element of partition we take from arr2 in right half
    // l1 < r1 always as arr1 is sorted
    // l2 < r2 always as arr2 is sorted
    // we need to check if l1<r2 and l2<r1, if yes,then its a valid partition
    /*
        If l1 <= r2 && l2 <= r1: We have found the answer.
        If (n1+n2) is odd: Return the median = max(l1, l2).
        Otherwise: Return median = (max(l1, l2)+min(r1, r2)) / 2.0

        If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. So, we have to take less elements from arr1[] and more from arr2[]. In such a scenario, we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid1-1).

        If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. So, we have to take less elements from arr2[] and more from arr1[]. In such a scenario, we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid1+1).
    */

    int n1 = a.size(), n2 = b.size();
    // if n1 is bigger swap the arrays as we need smaller size array at first place:
    //  First, we have to make sure that the arr1[] is the smaller array. If not by default, we will just swap the arrays. Our main goal is to consider the smaller array as arr1[].
    if (n1 > n2)
        return median(b, a);

    int n = n1 + n2;              // total length
    int left = (n1 + n2 + 1) / 2; // length of left half
    // apply binary search:
    int low = 0, high = n1; // our search space will be arr1[]
    while (low <= high)
    {
        int mid1 = (low + high) >> 1; // or just do (low+high)/2;
        int mid2 = left - mid1;       //
        // calculate l1, l2, r1 and r2;
        //  l1 and l2 are <median so we take by default as INT_MIN
        //  r1 and r2 are >median so we take by default as INT_MAX
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        // we make a partition at index mid1 means left will have element will index mid1-1 and mid2-1
        // right will have element from index mid1 and mid2
        // we check validity of mid1 and mid2 if they are valid indexes
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            // based on length of total array is even or odd, median formula changes
            // max(l1, l2) + min(r1, r2)/2 means as we know left half ka highest element will be (median-1)th and right half ka least element will be (median+1)th
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0; // dummy statement
}

int main()
{
    return 0;
}