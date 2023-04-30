#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2D Array or Matrix




int main()
{
    // Create 2D array
    int arr[3][4];
    cout<<"Taking input of 2D array"<<endl;
    // Take Input of 2D array
    for(int row = 0 ;row<3;row++)
    {
        for(int col = 0;col<4;col++)
        {
            cin>>arr[row][col];
        }
    }
    cout<<"Output of 2D array"<<endl;
    // Output of 2D Array
    for(int row = 0 ;row<3;row++)
    {
        for(int col = 0;col<4;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Hardcoded input to 2D array
    int arr1[3][4] = {1,5,4,3,2,6,7,8,1,2,4,6};
    for(int row = 0 ;row<3;row++)
    {
        for(int col = 0;col<4;col++)
        {
            cout<<arr1[row][col]<<" ";
        }
        cout<<endl;
    }

    // Other way of initialising 2D array
    cout<<endl;
    int arr2[3][4] = {
        {10,11,12,13},
        {45,45,32,47},
        {23,26,27,28}
        };
    for(int row = 0 ;row<3;row++)
    {
        for(int col = 0;col<4;col++)
        {
            cout<<arr2[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}