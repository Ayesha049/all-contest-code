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

/*ll n,m,k;
vector<int>pwt;

bool check( ll X)
{
    if((X*k)>n) return false;
    ll rem = n- (X*k);
    ll cnt = X*k + (rem/k)*(k-1) +(rem%k);
    if(cnt<m) return false;
    cout<<X<<endl;
    return true;
}

void pw(ll xx)
{
    pwt.pb(1);
    ll base =1;
    for(ll i=1;i<=xx;i++)
    {
        base*=2;
        //cout<<base<<" ";
        base=base%MOD;
        pwt.pb(base);
    }

}

ll quickpow(ll k,ll xx)
{
    ll ans=1;
    while(xx)
    {
        if(xx&1) ans = (ans*k)%MOD;
        k = (k*k)%MOD;
        xx>>=1;
    }
    return ans;
}

int main()
{
    cin>>n>>m>>k;
    ll l=0;
    ll h=(m/k);

    ll ans;

    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(check(mid))
        {
            ans = ((quickpow(2,mid+1) -2)*k)%MOD + (m-(mid*k)) % MOD;
            ans= ans% MOD;

            h=mid-1;
        }
        else l=mid+1;
    }
    ans = ans % MOD;
    cout<<ans<<endl;


}
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;

const ll mod=1e9+9;
ll fast_pow(ll base,ll k)
{
    ll ans=1;
    while (k) {
        if (k&1)
           ans=(ans*base)%mod;
        base=(base*base)%mod;
        k>>=1;
    }
    return ans;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
     {
        ll res=n/k;
        if (res<=(n-m)) {
            printf("%d\n",m%mod);
        }
        else {
            ll cnt=res-(n-m);
            ll ans=(k*(fast_pow(2,cnt+1)-2))%mod;
            ans=(ans+m-cnt*k+mod)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

