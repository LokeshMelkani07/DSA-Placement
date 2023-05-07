#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Macros, Global Variables, Inline Functions & Default Args

// A piece of code in program which is replaced by value of macro.
// Defining a macro which does not consumer memory whereas creating a variable consumes some memory
// At compile time all PI will be replaced by 3.14 in our code
// PI cannot be updated like PI = PI + 1 whereas we can change the value of variable which can create wrong answers
#define PI 3.14

// Global Variable
// A variable which can be accessed anywhere in the program
// Use of global varibale is a BAD Practice because its value can be updated by any function which will get reflected everywhere which is harmful for our program
int score = 15;

void a(int& i)
{
    cout<<"Score from a is "<<score<<endl;
}

void b(int& i)
{
    cout<<"Score from b is "<<score<<endl;
}


// Inline Function
// It helps us in reducing overhead function calls
// We can use ternary operator
/*
int getMax(int &a,int &b)
{
    return (a>b)?a:b;
}
*/
// we make above function inline
// we make above function inline just write inline ahead return type
// if function body is one liner we can make it inline
inline int getMax(int &a,int &b)
{
    return (a>b)?a:b;
}

// Default Arguments
// To make a function argument optional we use it
// If value mile toh use krle vrna ek default arguement use krle
// int start = 0 is our default arguement
// Always make rightmost arguement as the default argument first
// we cannot make n as default arg if start is not an default arg
// We can make all arguments as default arguements also
void print(int arr[],int n,int start = 0)
{
    for(int i= start;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

// Constant Variable
// const int a = 5;
// we cannot write like const int a; and intiialise a below (WRONG)
// we can also use const with pointers
/*
    1. int value = 5;         // non-const value

    2. const int *ptr_1 = &value;  // ptr_1 points to a “const int” value, so this is a pointer to a const value.

    3. int *const ptr_2 = &value;  // ptr_2 points to an “int”, so this is a const pointer to a non-const value.

    4. const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.
*/


int main()
{
    int r = 5;
    // int area = 3.14*r*r;
    int area = PI*r*r;
    cout<<"Area is "<<area<<endl;

    // Global Variable
    cout<<"Score from main is "<<score<<endl;
    a(r);
    b(r);
    // Use of global varibale is a BAD Practice because its value can be updated by any function which will get reflected everywhere which is harmful for our program


    // Inline Function
    int i = 5;
    int j = 6;
    string ans;
    // Ternary Operator
    ans = (i>j) ? "i is greater" : "J is greater";
    cout<<ans<<endl;
    i = i+3;
    j = j+1;
    ans = (i>j) ? "i is greater" : "J is greater";
    cout<<ans<<endl;
    // we are using same syntac (i>j) again and again instead we make a function
    cout<<getMax(i,j)<<endl;
    // we make above function inline just write inline ahead return type
    // if function body is one liner we can make it inline



    // Default Arguments
    // To make a function argument optional we use it
    // If value mile toh use krle vrna ek default arguement use krle
    int arr[] = {1,2,3,4,5};
    int n = 5;
    print(arr,n); // 1 2 3 4 5
    cout<<endl;
    print(arr,n,3); // 4 5
    return 0;
}