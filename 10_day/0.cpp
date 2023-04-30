#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Basic Mathematics for DSA
// Lecture 24
// Read notes of this lecture specially

// Tell Given Number is prime or not
bool isPrime(int n)
{
    // Brute force
    // TC: O(n^2)
    if(n<=1)
    {
        return false;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

// Given an integer n, return the number of prime numbers that are strictly less than n.
// Optimised code for finding the prime numbers
// Sieve of Eranothonas
int countPrimes(int n) {
        // TC: O(n*log(logn))
        vector<bool> prime(n+1,1);

        // to store count of prime numbers
        int count = 0;

        // mark 1 and 0 as non-prime
        prime[0] = prime[1] = false;

        for(int i = 2;i<n;i++)
        {
            if(prime[i])
            {
                count++;
                // mark all in the table of prime[i] as non-prime
                for(int j = 2*i; j<n;j=j+i)
                {
                    prime[j] = false;
                }
            }
        }

        return count;
}


// We use segemented sieve of eranothonas because normal sieve has a larger space coplecity and can prove to be worthless for bigger value of n
// In that, we decrease the search space into sqrt(n)


// GCD/HCF
int gcd(int a,int b)
{
    // gcd(a,b) = gcd(a-b,b) = gcd(a%b,b)
    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a!=b)
    {
        if(a>b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

// Relation between LCM and GCD
// LCM(a,b)*GCD(a,b) = a*b

// Modulo Exponentiation
int modularExponentiation(int x, int n, int m) {
	int res = 1;

	while(n>0)
	{
		if(n&1)
		{
			// odd
     		res = (1LL*res* (x)%m)%m;
		}
		x = (1LL*(x%m) * x%m)%m;
		n = n>>1; // means divide by 2
		// bit operations are less costly so we use them
	}

	return res;

}

int main()
{
    return 0;
}