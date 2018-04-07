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
        int n,k;
        si(n);
        si(k);
        vector<double>x;
        x.push_back(0);
        for(int i=1;i<=k;i++)
        {
            double a;
            scanf("%lf",&a);
            x.push_back(a);
        }
        int mx = (int)(x[1]-1);
        int zz = (int)(n-x[k]);
        mx = max(mx, zz);
        for(int i=2;i<=k;i++)
        {
            double tt = x[i]-x[i-1]-1;
            int temp = ceil(tt/2);
            mx = max(mx, temp);
        }
        printf("%d\n",mx+1);
    }
}


