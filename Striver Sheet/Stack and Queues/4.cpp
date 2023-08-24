#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
Check for Balanced Parentheses

Problem Statement: Check Balanced Parentheses. Given string str containing just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ and ‘]’, check if the input string is valid and return true if the string is balanced otherwise return false.

Note: string str is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
*/

bool isValidParenthesis(string s)
{
    // Take each opening character in the stack
    // if its not a opening char,it must be closing one then check stack top, if thats opening of that same char
    // pop it out else return false
    // At the end if its valid, stack should get empty
    // TC: O(n), SC: O(n)
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.size() == 0)
            {
                return false;
            }

            if (s[i] == '}')
            {
                if (st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }

            if (s[i] == ')')
            {
                if (st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }

            if (s[i] == ']')
            {
                if (st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
        }
    }
    return st.empty() ? true : false;
}

int main()
{
    return 0;
}