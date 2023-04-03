#include<iostream>
using namespace std;

int Linear_Search(int arr[],int n,int key)
{
    // Linear Search
    // TC: o(n)
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Searching inside array
    // Linear Search
    int arr[10] = {1,2,5,3,4,56,75,24,21,34};
    // check whether 75 is present in the array or not
    int size = sizeof(arr)/sizeof(int);
    cout<<"Element found at index "<<Linear_Search(arr,size,75)<<endl;
    return 0;
}