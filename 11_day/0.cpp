#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Pointers in C++

int main()
{
    // symbol table will map num with some mememory address where 5 is stored
    int num = 5;
    cout<<num<<endl;

    // address of operator (&)
    cout<<"address of num is "<<&num<<endl;

    // Pointer
    // Always initialise a pointer either by 0 if nothing a vaiable but always initialise it
    int *ptr = &num;
    cout<<"Address at ptr is "<< ptr<<endl;
    cout<<"Value at pointer is "<<*ptr<<endl; // 6
    num++;
    cout<<"Value at pointer after increment is "<<*ptr<<endl;  // 6
    // pointer can be of different data type
    double d = 5.4;
    double *p2 = &d;

    cout<<p2<<endl;
    cout<<*p2<<endl;

    // Size of pointer
    cout<<"Size of int data type is "<<sizeof(int)<<endl; // 4
    cout<<"Size of pointer to int data type is "<<sizeof(ptr)<<endl; // 4
    cout<<"Size of double data type is "<<sizeof(d)<<endl;  // 8
    cout<<"Size of pointer to double data type is "<<sizeof(p2)<<endl;  // 4

    // pointer to int is created which is pointing to some garbage value [BAD PRACTICE]
    //  int *p;
    int *p = 0;  // atleast do this as segamentation fault will come as 0 is not a memory whihc exist

    // Other way of storing value in pointer
    int i = 150;
    int *p1 = 0;
    p1 = &i;
    cout<<p1<<endl;
    cout<<*p1<<endl;

    int num1 = 5;
    int *p3 = &num1; // reference to that block means the address is stored in p3 so any change in value will be reflected in p3 also
    int a = num1; // copy of num1 is stored in a
    num1++; // if we ++ num1, it will not affect a
    cout<<num1<<endl; // 6
    cout<<a<<endl;  // 5
    cout<<*p3<<endl;  // 6
    (*p3)++;  // *p3 means value at num1 address, which is 6 currently, *p3++ means 6->7
    cout<<num1<<endl; // 7
    cout<<*p3<<endl;  // 7


    // Copying pointers
    int *q = p3;
    cout<<"Address at p and q is "<<"p3 "<<p3<<" "<<" q "<<q<<endl; // same address of both
    cout<<"value at p and q is "<<"p3 "<<*p3<<" "<<" q "<<*q<<endl; // 7 , 7
    (*p3)++;
    cout<<"value at p and q is "<<"p3 "<<*p3<<" "<<" q "<<*q<<endl;  // 8 , 8


    // Pointer Arithmetic
    int j = 9;
    int *p4  = &j;
    cout<<(*p4)++<<endl; // 9
    // p4 is now 10
    *p4 = *p4 + 1;  // p4 is now 1+1 = 11
    cout<<*p4<<endl; // 11
    cout<<p4<<endl;  // 0x61fe84
    p4 = p4+1;  // it will add 4 bytes in the memory address and move to next integer
    cout<<p4<<endl; // 0x61fe88
    cout<<*p4<<endl; //  8

    // Void pointer
    // Pointer of type vpid which can be typecasted to any other type. void *ptr;
    // Wild pointer
    // which is not initialsed and is pointing to any random garbage value
    return 0;
}
