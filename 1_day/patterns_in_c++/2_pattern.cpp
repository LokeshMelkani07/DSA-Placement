#include<iostream>
#include<algorithm>
using namespace std;

void pattern_1()
{
/*
* * * *
* * * *
* * * *
* * * *
*/
    for(int i = 1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern_2()
{
    /*
    *
    * *
    * * *
    * * * *
    * * * * *
    */
    for(int i=1;i<=3;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern_3()
{
    /*
    1
    1 2
    1 2 3
    */
    for(int i = 1;i<=3;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}

void pattern_4()
{
    /*
    1
    2 2
    3 3 3
    */
    for(int i = 1;i<=3;i++)
    {
     for(int j = 1;j<=i;j++)
     {
         cout<<i<<" ";
     }
     cout<<endl;
    }
}

void pattern_5()
{
  /*
  * * *
  * *
  *
  */
  for(int i = 1;i<=3;i++)
  {
    for(int j = 3;j>=i;j--)
    {
        cout<<"* ";
    }
    cout<<endl;
  }
}

void pattern_6()
{
    /*
    1 2 3
    1 2
    1
    */
    for(int i = 1;i<=3;i++)
    {
        int k = 1;
        for(int j = 3;j>=i;j--)
        {
           cout<<k<<" ";
           k++;
        }
        cout<<endl;
    }
}

void pattern_7(int n)
{
    /*
       *
      *  *
    * * * * *
    */
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int k = 0;k<2*i+1;k++)
        {
            cout<<"*";
        }
        for(int j = 0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern_8(int n)
{
    /*
    * * * * *
     * * *
       *
    */
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            cout<<" ";
        }
        for(int k = 0;k<2*n - (2*i+1);k++)
        {
            cout<<"*";
        }
        for(int j = 0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern_9(int n)
{
  /*
  Diamond pattern
  */
 // Combine pattern_7 and pattern_8
}

void pattern_10(int n)
{
    /*
    *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    *
    */
    for(int i = 1;i<=2*n-1;i++)
    {
       int stars = i;
       if(i>n) stars = 2*n-i;
       for(int j=1;j<=stars;j++)
       {
        cout<<"*";
       }
       cout<<endl;
    }

}

void pattern_11(int n)
{
    /*
    1
    0 1
    1 0 1
    */
    int start = 1;
    for(int i = 0;i<n;i++)
    {
        if(i%2==0) start = 1;
        else start = 0;
        for(int j = 0;j<=i;j++)
        {
           cout<<start;
           // flip 1 or 0
           start = 1-start;
        }
        cout<<endl;
    }
}

void pattern_12(int n)
{
    /*
    if n =4;
    1             1
    1 2         2 1
    1 2 3     3 2 1
    1 2 3 4 4 3 2 1
    */
    int space = 2*(n-1);
    for(int i = 1;i<=n;i++)
    {
        // numbers
        for(int j = 1;j<=i;j++)
        {
          cout<<j<<" ";
        }
        // space
        for(int j = 1;j<=space;j++)
        {
          cout<<" ";
        }
        // numbers
        for(int j = i;j>=1;j--)
        {
          cout<<j<<" ";
        }
        cout<<endl;
        space -= 2;
    }
}

void pattern_13(int n)
{
    /*
    n = 4
    1
    2 3
    4 5 6
    7 8 9 10
    */
    int count=1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cout<<count;
            count++;
        }
        cout<<endl;
    }
}

void pattern_14(int n)
{
    /*
    n = 4
    A
    A B
    A B C
    A B C D
    */

    for(int i = 1;i<=n;i++)
    {
      for(char ch = 'A';ch<'A'+i;ch++)
      {
        cout<<ch<<" ";
      }
      cout<<endl;
    }
}

void pattern_15(int n)
{
  /*
  n = 4
  A B C D
  A B C
  A B
  A
  */
  for(int i = 0;i<n;i++)
  {
    for(char ch = 'A'; ch<='A'+(n-i-1);ch++)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
  }
}

void pattern_16(int n)
{
    /*
    n = 4
    A
    B B
    C C C
    D D D D
    */
    for(int i =0;i<n;i++)
    {
        char ch = 'A' + i;
        for(int j = 0;j<=i;j++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void pattern_17(int n)
{
    /*
    n = 5
        A
      A B A
    A B C B A
  A B C D C B A
A B C D E D C B A
    */
   // Little similar to pattern 7 but little maths for character printing is needed
     for(int i = 0;i<n;i++)
    {
        // space
        for(int j = 0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        // characters
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int k = 1;k<=2*i+1;k++)
        {
            cout<<ch<<" ";
            if(k<=breakpoint) ch++;
            else ch--;

        }
        // space
        for(int j = 0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern_18(int n)
{
    /*
    n = 5
    E
    E D
    E D C
    E D C B
    E D C B A
    */
    for(int i = 0;i<n;i++)
    {
        char chh = 'A'+n-1;
        for(int j = 0;j<=i;j++)
        {
            cout<<chh<<" ";
            chh--;
        }
        cout<<endl;
    }

}

void pattern_19(int n)
{
    /*
    n = 3
    * * * * * *
    * *     * *
    *         *
    *         *
    * *     * *
    * * * * * *
    */
    // we can divide this pattern into 2 parts
    // till n
    // stars spaces stars

    // 1st part
    int intial_spaces = 0;
    for(int i = 0;i<n;i++)
    {
        // stars
        for(int j = 1;j<=n-i;j++)
        {
           cout<<"*";
        }
        // spaces
        for(int j = 0;j<intial_spaces;j++)
        {
           cout<<" ";
        }
        // stars
        for(int j = 1;j<=n-i;j++)
        {
           cout<<"*";
        }
        intial_spaces += 2;
        cout<<endl;
    }
    // 2nd part
    intial_spaces = 2*n-2;
    for(int i = 1;i<=n;i++)
    {
        // stars
        for(int j = 1;j<=i;j++)
        {
           cout<<"*";
        }
        // spaces
        for(int j = 0;j<intial_spaces;j++)
        {
           cout<<" ";
        }
        // stars
        for(int j = 1;j<=i;j++)
        {
           cout<<"*";
        }
        intial_spaces -= 2;
        cout<<endl;
    }
}

void pattern_20(int n)
{
  /*
  n = 3
  *         *
  * *     * *
  * * * * * *
  * *     * *
  *         *
  */
  // we cannot break it into symmetry.
  int spaces = 2*n-2;
  for(int i = 1;i<=2*n-1;i++)
  {
    int stars = i;
    if(i>n) stars = 2*n-i;
    // star
    for(int j = 1;j<=stars;j++)
    {
        cout<<"*";
    }

    // space
    for(int j = 1;j<=spaces;j++)
    {
        cout<<" ";
    }

    // star
    for(int j = 1;j<=stars;j++)
    {
        cout<<"*";
    }
    cout<<endl;
    if(i<n) spaces -= 2;
    else spaces += 2;
  }
}

void pattern_21(int n)
{
    /*
    n = 4
    ****
    *  *
    *  *
    ****
    */
   // Filling the stars in the boundaries
   // outer loop run till n
   // inner loop also runs till n
   // i==0, i==n-1 , j==0 , j==n-1 are cases of boundary so fill the stars
   for(int i = 0;i<n;i++)
   {
    for(int j = 0;j<n;j++)
    {
        if(i==0 || i==n-1 || j==0 || j==n-1)
        {
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
   }
}

void pattern_22(int n)
{
    /*
    n = 4
    4444444
    4333334
    4322234
    4321234
    4322234
    4333334
    4444444
    */
    // subtract 4 from whole matrix to get the new matrix i.e subtract n
    // now we get new matrix
    // if n=4, outer and inner loop both run for 7 times
    // means 2*n-1 times
    // we pick the center element like [3][3] if considering 0 based indexing
    // we check the distance from top,left,right,bottom
    // top = i, left = j, right = (2*n-1)-1-j, bottom = (2*n-1)-1-i
    // we take minimum distance from top,bottom,left, right and our value will be n - (minimum of top,down,left,right)
    for(int i=0;i<2*n-1;i++)
    {
        for(int j = 0;j<2*n-1;j++)
        {
          int top = i;
          int left = j;
          int right = (2*n-2)-j;
          int bottom = (2*n-2)-i;
          cout<<(n - min(min(top,bottom),min(left,right)));
        }
        cout<<endl;
    }
}

int main()
{
    pattern_22(4);
    return 0;
}