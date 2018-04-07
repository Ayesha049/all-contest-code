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

map<int,int>lcnt;
map<int,int>leaf;
vector<int> arr[1100];



int main()
{
    int n;
    si(n);
    for(int i=2;i<=n;i++)
    {
        int a;
        si(a);
        arr[a].push_back(i);
        leaf[a]=1;
    }
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<arr[u].size();i++)
        {
            int v = arr[u][i];
            if(leaf[v]==0) lcnt[u]++ ;
            else q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(leaf[i]!=0)
        {
            if(lcnt[i]<3)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}


