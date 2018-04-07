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
    int n,pos,l,r;
    si(n);
    si(pos);
    si(l);
    si(r);
    int cnt=0;
    if(pos<l)
    {
        cnt+=(l-pos)+1;
        if(r<n) cnt+=(r-l)+1;
    }
    else if(pos>r)
    {
        cnt+=(pos-r)+1;
        if(l>1) cnt+=(r-l)+1;

    }
    else
    {
        if(l==1 && r==n)
        {
            cnt=0;
        }
        else if(l==1)
        {
            cnt+= (r-pos)+1;
        }
        else if(r==n)
        {
            cnt+=(pos-l)+1;
        }
        else
        {
            int xx = min((pos-l),(r-pos));
            cnt+=2;
            cnt+=xx;
            cnt+=(r-l);
        }
    }
    printf("%d\n",cnt);
}


