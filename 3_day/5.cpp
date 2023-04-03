#include<iostream>
using namespace std;

void Reverse_Array(int arr[],int size)
{
   int i = 0;
   int j = size-1;
   while(i<j)
   {
     swap(arr[i],arr[j]);
     i++;
     j--;
   }
}

void Print_Array(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    // Reversing the array
    int arr[6] = {1,2,3,4,5,6};
    Reverse_Array(arr,6);
    Print_Array(arr,6);
    return 0;
}