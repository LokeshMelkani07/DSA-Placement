#include<iostream>
using namespace std;

// Lecture 31
// Recursion (First video)
int factorial(int n)
{
    // base case
    if(n==0)
    {
        return 1;
    }

    // Breakdown the problems into smaller one
    int smallerProblem = factorial(n-1);
    // Recurrence relation
    int largerProblem = n* smallerProblem;

    return largerProblem;
}

int power(int n)
{
    // Function to find power of 2
    if(n==0)
    {
        return 1;
    }

    // Recurrence relation
    int smallerProblem = power(n-1);
    int biggerProblem = 2*power(n-1);

    return biggerProblem;

}

// Print Reverse Counting
void print_reverse(int n)
{
    // Tail Recursion
    // Base case
    if(n==0)
    {
        return;
    }

    cout<<n<<" ";

    print_reverse(n-1);
}

// Print Counting
void print_counting(int n)
{
    // Head Recursion
    // Base case
    if(n==0)
    {
        return;
    }

    print_counting(n-1);

    cout<<n<<" ";
}

int main()
{
    int n;
    int m;
    // Find Factorial
    cout<<"Enter the number for finding factorial"<<endl;
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<factorial(n)<<endl;
    // Find power of 2
    cout<<"Enter the power of 2 to be found"<<endl;
    cin>>m;
    cout<<"2^"<<m<<" is "<<power(m);
    // Print Reverse Counting
    cout<<endl;
    print_reverse(5);
    // Print Counting
    cout<<endl;
    print_counting(5);
    return 0;
}