#include<iostream>
using namespace std;

int main()
{
    // Bitwise operator
    int a = 4;
    int b = 6;
    cout<<"a&b "<<(a&b)<<endl;
    cout<<"a|b "<<(a|b)<<endl;
    cout<<"~a "<<(~a)<<endl;
    cout<<"a^b "<<(a^b)<<endl;
    // left shift, right shift operator
    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(19<<1)<<endl;
    cout<<(21<<2)<<endl;
    // pre/post increment/decrement operator
    int i = 7;
    cout<<(++i)<<endl; // 8
    cout<<(i++)<<endl; // 8
    cout<<(i--)<<endl; // 9
    cout<<(--i)<<endl; // 7
    return 0;
}