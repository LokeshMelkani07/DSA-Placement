#include<iostream>
using namespace std;

 int subtractProductAndSum(int n) {
    // Problem 1
        int product = 1;
        int sum = 0;
        while(n)
        {
            product *= n%10;
            sum += n%10;
            n = n/10;
        }
        return product-sum;
}

int hammingWeight(uint32_t n) {
    // Problem 2
        // check last bit
        // right shift it everytime by 1 till the time number becomes 0
        int count = 0;
        while(n)
        {
            if(n&1)
            {
                count++;
            }
            n = n>>1;
        }
        return count;
    }

int main()
{
    // Leetcode problem solving session
    // Problem link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
    // Given an integer number n, return the difference between the product of its digits and the sum of its digits.
    cout<<subtractProductAndSum(234)
    <<endl;
    // Problem 2
    // https://leetcode.com/problems/number-of-1-bits/
    // Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
    cout<<hammingWeight(11)<<endl;

    return 0;
}