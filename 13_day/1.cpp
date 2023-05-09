#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion Day 2

// Recursion by Example
void reachHome(int src,int dest)
{
    cout<<"Source "<<src<<" "<<"Destination "<<dest<<endl;
    // Base case
    if(src==dest)
    {
        cout<<"Reached Home"<<endl;
        return;
    }

    // Processing
    src++;
    // Recursive call
    reachHome(src,dest);
}

// Fibonacci series
 int fib(int n) {
        // base case
        if(n==0)
            return 0;
        // base case
        if(n==1)
            return 1;

        // Recurrence relation
        int ans = fib(n-1) + fib(n-2);

        return ans;
}

// Count Ways To Reach The N-th Stairs
// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.
int countDistinctWays(int nStairs) {
    // base case
    if(nStairs<0)
    {
        return 0;
    }

    // base case
    if(nStairs==0)
    {
        return 1;
    }

    // Recurrence relation
    // Either it will jump from n-1 stair or n-2 stair
    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);

    return ans;
}

// Say Digits
// input: 412, output: four one two

void sayDigits(int n,string arr[])
{
    // base case
    if(n==0)
    {
        return;
    }

    int digit = n%10;

    n = n/10;

    sayDigits(n,arr);

    cout<<arr[digit]<<" ";
}

int main()
{
    int destination = 10;
    int source = 1;
    // reachHome(source,destination);

    // say digit question
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    string arr[] = {"zero","one","two","three","four","five","sixth","seven","eigth","nine"};

    sayDigits(n,arr);





    return 0;
}
