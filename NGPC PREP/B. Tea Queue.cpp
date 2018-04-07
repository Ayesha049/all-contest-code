#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    int t;
    si(t);
    while(t--)
    {
        int time = 1;
        int n;
        si(n);
        int l,r;
        map<int,int>tm;
        for(int i=1;i<=n;i++)
        {
            si(l);
            si(r);
            if(time<l) time=l;
            if(time>=l && time<=r) tm[i]=time, time++;
        }
        for(int i=1;i<=n;i++) printf("%d ",tm[i]);
        printf("\n");
    }
}


