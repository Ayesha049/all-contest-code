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

map<int,int>cnt;

int main()
{
    ll n;
    sl(n);
    int k;
    si(k);
    ll temp =n;
    int m=0;
    for(int i=0;i<64;i++)
    {
        if(temp&1)
        {
            m++;
            cnt[i]++;
        }
        temp=temp>>1;
    }
    if(m>k)
    {
        cout<<"NO\n";
        return 0;
    }
    printf("YES\n");
    for(int i=63;i>=-63;i--)
    {
        if(cnt[i]+m >k) break;
        else
        {
            m+=cnt[i];
            cnt[i-1] += cnt[i]*2;
            cnt[i]=0;
        }
    }

    multiset <int> ms;
    for(int i=63;i>=-63;i--)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            ms.insert(i);
            //2cout<<i<<endl;
        }
    }
    while(ms.size()<k)
    {
        int tt = *(ms.begin());
        ms.erase(ms.begin());
        ms.insert(tt-1);
        ms.insert(tt-1);
    }
    for(auto it = ms.rbegin();it!=ms.rend();it++) cout<<*it<<" ";
    cout<<endl;
}


