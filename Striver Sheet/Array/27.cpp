#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
3 Sum : Find triplets that add up to a zero

Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

Example 2:

Input: nums=[-1,0,1,0]
Output: Output: [[-1,0,1],[-1,1,0]]
Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k

*/

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Brute force
    /*
    First, we will declare a set data structure as we want unique triplets.
    Then we will use the first loop(say i) that will run from 0 to n-1.
    Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
    Then there will be the third loop(say k) that runs from j+1 to n-1.
    Now, inside these 3 nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k], and if it is equal to the target i.e. 0 we will sort this triplet and insert it in the set data structure.
    Finally, we will return the list of triplets stored in the set data structure.
    */

    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Better force, try to reduce 3 loops to 2 loops
    /*
    First, we will declare a set data structure as we want unique triplets.
    Then we will use the first loop(say i) that will run from 0 to n-1.
    Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
    Instead of using one more loop for k, we use formula.
    arr[i]+arr[j]+arr[k] = 0 means arr[k] = -(arr[i]+arr[j])
    Inside second loop we use another hashSet
    We find arr[k] in the hashset and if found we add it in the temp array
    if not found, we store arr[j] in the hashSet
    we will sort this triplet and insert it in the set data structure.
    Finally, we will return the list of triplets stored in the set data structure.
    */

    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Most Optimal approach
    // we will get rid of hashSet and set now
    // set was used to store unique triplet
    // hashset was used to sorted element
    // Instead we use, 3 pointers. i,j,k where i is fixed and j and k are moving
    // To get sorted values we sort the array first
    // To get unique values we check i,j,k should have different value other just move them

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // Remove duplicates
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        // point j next to i
        int j = i + 1;
        // point k from back
        int k = n - 1;

        // Now move j forward and k backward till they cross each other
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                // means increase j
                j++;
            }
            else if (sum > 0)
            {
                // means decrease k
                k--;
            }
            else
            {
                // we have founf one triplet
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                // Remove duplicates
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                // Remove duplicates
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}