#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Roman to Integer
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

int romanToInt(string s)
{
    // we can do one thing
    // store all the mapping of symbols inside a map
    // store the last element in result
    // now start traversing from end of string
    // pick the element and check if its value in int in smaller or greater than its next element
    // if its smaller than update result with next ele - current ele
    // if its larger, update result with curr ele + next ele
    // update the result this way
    // return result
    unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int result = mp[s.back()];
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            result = result - mp[s[i]];
        }
        else
        {
            result = result + mp[s[i]];
        }
    }
    return result;
}

int main()
{
    return 0;
}