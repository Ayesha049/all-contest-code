#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define pb             push_back
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    int n;
    si(n);
    vector<int>vc;
    vector<int>pos;
    vc.push_back(0);
    int mn = MOD;
    f(i,0,n)
    {
        int a;
        si(a);
        vc.push_back(a);
        mn = min(mn,a);
    }
    for(int i=1;i<=n;i++)
    {
        if(vc[i]==mn) pos.push_back(i);
    }
    int mndis = MOD;
    for(int i=1;i<pos.size();i++)
    {
        mndis = min(mndis,pos[i]-pos[i-1]);
    }
    printf("%d\n",mndis);

}


