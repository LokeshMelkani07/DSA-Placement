#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Pointers in C++ (part 2)

void print(int *ptr)
{
    cout<<"Address at ptr inside function is "<<ptr<<endl;
    cout<<"Value of ptr inside function is "<<*ptr<<endl;
}

void update(int *p)
{
    // Copy of p is passed so value will not get reflected in actual value
    // p = p+1;
    // cout<<"Value inside function is "<<p<<endl;

    // but we can change the value inside the function
    *p = *p +1;
}

int getSum(int arr[],int n)
{
    // int getSum(int *arr,int n) is also right
    // When we pass array as parameter in a function
    // Pointer to first element of array will be passed not the whole array
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        // sum += arr[i];
        sum += i[arr];
    }
    return sum;
}

int main()
{
    int arr[10] = {1,12,23,34,45,56,67,78,89,90};

    cout<<"Address of first memory block is "<<arr<<endl; // 0x61fe98
    cout<<"Value of first memory block is "<<arr[0]<<endl;
    cout<<"Address of first memory block using & operator is "<<&arr[0]<<endl;  // 0x61fe98
    cout<<"*arr gives value of first index "<<*arr<<endl;  // 1
    cout<<"*arr + 1 gives value  "<<*arr+1<<endl; // 1+1 = 2
    cout<<"*arr + 2 gives value  "<<*arr+2<<endl; // 1+2 = 3
    cout<<"*(arr + 1) gives value of second index  "<<*(arr+1)<<endl; // 12
    cout<<"*(arr + 2) gives value of third index  "<<*(arr+2)<<endl; // 23
    cout<<arr[2]<<endl; // 23

    /*
    Formulae

    arr[i] = *(arr+i)

    or

    i[arr] = *(i+arr)
    */

    int i = 4;
    cout<<i[arr]<<endl;  // 45
    cout<<*(i+arr)<<endl;  // 45

    int temp[10]={10,12,32,12};
    int *p = &temp[0];
    cout<<"size of array is "<<sizeof(temp)<<endl;  // 40
    cout<<"size of pointer is "<<sizeof(p)<<endl; // 4
    cout<<"value of array is "<<temp[0]<<endl; // 10
    cout<<"value of pointer is "<<*p<<endl; // 10

    int arr1[20] = {10 ,3,5,7,8};
    cout<<arr1<<endl;
    cout<<&arr1[0]<<endl;
    cout<<&arr1<<endl;
    cout<<endl;
    int *ptr = &arr1[0];
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    // The value of &arr1 and &pte both are different

    cout<<endl;
    // we cannot change the contetn of symbol table
    int arr3[10];
    // arr = arr+1;  // This is error
    int *ptr1 = &arr3[0];
    cout<<ptr1<<endl;
    ptr1 = ptr1+1;
    cout<<ptr1<<endl;  // move to next memory block

    // Character Array
    cout<<endl;
    int arr4[5] = {1,2,3,4,5};
    char ch[6] = "abcde";
    cout<<arr<<endl;  // 0x61fe8c
    cout<<ch<<endl; // abcde

    char *ptr2 = &ch[0];
    // ptr2 will print array till in encounters null character '\0'
    cout<<ptr2<<endl;  // abcde
    cout<<*ptr2<<endl; // a

    char ch1 = 'z';
    char *ptr3 = &ch1;
    cout<<ptr3<<endl;

    cout<<endl;
    // Pointers in Function
    int value = 7;
    int *ptr4 = &value;
    print(ptr4);
    cout<<"Before update address is "<<ptr4<<endl;
    cout<<"Before update value is "<<*ptr4<<endl;
    update(ptr4);
    cout<<"After update address is "<<ptr4<<endl;
    cout<<"After update value is "<<*ptr4<<endl;

    // Get sum
    int arr5[6] = {1,2,3,4,5,7};
    // when we pass an array to a function as a parameter, it does not pass whole array it just pass a pointer to the first element of the array
    cout<<"Sum is "<<getSum(arr5,6)<<endl;
    // we can send the pat of array like this points to third index of array
    cout<<"Sum is "<<getSum(arr5+3,3)<<endl;
    return 0;
}