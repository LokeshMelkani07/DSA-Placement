#include<iostream>
using namespace std;

int main()
{
    // mini calculator program
    int a,b;
    char opp;
    cout<<"Enter the first number"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    cout<<"Enter the Operator"<<endl;
    cin>>opp;

    switch(opp)
    {
        case '+' : cout<<"The addition of "<<a<<" "<<b<<" is "<<a+b<<endl;
        break;

        case '-' : cout<<"The Subtraction of "<<a<<" "<<b<<" is "<<a-b<<endl;
        break;

        case '*' : cout<<"The Multiplication of "<<a<<" "<<b<<" is "<<a*b<<endl;
        break;

        case '/' : cout<<"The Division of "<<a<<" "<<b<<" is "<<a/b<<endl;
        break;

        case '%' : cout<<"The Modulus of "<<a<<" "<<b<<" is "<<a%b<<endl;
        break;

        default: cout<<"Please Enter a valid operator";
        break;
    }
    return 0;
}