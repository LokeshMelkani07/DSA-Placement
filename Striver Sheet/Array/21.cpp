#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Implement Pow(x,n) | X raised to the power N

Problem Statement: Given a double x and integer n, calculate
x raised to power n. Basically Implement pow(x, n).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

double myPow(double x, int n)
{
    // Brute force
    // just 2^6 = 2*2*2*2*2*2
    // if 2^-4 is to be calculated we can write it as 1/2^4
    // So for n<0, we do x = 1/x and power = abs(power)
    // But this gives TLE because when we make it positive, it goes out of bound of int

    if (n < 0)
    {
        x = 1 / x;
        n = abs(n);
    }

    double ans = 1.0;

    for (int i = 0; i < n; i++)
    {
        ans = ans * x;
    }

    return ans;
}

double myPow(double x, int n)
{
    // Optimised approach
    // Binary exponentiation
    // 2^10 can be written as (2*2)^5 and
    // (2^2)^5 can be written as (4*4)^2
    // (4*4)^2 can be written as (16*16)^1
    // (16*16)^1 can be written as (256)*256^0 = 256
    // So we return 256 back to (4*4)^2 and so on at the end 2^10 = 1024
    // for n%2==0 i.e n is even, we do x = x*x and n = n/2
    // for n%2==1 i.e n is odd, we do ans = ans*x and n = n-1 which makes it even by doing n-1
    // TC: O(logn)
    double ans = 1.0;

    // copy the power
    long long power = n;

    // if its negative make it positive but in this conversion it may overflow so we take it long long
    if (power < 0)
        power = -1 * power;

    // till power is not 0
    while (power)
    {
        // if power is odd
        if (power % 2 == 1)
        {
            ans = ans * x;
            power = power - 1;
        }
        else
        {
            // if its even
            x = x * x;
            power = power / 2;
        }
    }

    // if n was negative do 2^-6 as 1/2^6
    if (n < 0)
        return (double)(1.0) / (double)(ans);

    return ans;
}

int main()
{
    return 0;
}