#include<iostream>
using namespace std;

/*
1. https://leetcode.com/problems/power-of-two/
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

2. https://leetcode.com/problems/complement-of-base-10-integer/
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.Given an integer n, return its complement.

3. https://leetcode.com/problems/reverse-integer/
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

int reverse(int x) {
    // problem 1
        int ans = 0;
        while(x!=0)
        {
            int digit = x%10;

            if(ans>INT_MAX/10 || ans<INT_MIN/10)
            {
                return 0;
            }

            ans = (ans*10) + digit;
            x = x/10;
        }
        return ans;
}

int bitwiseComplement(int n) {
    // Problem 2
        int m = n;
        int mask = 0;
        int ans = 0;
        if(n==0)
        {
            return 1;
        }
        while(m!=0)
        {
            mask = (mask<<1) | 1;
            m = m>>1;
        }
        ans = (~n)&mask;
        return ans;
}

bool isPowerOfTwo(int n) {
        // Problem 3
        int ans = 1;
        for(int i = 0;i<=30;i++)
        {
            if(ans == n)
            {
                return true;
            }

            if(ans<INT_MAX/2)
            ans = ans*2;

        }
        return false;
}

int main()
{
    // Leetcode problem solving session
    cout<<reverse(10)<<endl;
    cout<<bitwiseComplement(10)<<endl;
    cout<<isPowerOfTwo(100)<<endl;
    return 0;
}