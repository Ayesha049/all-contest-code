#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

int digsum(int n)
{
    int sum =0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    //cout<<sum<<endl;
    return sum;
}


int main()
{
    int k;
    si(k);
    int xx=0;
    for(int i=11;i<=100000000;i++)
    {
        int tt = digsum(i);
        if(tt==10) xx++;
        if(xx==k)
        {
            cout<<i<<endl;
            return 0;

        }
    }
    cout<<k<<endl;
}


