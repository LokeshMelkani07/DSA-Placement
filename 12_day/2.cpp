#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Making of Jaggered Array using Dynamic Memory Allocation
// What is an Jaggered Array
// A jagged array is an array of arrays such that member arrays can be of different sizes, in 2D array terms for each row we can have a variable number of columns. These types of arrays are also known as Jagged arrays.
/*
arr[3][] = 1 2 3 4        // arr[0][4] : 1st row have 4 columns
           5 6            // arr[1][2] : 2nd row have 2 columns
           7 8 9          // arr[2][3] : 3rd row have 3 columns
*/

int main()
{
    int row = 3;
    int size[] = {4,2,3};
    int **arr = new int*[row];
    for(int i = 0;i<row;i++)
    {
        arr[i] = new int[size[i]];
    }

    // Taking input from the user
    cout<<"Enter the input"<<endl;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<size[i];j++)
        {
            cin>>arr[i][j];
        }
    }

    // Output the Array
    cout<<"Your Jaggered Array is"<<endl;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<size[i];j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Free up the space
    for(int i = 0;i<row;i++)
    {
        delete[]arr[i];
    }
    delete[] arr;

    return 0;
}