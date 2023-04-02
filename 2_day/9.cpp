#include<iostream>
using namespace std;

int powerofnumber(int a,int b)
{
    // Find a ki power b
    int ans = 1;
    for(int i = 1;i<=b;i++)
    {
        ans = ans*a;
    }
    return ans;
}

bool oddEven(int n)
{
  // Check number is odd or even
  if(n%2==0)
  {
    return true;
  }
  else{
    return false;
  }
}

/*
nCr = n! / r! * (n-r)!
*/

// Print factorial till n
int factorial(int n)
{
    int fact = 1;
    for(int i=1;i<=n;i++)
    {
        fact= fact*i;
    }
    return fact;
}

// Print nCr
int nCr(int n,int r)
{
   int num = factorial(n);
   int deno = factorial(r)*factorial(n-r);
   int ans = num/deno;
   return ans;
}

void printCounting(int n)
{
    // Print counting from 1 to n
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
}

// Check its a Prime number or not
bool PrintPrime(int n)
{
   for(int i = 2;i<n;i++)
   {
    if(n%i==0)
    {
        return false;
    }
   }
   return true;
}

int main()
{
    // Functions
    cout<<powerofnumber(12,2)<<endl;
    cout<<oddEven(9)<<endl;
    cout<<nCr(8,2)<<endl;
    printCounting(10);
    cout<<endl;
    cout<<PrintPrime(7)<<endl;
    return 0;
}