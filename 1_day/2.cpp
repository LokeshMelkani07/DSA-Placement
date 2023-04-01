#include <iostream>
using namespace std;

// Data type and variable

int main()
{
    int a = 123;
    cout<<a<<endl;
    cout<<"size of a is "<<sizeof(a)<<endl;
    char b = 'v';
    cout<<b<<endl;
    cout<<"size of b is "<<sizeof(b)<<endl;
    bool bl = true;
    cout<<bl<<endl;
    cout<<"size of bl is "<<sizeof(bl)<<endl;
    float f = 1.2;
    cout<<f<<endl;
    cout<<"size of f is "<<sizeof(f)<<endl;
    double d = 1.23;
    cout<<d<<endl;
    cout<<"size of d is "<<sizeof(d)<<endl;
    // Type casting
    int ab = 'a';
    cout<<ab<<endl;
    char ch = 98;
    cout<<ch<<endl;
    unsigned abc = 111;
    cout<<abc<<endl;
    // Operator
    // int/int = always int
    // float/int = always float
    // double/int = always double
    float a_1 = 0.2/5;
    cout<<a_1<<endl;
    // Relational operator
    int a_b = 1;
    int bc = 2;
    bool first = (a_b==bc);
    cout<<first<<endl;
    bool first_1 = (a_b>bc);
    cout<<first_1<<endl;
    bool first_2 = (a_b<bc);
    cout<<first_2<<endl;
    bool first_3 = (a_b<=bc);
    cout<<first_3<<endl;
    bool first_4 = (a_b>=bc);
    cout<<first_4<<endl;
    bool first_5 = (a_b!=bc);
    cout<<first_5<<endl;
    // Logical operators
    int abcd = 1;
    int bcd = 2;
    bool second = (abcd && bcd);
    cout<<second<<endl;
    return 0;
}