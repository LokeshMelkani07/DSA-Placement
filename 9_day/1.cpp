#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// While Giving 2D array as a parameter in a function in c++, we need to specify Coulmn size Mandatorily as compiler need to pre-calculate the Memory addresses of individual elements

// Linear Search in 2D array
int Linear_Search(int arr[3][4],int target)
{
    // TC: O(m*n)
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<4;j++)
        {
            if(arr[i][j]==target)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Row-wise Sum: {sum of row1, sum of row2, sum of row3} should be the output

vector<int> row_wise_sum(int arr[3][4])
{
    int sum = 0;
    vector<int> ans;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<4;j++)
        {
            sum += arr[i][j];
        }
        ans.push_back(sum);
        sum = 0;
    }

    return ans;
}

// Find The Largest Row Sum
int largest_row_Sum(int arr[3][4])
{
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<4;j++)
        {
            sum += arr[i][j];
        }
        maxi = max(maxi,sum);
        sum = 0;
    }

    return maxi;
}

int main()
{
    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {12,13,14,15}
    };
    if(Linear_Search(arr,12))
    {
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element Not Found"<<endl;
    }

    // Row-wise sum
    vector<int> ans;
    ans = row_wise_sum(arr);
    cout<<"Row wise sum is"<<endl;
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // Largest Row Sum
    cout<<"Largest Row Sum is "<<largest_row_Sum(arr)<<endl;





    return 0;
}