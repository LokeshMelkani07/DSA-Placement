#include<iostream>
using namespace std;

int main()
{
    // Pattern Printing using loops
    // check number of row
    // check number of col
    // make a relation between number of row and number of col based on number of row
    /*
    int n1;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=n1)
      {
        cout<<"* ";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=n1)
      {
        cout<<i<<" ";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    1 2 3
    4 5 6
    7 8 9
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    int count = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=n1)
      {
        cout<<count<<" ";
        count++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    1
    2 2
    3 3 3
    4 4 4 4
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=i)
      {
        cout<<i<<" ";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    1
    2 3
    4 5 6
    7 8 9 10
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    int count = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=i)
      {
        cout<<count<<" ";
        count++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    1
    2 3
    3 4 5
    4 5 6 7
    5 6 7 8 9
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      int value = i;
      while(j<=i)
      {
        cout<<value<<" ";
        value++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    1
    2 1
    3 2 1
    4 3 2 1
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = i;
      while(j>=1)
      {
        cout<<j<<" ";
        j--;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    A A A
    B B B
    C C C
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    char ch = 'A';
    while(i<=n1)
    {
      int j = 1;
      while(j<=n1)
      {
        cout<<ch<<" ";
        j++;
      }
      cout<<endl;
      ch++;
      i++;
    }
    */
    /*
    A B C
    A B C
    A B C
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      char ch = 'A';
      while(j<=n1)
      {
        cout<<ch<<" ";
        ch++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    A B C D
    B C D E
    C D E F
    D E F G
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=n1)
      {
        char ch = 'A' + i + j -2;
        cout<<ch<<" ";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    A
    B B
    C C C
    D D D D
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      while(j<=i)
      {
        char ch = 'A' + i -1;
        cout<<ch<<" ";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    A
    B C
    C D E
    D E F G
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      char ch = 'A' + i -1;
      while(j<=i)
      {
        cout<<ch<<" ";
        ch++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    D
    C D
    B C D
    A B C D
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      int j = 1;
      char ch = 'A' + n1 -i;
      while(j<=i)
      {
        cout<<ch<<" ";
        ch++;
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
          *
        * *
      * * *
    * * * *
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      // print space
      int space = n1-i;
      while(space)
      {
        cout<<" ";
        space = space-1;
      }
      // print star
      int j = 1;
      while(j<=i)
      {
        cout<<"*";
        j++;
      }
      cout<<endl;
      i++;
    }
    */
    /*
    * * * *
      * * *
        * *
          *
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      // print space
      int space = i-1;
      while(space)
      {
        cout<<" ";
        space = space-1;
      }
      // print star
      int j = n1 - i +1;
      while(j>=1)
      {
        cout<<"*";
        j--;
      }
      cout<<endl;
      i++;
    }
    */
    /*
            1
          1 2 1
        1 2 3 2 1
      1 2 3 4 3 2 1
    int n1;
    cout<<"Enter the value of n1"<<endl;
    cin>>n1;
    int i = 1;
    while(i<=n1)
    {
      // print space
      int space = n1-i;
      while(space)
      {
        cout<<" ";
        space = space-1;
      }
      // print star 1
      int j = 1;
      while(j<=i)
      {
        cout<<j;
        j++;
      }
      // print star 2
      int k = i-1;
      while(k)
      {
        cout<<k;
        k--;
      }
      cout<<endl;
      i++;
    }
    */
    return 0;
}