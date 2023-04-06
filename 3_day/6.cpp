#include<iostream>
#include<unordered_map>
using namespace std;

 int reverse(int x) {
        int ans = 0;
        while(x!=0)
        {
            int digit = x%10;

            if(ans>INT_MAX/10 || ans<INT_MIN/10)
            {
                return 0;
            }

            ans = (ans*10) + digit;
            x = x/10;
        }
        return ans;
    }

    bool isIsomorphic(string s, string t) {
       unordered_map<int, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }

int main()
{
    // Practice Questions Arrays

    return 0;
}
