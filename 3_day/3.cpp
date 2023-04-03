#include<iostream>
using namespace std;

void update(int arr[],int n)
{
    cout<<"Inside the array"<<endl;
    arr[0] = 120; // This will update the element at 0th index in the original array also
    // Printing
    for(int i = 0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Going back to main function"<<endl;
}

int main()
{
    // Scope in array
    int arr[3] = {1,2,4};
    // Here when we are passing arr to the function as arguement
    // arr means address of first block of the array so as we are passing the address
    // any change made in the array through the function will be reflected in the actual array also
    // This is scope of array
    // So we should avoid updating the array inside functions
    update(arr,3);
    // printing the array
    for(int i = 0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}