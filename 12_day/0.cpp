#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Reference Variable | Static vs Dynamic Memory | Part-1

void updateByValue(int n)
{
    // Call by value
    n++;
}

void updateByReference(int &n)
{
    // Call by reference
    n++;
}

// We can also pass reference variable in return type
int& func(int a)
{
    // This is a bad pratice because num,ans are local variable after this function call, this memory will be destroyed so This should not be done this is a bad practice
    int num = a;
    int &ans = num;
    return ans;
}

int* fun(int n)
{
    // This is also a BAD Practice as ptr is a local variable whose memory space will be freed up outside this fucntion call and we may be not able to access this ptr due to this.
    int *ptr = &n;
    return ptr;
}

int getSum(int *arr,int n)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int i = 5;
    // Creating a Reference Variable
    int &j = i;
    cout<<i<<endl;  // 5
    i++;
    cout<<i<<endl;  // 6
    j++;
    cout<<i<<endl;  // 7
    cout<<j<<endl;  // 7

    // Pass by value
    int n = 5;
    cout<<"Before "<<n<<endl;  // 5
    updateByValue(n);
    cout<<"After "<<n<<endl;   // 5

    // Pass by reference
    cout<<"Before "<<n<<endl;  // 5
    updateByReference(n);
    cout<<"After "<<n<<endl;  // 6

    // BAD Practice
    // The below pratiice is a BAD practice of giving size of array in runtime because every program has some alloted memory to get executed
    // Size of array should be specified in compile only or atleast do int arr[1000000000];
    // There are 2 types of memory stack and heap memory
    // These both memory are alloted based on size we get during compile time
    // when we allot the size of array during runtime, it may happen that stack memory is not sufficient and our program may crash
    /*
    int m;
    cin>>m;
    int arr[m];
    */

    // Whatever is allocated in stack is static allocation
    // Whatever is allocated in heap is dynamic allocation
    // we can tackle the above situation using allocation of memory in heap
    // Till now we were just allocating memory in stack which was static
    // We can allocate memeory in heap using 'new' keyword
    // new char; will give us memory location of a block in heap which we can access using a pointer
    char *ch = new char; // total 8 + 1 = 9 byte
    int *k = new int; // total 8 + 4 = 12 byte

    // Dynamic array
    int n1;
    cout<<"Size of array "<<endl;
    cin>>n1;
    // Variable size array
    int *arr1 = new int[n1];
    for(int i = 0;i<n1;i++)
    {
        // arr[i] = *(arr+i)
        cin>>arr1[i];
    }
    int ans = getSum(arr1,n1);
    cout<<"Sum is "<<ans<<endl;

    // In static memory, the memory gets freed up automatically whereas in Dynamic memory allocation we need to free up the memory manually using 'delete' keyword
    // for deleting memory of variable use. delete i;
    // for deleting memory of array use. delete []arr;
    return 0;
}
