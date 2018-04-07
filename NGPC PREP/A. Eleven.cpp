#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define pb             push_back
#define MOD 1000000009
using namespace std;
#define INF 1e12
#define EPS 1e-12
#define PI 3.141592653589

map<int, int> fib;
map<int,int>isfib;

void fibb()
{
    fib[1]=1;
    fib[2]=1;
    isfib[1]=1;
    isfib[2]=1;
    for(int i=3;;i++)
    {
        fib[i] = fib[i-1]+fib[i-2];
        isfib[fib[i]]=1;
        if(fib[i]>1100) break;
    }
}



int main()
{
    fibb();
    int n;
    si(n);
    for(int i=1;i<=n;i++)
    {
        if(isfib[i]==1)
        {
            printf("O");
        }
        else printf("o");
    }
    cout<<endl;
}


