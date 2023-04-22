#include<iostream>
#include<vector>
using namespace std;

// Insertion Sort
// It is stable and adaptive algo
// stable means order is maintained of same set of keys
// adaptive means it changes its behaviour when it is run based on info avaiable
// SC: O(1)
// TC: O(n^2)
// Best case TC: O(n)
// Worst case TC: O(n^2)
void insertionSort(vector<int>& arr, int n)
{
     for(int i = 1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void printArray(vector<int> &arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    vector<int> arr{6,2,8,4,10};
    insertionSort(arr,arr.size());
    printArray(arr,arr.size());
    return 0;
}