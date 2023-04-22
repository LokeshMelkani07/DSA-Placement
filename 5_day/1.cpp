#include<iostream>
#include<vector>
using namespace std;

// bubble Sort
// Worst Case TC: O(n^2)
// SC: O(1)

void bubbleSort(vector<int>& arr, int n)
{
    for(int i = 0;i<n-1;i++)  // or we can write for(i = 1 -> i<n)
    {
      for(int j = 0; j<n-i-1; j++) // then we have to write for(j=0 -> j<n-i)
      {
          if(arr[j] > arr[j+1])
          {
              swap(arr[j],arr[j+1]);
          }
      }
    }
}

// Optimisation if array is already sorted
// Best Case Time Complexity = o(n)
void optimisedBubbleSort(vector<int>& arr, int n)
{
    for(int i = 0;i<n-1;i++)  // or we can write for(i = 1 -> i<n)
    {
      // if during any pass, no swaps are made means array is already sorted
      bool swapped = false;
      for(int j = 0; j<n-i-1; j++) // then we have to write for(j=0 -> j<n-i)
      {
          if(arr[j] > arr[j+1])
          {
              swap(arr[j],arr[j+1]);
              swapped = true;
          }
      }
      // if array is already sorted, break
      if(swapped = false)
         break;
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
    bubbleSort(arr,arr.size());
    printArray(arr,arr.size());
    return 0;
}