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
    ll x,y;
    sl(y);
    sl(x);
    cout<<x<<" "<<y<<endl;
    if(x==0)
    {
        printf("NO\n");
        return 0;
    }
    ll ty=x-1;
    if(ty==y)
    {
        printf("YES\n");
        return 0;
    }
    if(ty==0 || y<ty || (y-ty)%2==1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}



