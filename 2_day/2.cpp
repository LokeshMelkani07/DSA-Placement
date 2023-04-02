#include<iostream>
using namespace std;

int main()
{
    // for loop
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"Printing counting from 1 to n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    // Using 2 variables in for loop
    for(int a=1,b=n;a<=n,b>=1;a++,b--)
    {
        cout<<a<<" "<<b<<" "<<endl;
    }
    // sum of n numbers
    int sum = 0;
    for(int i =1;i<=n;i++)
    {
        sum += i;
    }
    cout<<"sum is "<<sum<<endl;
    // Print first 10 numbers of Fibonacci series
    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";
    for(int i = 1;i<=n;i++)
    {
        int next = a+b;
        a = b;
        b = next;
        cout<<next<<" ";
    }
    cout<<endl;
    // Check number is prime or not
    // Use of break keyword
    int m = 70;
    bool flag = true;
    for(int i = 2;i<m;i++)
    {
        if(m%i==0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout<<"Number is prime"<<endl;
    }
    else{
        cout<<"Number is not prime"<<endl;
    }
    // Continue Keyword
    for(int i = 1;i<=5;i++)
    {
        cout<<"Hi"<<endl;
        cout<<"Hey"<<endl;
        continue;
        cout<<"Hello"<<endl;
    }
    return 0;
}