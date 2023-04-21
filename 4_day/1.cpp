#include<iostream>
using namespace std;

// Binary Search
int binary_search(int arr[],int size,int key)
{
   int start = 0;
   int end = size-1;
   // int mid = (start+end)/2; will give out of range error because if s and e both are 2^31-1 that is max value of a int then s+e will be out of range of int so to get away with it, we change the formula to
   int mid = (start + (end-start)/2);

   while(start<=end)
   {
    if(arr[mid]==key)
    {
        return mid;
    }
    if(arr[mid]<key)
    {
        start = mid+1;
    }
    else{
        end = mid-1;
    }

    mid = (start+(end-start/2));
   }
   return -1; // if element not found
}

int main()
{
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};
    int even_size = sizeof(even)/sizeof(int);
    int odd_size = sizeof(odd)/sizeof(int);
    cout<<binary_search(even,even_size,18)<<endl;
    cout<<binary_search(odd,odd_size,14)<<endl;
    return 0;
}