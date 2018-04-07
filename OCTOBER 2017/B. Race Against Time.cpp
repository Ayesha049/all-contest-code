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



int main()
{
    int h,m,s,t1,t2;
    cin>>h>>m>>s>>t1>>t2;
    map<int,int>mpp;

    mpp[(h%12)*5]=1;
    mpp[m]=1;
    mpp[s]=1;
    t1=t1*5;
    t1=t1%60;
    t2=t2*5;
    t2=t2%60;
    int tt1=max(t1,t2);
    int tt2=min(t1,t2);
    int dif= (tt1-tt2);
    int flag=0;
    f(i,0,dif)
    {
        if(mpp[tt2+i]==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        flag=0;
        dif = 60-dif;
        f(i,0,dif)
        {
            if(mpp[(tt1+i)%60]==1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


