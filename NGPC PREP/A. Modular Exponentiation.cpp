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

vector<int> poww;

void solve()
{
    int base =1;
    poww.pb(1);
    for(int i=1;i<=29;i++)
    {
        base*=2;
        poww.pb(base);
    }
}


int main()
{
    solve();
    int n,m;
    si(n);
    si(m);
    if(n>29) printf("%d\n",m);
    else printf("%d\n",m%poww[n]);
}


