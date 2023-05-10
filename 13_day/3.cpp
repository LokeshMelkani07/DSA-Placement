#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursion with Strings | Day-4

// Reverse the string using Recursion
void reverseString(string &str,int i,int j)
{
    // base case
    if(i>j)
    {
        return;
    }

    // Processing
    swap(str[i],str[j]);
    i++;
    j--;

    // Recursive call
    reverseString(str,i,j);
    // or use reverseString(str,i+1,j-1);

}

// Check palindrome or not using recursion
bool checkPalindrome(string &str,int i,int j)
{
    // base case
    if(i>j)
    {
        return true;
    }

    if(str[i] != str[j])
    {
        return false;
    }
    else{
        return checkPalindrome(str,i+1,j-1);
    }
}

// Find a^b using recursion
// Optimisation:
// a^b = a^b/2 * a^b/2 if b is even
// a^b = a* ( a^b/2 * a^b/2 ) if b is odd
int power(int a,int b)
{
    // base case
    // (anything)^0 = 1
    if(b==0)
    {
        return 1;
    }
    // (anything)^1 = anything
    if(b==1)
    {
        return a;
    }

    // Recurrence Relation
    int ans = power(a,b/2);

    // if b is even
    if(!(b&1))
    {
        return ans*ans;
    }
    else{
        // if b is odd
        return a*ans*ans;
    }
}

// Bubble sort using Recursion
void bubble_sort(int *arr,int n)
{
    // base case
    if(n==0 || n==1)
    {
        return;
    }

    // just place one element in its correct position, res recursion will take case
    // place the largest element in the last position
    for(int i = 0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }

    // Recursive call
    bubble_sort(arr,n-1);
}

int main()
{
    string str = "lokesh";

    // Reverse the string using recursion
    reverseString(str,0,str.length()-1);
    cout<<"The reversed string is "<<str<<endl;

    // Palindrome or not
    string str1 = "abbccbba";
    bool ans = checkPalindrome(str1,0,str1.length()-1);

    if(ans)
    {
        cout<<"It is a palindrome"<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }

    // Find power of a^b using recursion
    int a,b;
    cout<<"Enter the number"<<endl;
    cin>>a;
    cout<<"Enter the power"<<endl;
    cin>>b;
    cout<<"The answer is "<<power(a,b)<<endl;

    // Bubble sort using recursion
    int arr[] = {3,5,6,34,2};
    int size = 5;

    bubble_sort(arr,size);

    // Print the array
    for(int x: arr)
    {
        cout<<x<<" ";
    }


    return 0;
}