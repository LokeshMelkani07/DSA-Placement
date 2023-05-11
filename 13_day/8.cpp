#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 9
// Lecture39: Permutations of a String
// Permutations
// String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
/*
Sample Input 1:

3
abc
bc
c

Sample Output 1:

abc acb bac bca cab cba
bc cb
c

*/

void solve(vector<int> nums,int index, vector<vector<int>> &ans)
{
        // base case
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // Make swaps for each possible combination at a certain position
        for(int j = index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            solve(nums,index+1,ans);
            // Backtracking Step
            // We are making changes in the original string so let say in recursion we go from bac -> bca so while coming back its our duty to again make it bac so that further recursive calls can be made
            // so we swap index+1 with j again after making the recursive call
            swap(nums[index],nums[j]);
        }
}

vector<vector<int>> permute(vector<int>& nums)
{
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
}

int main()
{
    return 0;
}