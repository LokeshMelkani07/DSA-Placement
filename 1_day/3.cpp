#include<iostream>
using namespace std;

int main()
{
    // Conditionals and loops
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"Value of n is "<<n<<endl;
    if(n>0)
    {
        cout<<n<<" is Positive"<<endl;
    }
    else{
        cout<<n<<" is negative"<<endl;
    }
    int a,b;
    cout<<"Enter value of a"<<endl;
    cin>>a;
    cout<<"Enter value of b"<<endl;
    cin>>b;
    if(a>b)
    {
        cout<<"value of a is"<<a<<endl;
    }
    else{
        cout<<"value of b is "<<b<<endl;
    }
    int c;
    cout<<"Enter the value of c"<<endl;
    cin>>c;
    if(c>0)
    {
        cout<<c<<" is positive"<<endl;
    }
    else if(c<0)
    {
        cout<<c<<" is negative"<<endl;
    }
    else{
        cout<<c<<" is Neither positive nor negative"<<endl;
    }
    return 0;
}