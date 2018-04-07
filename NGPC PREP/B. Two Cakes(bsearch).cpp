#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

int n,a,b;

int check(int x)
{
    int aa = a/x;
    int bb = b/x;
    if(aa+bb>=n) return 1;
    return 0;
}

int main()
{

    si(n);
    si(a);
    si(b);
    int low=1;
    int ans=0;
    int hi = min(a,b);
    while(hi>=low)
    {
        int mid = (hi+low)/2;
        if(check(mid)==1)
        {
            ans = mid;
            low=mid+1;
        }
        else hi = mid-1;
    }
    printf("%d\n",ans);
}


