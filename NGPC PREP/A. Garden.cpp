#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define pb             push_back
#define MOD 1000000009
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    int n,k;
    si(n);
    si(k);
    int mn=(int)INFINITY;
    for(int i=0;i<n;i++)
    {
        int a;
        si(a);
        if(k%a==0)
        {
            mn = min(mn, (k/a));
        }
    }
    printf("%d\n",mn);
}


