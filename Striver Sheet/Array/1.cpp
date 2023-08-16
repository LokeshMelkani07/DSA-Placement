#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Program to generate Pascal’s Triangle
// To find element at particular row and col in pascal triangle
int pascalTriangle(int r, int c)
{
    // Generating any Element for (r,c) in a pascal triangle
    // we will use nCr = n! / (n-r)! * r!
    // n*(n-1)*(n-2)*......(n-r+1)* (n-r)! / (n-r)! * r!
    // which boils down to n*(n-1)*.....(n-r+1) / r*(r-1)*.........1
    // To get element at nCr, we will use formula n-1 C r-1
    int element = nCr(r - 1, c - 1);
    return element;
}

// Variation 2
// Print the nth row of pascal triangle
// We can make an assumption that, number of element in nth row will be = n in pascal triangle
void pascalTriangle2(int n)
{
    // printing the entire row n:
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

// Variation 3
// Print whole pascal triangle till nth row
int nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return (int)res;
}

vector<vector<int>> generate(int N)
{
    // For each row, print element for each col
    // Same formula will be used
    vector<vector<int>> vec;
    // i = row, j = col
    for (int i = 1; i <= N; i++)
    {
        vector<int> vec1;
        for (int j = 1; j <= i; j++)
        {
            int ans = nCr(i - 1, j - 1);
            vec1.push_back(ans);
        }
        vec.push_back(vec1);
    }

    return vec;
}

int main()
{
    return 0;
}