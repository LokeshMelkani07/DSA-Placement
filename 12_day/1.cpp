#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Dynamic Memory Allocation of 2D Arrays

int main()
{
    int n,m;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    // Creation of 2D array dynamically
    int **arr = new int*[n];
    cout<<"Enter the number of coulmns of 2D array"<<endl;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[m];
    }

    // Taking input in 2D array
    for(int i = 0;i<n;i++)
    {
        for(int j= 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    // Taking output in 2D array
    for(int i = 0;i<n;i++)
    {
        for(int j= 0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Releasing heap memory manually for 2D array
    for(int i = 0;i<n;i++)
    {
        // releasing coulmn blocks created
        delete []arr[i];
    }

    // releasing memory of int* blocks created
    delete []arr;
    return 0;
}