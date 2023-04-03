#include<iostream>
using namespace std;

int Get_Max(int arr[],int size)
{
    // Find maximum element in array
    int maxi = INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>maxi)
        {
            maxi = arr[i];
        }
    }

    return maxi;
}

int Get_Min(int arr[],int size)
{
    // Find minimum element in array
    int mini = INT_MAX;
    for(int i = 0;i<size;i++)
    {
        if(arr[i]<mini)
        {
            mini = arr[i];
        }
    }

    return mini;
}

int main()
{
    // Find Maximum/ Minimum of an array
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[100];
    cout<<"Enter the elements of array"<<endl;
    for(int i = 0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum element is "<<Get_Max(arr,size)<<endl;
    cout<<"Minimum element is "<<Get_Min(arr,size)<<endl;
    return 0;
}