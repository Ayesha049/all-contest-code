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
//#define double long double
#define EPS 1e-7

int main()
{
    int a,b;
    cin>>a>>b;
    string s,t;

    cin>>s>>t;
    vector<int>vc[1001];

    f(i,0,b-a+1)
    {
        f(j,0,a)
        {
            if(t[i+j]!=s[j])
            {
                vc[i].pb(j+1);
            }
        }
    }


    int mn=INFINITY;
    f(i,0,b-a+1)
    {
        int xx=vc[i].size();
        mn= min(mn,xx);
    }
    f(i,0,b-a+1)
    {
        if(vc[i].size()==mn)
        {
            cout<<vc[i].size()<<endl;
            f(j,0,vc[i].size())
            {
                cout<<vc[i][j]<<" ";
            }
            return 0;
        }
    }

}


