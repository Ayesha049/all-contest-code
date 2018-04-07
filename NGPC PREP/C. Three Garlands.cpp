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
    map<int,int> mp;
    for(int i=0;i<3;i++)
    {
        int a;
        si(a);
        mp[a]++;
    }
    if(mp[1]>=1 || mp[2]>=2 || mp[3]>=3 || (mp[2]==1 && mp[4]==2)) printf("YES\n");
    else printf("NO\n");
}


