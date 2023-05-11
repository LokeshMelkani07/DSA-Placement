#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 8
// Lecture38: Phone Keypad Problem Recursion

// Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

void solve(string digits,string output,int index,vector<string> &ans,string mapping[])
  {
      // base case
      if(index>=digits.length())
      {
          ans.push_back(output);
          return;
      }

      // Convert as digit[index] will give us "2" as a character, we need it as a integer so we do - '0'
      int element = digits[index] - '0';
      // Instead of above step we can also use, digit[index] in place of int element directly
      cout<<element<<endl;
      cout<<endl;
      string value = mapping[element];
      for(int i = 0;i<value.length();i++)
      {
          output.push_back(value[i]);
          solve(digits,output,index+1,ans,mapping);
          // Backtracking step
          output.pop_back();
      }
  }

vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return {};
        }
        vector<string> ans;
        string output = "";
        int index = 0;
        string mapping[10] = {"","" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
}

int main()
{
    return 0;
}