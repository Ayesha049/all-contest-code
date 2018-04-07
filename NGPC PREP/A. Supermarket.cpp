#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    int n;
    double m;
    cin>>n>>m;
    double mn = (double) INFINITY;
    double a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        mn = min(mn, (a/b)*m );
    }
    printf("%.9lf\n",mn);
}


