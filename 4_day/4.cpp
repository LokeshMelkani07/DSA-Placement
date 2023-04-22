// Binary Search Advanced Problems
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Book Allocation Problem
// https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// ayush-is-studying-for-ninjatest-which-will-be-held-after-n-days-and-to-score-good-marks-he-has-to-study-m-chapters-and-the-ith-chapter-requires-time-i-seconds-to-study-the-day-in-ayush-s-world-has-160-100-seconds-there-are-some-rules-that-are-followed-by-ayush-while-studying

bool isPossible(int days,int chapter, vector<int> &time,long long mid)
{
	int daysCount = 1;
	long long int timeCount = 0;
	for(int i = 0;i<chapter;i++)
	{
		if(timeCount + time[i] <=mid && timeCount<pow(100,100))
		{
			timeCount += time[i];
		}
		else{
			daysCount++;
			if(daysCount > days || time[i] > mid)
			{
				return false;
			}
			timeCount = time[i];
		}
	}
	return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
	long long start = 0;
	long long sum = 0;
	for(int i = 0;i<m;i++)
	{
		sum += time[i];
	}
	long long end = sum;
	long long ans = -1;
	long long mid = start + (end-start)/2;
	while(start<=end)
	{
		if(isPossible(n,m,time,mid))
		{
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}
	return ans;
}

// Painter's Partition Problem
// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// Same as Book allocation Problem
bool ispossible(vector<int> &boards, int k,int mid)
{
     int n=boards.size();
     int count=1;
     int sum=0;
     for(int i=0; i<n; i++)
     {
     if(sum+boards[i]<=mid)
     {
        sum+=boards[i];
     }
    else
    {
        count++;
        if(count>k||boards[i]>mid)
        {
            return false;
        }
        sum=boards[i];
    }
        }
    return true;
    }

int findLargestMinDistance(vector<int> &boards, int k)
{
     int n=boards.size();
     int s=0;
     int e=0;
     int ans=-1;
     for(int i=0; i<n; i++)
     {
       // s=min(s,boards[i]);
        e+=boards[i];
     }
     int mid=s+(e-s)/2;
     while(s<=e)
     {
      if(ispossible(boards,k,mid))
      {
          ans=mid;
          e=mid-1;

      }
      else{
          s=mid+1;
      }
    mid=s+(e-s)/2;
     }
     return ans;

}

// Aggressive Cows
// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

bool isPossible(vector<int> &stalls, int k,int mid)
{
    int cowCount = 1;
    int lastPosition = stalls[0];

    for(int i = 0;i<stalls.size();i++)
    {
        if(stalls[i] - lastPosition >= mid)
        {
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int start = 0;
    int maxi = -1;
    for(int i = 0;i<stalls.size();i++)
    {
        maxi = max(maxi,stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end-start)/2;
    while(start<=end)
    {
       if(isPossible(stalls,k,mid))
       {
           ans = mid;
           start = mid+1;
       }
       else{
           end = mid-1;
       }
       mid = start + (end-start)/2;
    }
    return ans;
}

int main()
{
    return 0;
}
