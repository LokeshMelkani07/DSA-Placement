#include<iostream>
#include<vector>
using namespace std;

// Selection Sort
// Space Comp = o(1)
// Time Comp = o(n^2) in both best case and worst case
void selectionSort(vector<int>& arr, int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int midIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[midIndex])
            {
                midIndex = j;
            }
        }
        swap(arr[midIndex],arr[i]);
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
    selectionSort(arr,arr.size());
    printArray(arr,arr.size());
    return 0;
}
