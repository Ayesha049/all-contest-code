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




int func( ll n)
{
    int cnt =1;
    while(1)
    {

        if(n==1) break;
        cnt++;
        if(n%2==0) n=n/2;
        else n= (3*n +1);
    }
    return cnt;

}


int main()
{

    int a,b;
    while(scanf ("%d %d", &a, &b) != EOF)
    {

        int a1 = min(a,b);
        int b1= max(a,b);
        int mx= 0;
        for(ll i=a1;i<=b1;i++)
        {
            mx= max(mx,func(i));
        }
        printf("%d %d %d\n", a,b,mx);
    }
    return 0;
}


