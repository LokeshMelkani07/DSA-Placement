#include<iostream>
using namespace std;

int main()
{
    // Variables and Scope
    int a = 2;
    cout<<a<<endl; // 2

    if(true)
    {
        // The below a is different from the above a as
        // Below 'a' has a block scope
        int a = 5;
        cout<<a<<endl;  // 5
        int b = 9; // this b cannot be accessed outside this block
    }
    cout<<a<<endl; // 2
    // cout<<b<<endl;  // error
    int b = 3;
    cout<<b<<endl; // 3

    // block inside block
    if(true){
      int c = 10;
      if(true)
      {
        int c = 11;
        cout<<c<<endl;  // 11
      }
    }
    return 0;
}