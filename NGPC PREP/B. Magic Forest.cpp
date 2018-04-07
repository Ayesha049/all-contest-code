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
    si(n);
    int a,b,c;
    int cnt =0;
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            a=i;
            b=j;
            c = a^b;
            if(c>b) continue;
            if(a+b>c && b+c>a && c+a>b)
            {
               //cout<<a<<" "<<b<<" "<<c<<endl;
               cnt++;
            }
        }
    }
    printf("%d\n",cnt);
}




