#include<iostream>
using namespace std;

void print_Array(int arr[],int n)
{
  // Printing the array
  for(int i = 0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
    // Introduction to Arrays
    int a[10] = {1,2,3};
    cout<<"First element of array "<<a[0]<<endl;
    cout<<"Second element of array "<<a[1]<<endl;
    print_Array(a,10);
    // Character array
    char ch[6] = {'l','o','k','e','s','h'};
    return 0;
}