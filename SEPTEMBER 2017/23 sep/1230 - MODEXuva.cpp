#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define fd(i,a,b)      for(ll i=(a);i>(b);i--)
#define x              first
#define y              second
#define si(a)          scanf("%d",&a)
#define sii(a,b)       scanf("%d %d",&a,&b)
#define siii(a,b,c)    scanf("%d %d %d",&a,&b,&c)
#define sl(a)          scanf("%I64d",&a)
#define sll(a,b)       scanf("%I64d %I64d",&a,&b)
#define slll(a,b,c)    scanf("%I64d %I64d %I64d",&a,&b,&c);
#define pfci(n,ans)    printf("Case %I64d: %d\n",n,ans)
#define pfcl(n,ans)    printf("Case %I64d: %I64d\n",n,ans)
#define pfcd(n,ans)    printf("Case %I64d: %lf\n",n,ans)
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define MOD 1000000009
#define ld long double
#define mp make_pair
using namespace std;
#define INF 1e12
#define EPS 1e-12
//#define double long double
#define PI 3.141592653589

ll bigmod(ll x,ll y,ll n)
{
    if(y==0) return 1;
    else if(y%2==1)
    {
        return ((x%n)*bigmod(x,y-1,n))%n;
    }
    else return (bigmod(x,y/2,n)*bigmod(x,y/2,n))%n;
}



long long big(long long a,long long p,long long m)
{
    long long r = 1;
    while(p!=0)
    {
        if(p%2==1) r = (r*a)%m;
        a = (a*a)%m;
        p = p/2;
    }
    return r;
}

int main()
{
    ll x,y,n;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld %lld",&x,&y,&n);
        {
            ll ans=big(x%n,y,n);
            cout<<ans<<endl;
        }
    }
    cin>>t;
    return 0;
}


