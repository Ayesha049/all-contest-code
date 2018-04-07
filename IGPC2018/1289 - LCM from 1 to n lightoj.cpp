
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
#define MOD 4294967296
#define ld long double
#define mp make_pair
using namespace std;
#define INF 1e12
#define EPS 1e-15
//#define double long double
#define PI acos(-1.0)
#define szz 100000100

vector<int>prime;
long long a[szz / 64 + 100];

void seive()
{
    prime.pb(2);

    for (long long i = 3; i <= sqrt(szz); i += 2) {
		if(!(a[i/64]&(1LL<<(i%64)))) {
			for(long long j = i * i; j <= szz; j += 2 * i) {
				a[j/64] |= (1LL<<(j%64));
			}
		}
	}

	for (long long i = 3; i <= szz; i += 2) {
		if(!(a[i / 64] & (1LL << (i % 64)))) {
			prime.pb(i);
		}

	}

}


void solve()
{
    unsigned int n;
    scanf("%u",&n);
    unsigned int ans=1;
    double lg= log(n);
    for(int i=0;i<prime.size();i++)
    {
        if(prime[i]>n) break;
        ans*=prime[i];
    }
    f(i,0,prime.size())
    {
        if(prime[i]>sqrt(n)) break;
        int pw = floor(lg/(log(prime[i])));
        for(int j=1;j<pw;j++)
        {
            ans*=prime[i];
        }
    }

    printf("%u\n", ans);

}

int main()
{

    seive();
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        printf("Case %d: ", i + 1);
        solve();
    }
    return 0;
}



