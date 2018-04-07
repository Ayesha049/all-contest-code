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

int pr[2000001];
vector<int>prime;

void seive()
{
    pr[1]=1;
    for(int i=2;i<=2000000;i++)
    {
        if(pr[i]) continue;

		for(int j=2*i;j<2000000;j+=i) pr[j]=1;
    }
    for(int i=1;i<2000000;i++)
    {
        if(pr[i]==0)
        {
            prime.push_back(i);
        }
    }
}



int main()
{
    seive();
    int n,m;
    si(n);
    si(m);
    if(n==2)
    {
        printf("2 2\n");
        printf("1 2 2\n");
        return 0;
    }
    int up = upper_bound(prime.begin(),prime.end(), n-2) - prime.begin();
    printf("%d %d\n", prime[up], prime[up]);
    for(int i=1;i<n-1;i++)
    {
        printf("%d %d 1\n",i,i+1);
    }
    printf("%d %d %d\n",n-1,n, prime[up]-(n-2));
    m-=(n-1);
    for(int i=1;i<=n-2;i++)
    {
        if(m==0) break;
        for(int j=i+2;j<=n;j++)
        {
            printf("%d %d %d\n",i,j, prime[up]+1);
            m--;
            if(m==0) break;
        }

    }
}


