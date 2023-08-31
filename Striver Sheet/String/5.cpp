#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Count and Say
The Look-And-Say sequence is a sequence of positive integers. The sequence is as follows:
1, 11, 21, 1211, 111221, 312211, 13112221,...
The first number is 1.

This is read as “One 1”.
Hence, the second number will be 11.

The second number is read as “Two 1s”.
Hence, the third number will be 21.

The third number is read as “One 2, One 1”.
Hence, the fourth number will be 1211. And so on.

The fourth term is read as “One 1, One 2, Two 1s”.

Hence, the fifth term will be 111221. And so on.
Given an integer N, find the Nth term of the sequence.
Sample Input 1:

3
1
2
3

Sample Output 1:

1
11
21

Explanation for Sample 1:

The first term is 1.

The second term is 11.

The third term is 21.

Sample Input 2:

1
6

Sample Output 2:

312211

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/

string countAndSay(int n)
{
    if (n == 0)
        return "";
    string res = "1"; // base case
    while (--n)
    {
        string cur = "";
        for (int i = 0; i < res.size(); i++)
        {
            int count = 1;
            while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
            {
                // keep on counting till number values are same
                count++;
                i++;
            }
            // once we encounter different number
            // add count into the result string for that number + that number
            cur += to_string(count) + res[i];
        }
        // update result value for that value of n
        res = cur;
    }
    return res;
}

int main()
{
    return 0;
}