#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    // Decimal and Binary number system
    // convert decimal to binary
    int n;
    cout<<"Enter number to be converted to binary in decimal"<<endl;
    cin>>n;
    int ans = 0;
    int i = 0;
    while(n!=0)
    {
        int digit = n&1;
        ans = (digit* pow(10,i)) + ans;
        n = n>>1;
        i++;
    }
    cout<<"Ans is "<<ans<<endl;
    // Binary to decimal conversion
    // check the last bit and if bit = 1 consider 2^i and if last bit is 0, ignore it
    int answer = 0;
    int j = 0;
    int m;
    cout<<"Enter the binary number which is to be converted to decimal"<<endl;
    cin>>m;
    int num = m;
    while(m!=0)
    {
        int digit = m%10;
        if(digit==1)
        {
            answer = answer + pow(2,j);
        }
        m = m/10;
        j++;
    }
    cout<<"Decimal of "<<num<<" is "<<answer;
    return 0;
}