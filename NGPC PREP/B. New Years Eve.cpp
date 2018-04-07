#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

vector<ll>poww;

void solve()
{
    ll base = 1;
    poww.push_back(0);
    for(int i=1;i<=60;i++)
    {
        base*=2;
        poww.push_back(base);
    }
}


int main()
{
    solve();
    ll n,k;
    sl(n);
    sl(k);
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    int low = upper_bound(poww.begin(),poww.end(),n) - poww.begin();
    cout<<poww[low]-1<<endl;
}


