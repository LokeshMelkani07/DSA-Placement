#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Pointers in C++ (part 3)
// Advanced pointers

void update(int **ptr)
{
    // No change as copy of it will be made
    // ptr = ptr + 1;

    // change will come 0x61feb4 -> 0x61febc
    // In double pointer *ptr means value at double pointer which is nothing but address of ptr1
    // *ptr + 1 means add one block to that address
    // *ptr = *ptr + 1;

    // Change Will come
    // **ptr contain value inside ptr1 which is value of i so it will increment value by 1
    // Value of i changes from 5 to 6
    // rest remains same
    **ptr = **ptr + 1;

}

int main()
{
    int i = 5;
    int *ptr = &i;
    // Double Pointer
    int **ptr2 = &ptr;

    cout<<ptr<<endl;  // 0x61feb8
    cout<<*ptr2<<endl; // 0x61feb8
    cout<<ptr2<<endl;  // 0x61feb4
    cout<<**ptr2<<endl; // 5
    cout<<&i<<endl; // 0x61feb8
    cout<<ptr<<endl; // 0x61feb8
    cout<<*ptr2<<endl; // 0x61feb8
    cout<<&ptr<<endl; // 0x61feb4
    cout<<ptr2<<endl; // 0x61feb4

    // Double Pointers and FUnctions
    cout<<endl;
    cout<<"Before"<<endl;
    cout<<"i "<<i<<endl;
    cout<<"ptr "<<ptr<<endl;
    cout<<"ptr2 "<<ptr2<<endl;
    update(ptr2);
    cout<<endl;
    cout<<"After"<<endl;
    cout<<"i "<<i<<endl;
    cout<<"ptr "<<ptr<<endl;
    cout<<"ptr2 "<<ptr2<<endl;
    return 0;
}