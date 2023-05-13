#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Single Linkedlist
// Lecture 44: Linked List & its types - Singly, Doubly, Circular etc.

 int recur(int i,int zero,int one, vector<long long>&dp)
    {
        if(i==0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=(recur(i-zero,zero,one,dp)%1000000007 + recur(i-one,zero,one,dp)%1000000007)%1000000007;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1,-1);
        long long ans=0;
        for(int i=low;i<=high;i++)
        {
            ans=(ans%1000000007 + recur(i,zero,one,dp)%1000000007)%1000000007;
        }
        return ans;
    }


int main()
{
    return 0;
}
