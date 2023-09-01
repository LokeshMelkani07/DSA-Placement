#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Minimum Characters For Palindrome
Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string a palindrome.
For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.
Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string “acaabaaca” palindrome.
Sample input 1 :

2
abcd
dad

Sample output 1 :

3
0

Explanation of sample input 1 :

For test case 1 :
Minimum characters to be added at front to make it a palindrome are 3 i.e. “dcb” which makes the string “dcbabcd”.

For test case 2 :
The string is already a palindrome, we do not need to add any character.

Sample input 2 :

2
xxaxxa
abb

Sample output 2 :

1
2
*/

bool isPalindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}
int minCharsforPalindrome(string str)
{
    // We see given str = "abc"
    // To make it palindrome we need to add "cb" at the front
    // We make a counter added
    // We check the string if its palindrome and if its not then
    // we increase the added counter and send substr(0,n-added) and check if thats palindrome
    // again if its not we increase the added counter and again send substring
    // this way, we return added at the end
    // This solution is o(n2) we need solution in O(n)
    int added = 0;
    int n = str.length();

    while (n > 0)
    {
        if (isPalindrome(str.substr(0, n - added)))
            break;
        else
            added++;
    }

    return added;
}

int minCharsforPalindrome(string str)
{
    // Solution in O(n)
    // We will shift the last index
    // Do all the calculations inside one loop only
    // we keep track of last index
    // what is an palindrome??
    // when element from front and element from end are equal?
    // so we keep i at front, j at end
    // if both are equal we move them
    // else we neglect last_index, again start i from 0 but now we put j at last_index
    // we do this till i<=j
    // at the end number of element to be added in the front will be equal to n-1 - last_index
    int n = str.length();
    int i = 0;
    int j = n - 1;
    int last_index = n - 1;

    while (i <= j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            i = 0;
            last_index--;
            j = last_index;
        }
    }
    int added = n - 1 - last_index;

    return added;
}

int main()
{
    return 0;
}