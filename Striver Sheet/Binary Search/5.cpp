#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
K-th Element of two sorted arrays

Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

Examples :

Input: m = 5
n = 4
array1 = [2,3,6,7,9]
array2 = [1,4,8,10]
k = 5

Output:
6

Explanation: Merging both arrays and sorted. Final array will be -
[1,2,3,4,6,7,8,9,10]
We can see at k = 5 in the final array has 6.

Input:
m = 1
n = 4
array1 = [0]
array2 = [1,4,8,10]
k = 2

Output:
4

Explanation:
Merging both arrays and sorted. Final array will be -
[1,4,8,10]
We can see at k = 2 in the final array has 4
*/

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // Brute force
    // Merge both arrays into one array
    // Sort that array
    // get the kth element
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        ans.push_back(row1[i]);
    }

    for (int j = 0; j < n; j++)
    {
        ans.push_back(row2[j]);
    }

    sort(ans.begin(), ans.end());

    return ans[k - 1];
}

int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k)
{
    // Optimised approach
    /*
    We can part it in such a way that our kth element will be at the end of the left half array. Let’s make some observations. The left portion of the array is made of some elements of both array1 and array2. We can see that all elements of the right half of the array are always larger than the left ones. So, with help of binary search, we will divide arrays into partitions with keeping k elements in the left half. We have to keep in mind that l1 <= r2 and l2 <= r1. Why so? This ensures that left-half elements are always lesser than right elements.
    Apply binary search in an array with a small size. Start iterating with two pointers, say left and right. Find the middle of the range. Take elements from low to middle of array1 and the remaining elements from the second array. Then using the condition mentioned above, check if the left half is valid. If valid, print the maximum of both array’s last element. If not, move the range towards the right if l2 > r1, else move the range towards the left if l1 > r2.
    Time Complexity : log(min(m,n))
    Reason: We are applying binary search in the array with minimum size among the two. And we know the time complexity of the binary search is log(N) where N is the size of the array. Thus, the time complexity of this approach is log(min(m,n)), where m,n are the sizes of two arrays.
    Space Complexity: O(1)
    Reason: Since no extra data structure is used, making space complexity to O(1).
    */

    // we will make partitions according to first array so we need arr1 as smaller
    if (m > n)
    {
        return ninjaAndLadoos(arr2, arr1, n, m, k);
    }

    // In our arr1, our search space is from 0 to m i.e size of arr1 we can take at max n element from arr1 or 0 element from arr1 but keeping in the mind the test cases, we decide high and low as

    // edge cases
    // if our k = 7 and arr2.size() = 6 means we need atleast one element from arr1 to fulfill the condition so in that case our
    // low = max(0,k-m)
    // if our k = 3 and our arr1.size() = 4, we cannot make parition at index= 4, in this case high = 3 so high = min(k,n)

    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        // we make a cut on arr1 to insert in left portion
        int cut2 = k - cut1;
        // remaining element we take from arr2 for left portion
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        // let say we make cut at index = 4 means we have to take all element from index 0 to 3 so we do cut1-1 for left portion
        // rest element from cut1 to end goes to right portion
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            // max(l1,l2) will give our kth element because we are taking
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}

int main()
{
    return 0;
}