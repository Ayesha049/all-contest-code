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

ll m;

int check(ll n)
{
    double nn=n;
    ll b = ceil(cbrt(nn));
    ll sum =0;
    for(ll i=2;i<=b;i++)
    {
        ll temp= i*i*i;
        sum += (n/temp);
    }
    //cout<<n<<" "<<sum<<endl;
    if(sum==m) return 1;
    else if(sum<m) return -1;
    else return 2;

}



int main()
{

    cin>>m;

    ll ans =-1;

    ll low=8;
    ll high=1e17;
    while(low<=high)
    {
        ll mid = (high+low)/2;
        if(check(mid)==1)
        {
            ans=mid;
            high= mid-1;
        }
        else if(check(mid)==-1) low=mid+1;
        else high=mid-1;
    }
    cout<<ans<<endl;

}


