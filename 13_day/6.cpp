#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 7
// Lecture37: Recursion - Subsets / Subsequences of String [Theory + Code]

// Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).The solution set must not contain duplicate subsets. Return the solution in any order.

void solve(vector<int> nums,vector<int> output,int index, vector<vector<int>> &ans)
    {
        // base case
        if(index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // Exclude
        solve(nums,output,index+1,ans);

        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums,output,index,ans);
        return ans;
}

// Subsequences of String
// You are given a string 'STR' containing lowercase English letters from a to z inclusive. Your task is to find all non-empty possible subsequences of 'STR'.

void solve(string str, string output, int index, vector<string> &ans)
{
	// Base case
	if(index>= str.length())
	{
		// As the test case do not need empty string in output so we leave it
		if(output.length() > 0)
		{
     		ans.push_back(output);
		}
		return;
	}

	// Exclude
	solve(str,output,index+1,ans);

	// Include
	char element = str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){

	vector<string> ans;
	string output = "";
	int index = 0;
	solve(str,output,index,ans);
	return ans;
}


int main()
{
    return 0;
}
