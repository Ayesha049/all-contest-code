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
    ll a,b;
    sl(a);
    sl(b);
    ll x,y,z;
    sl(x);
    sl(y);
    sl(z);
    ll xx = (2*x)+y;
    ll yy = (3*z)+y;
    ll cnt=0;
    if(a<xx) cnt+=(xx-a);
    if(b<yy) cnt+=(yy-b);
    cout<<cnt<<endl;

}


