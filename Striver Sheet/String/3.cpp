#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
String to Integer (atoi)
Medium

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

    Read in and ignore any leading whitespace.
    Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
    Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
    Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    Return the integer as the final result.

Note:

    Only the space character ' ' is considered a whitespace character.
    Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.



Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.

Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
*/

int myAtoi(string s)
{
    // We know every string ends with a null terminator '\0'
    // We will start from index = 0
    // we will pick each element and do char - '0' to get its integer value
    // if value falls between 0 to 9 we store in the result by doing
    // result = result*10 + char
    // if its not a valid character like 'a' then ASCII value of 'a' is 97 so 'a' - '0' does not fall under 0 to 9 so return -1
    // do this till we reach null character
    int i = 0, n = s.size();

    while (s[i] == ' ')
    { // skipping space characters at the beginning
        i++;
    }

    int positive = 0, negative = 0;

    if (s[i] == '+')
    {
        positive++; // number of positive signs at the start in string
        i++;
    }

    if (s[i] == '-')
    {
        negative++; // number of negative signs at the start in string
        i++;
    }

    double ans = 0;

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        ans = ans * 10 + (s[i] - '0'); // (s[i] - '0') is converting character to integer
        i++;
    }

    if (negative > 0) // if negative sign exist
        ans = -ans;
    if (positive > 0 && negative > 0) // if both +ve and -ve sign exist, Example: +-12
        return 0;

    if (ans > INT_MAX) // if ans > 2^31 - 1
        ans = INT_MAX;

    if (ans < INT_MIN) // if ans < 2^31
        ans = INT_MIN;

    return (int)ans;
}

int main()
{
    return 0;
}