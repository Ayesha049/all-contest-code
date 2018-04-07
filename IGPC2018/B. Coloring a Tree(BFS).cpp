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

map<int,int>color;

class graphh
{
public:
    int v;
    list<int>*arr;
    vector<int> parent;
    vector<int> visited;
    map<int,int>clr;

    graphh(int x)
    {
        v=x;
        arr=new list<int>[v+1];
        for(int i=0;i<=x;i++)
        {
            parent.push_back(0);
            visited.push_back(0);
        }
    }
    void setedge(int a,int b)
    {
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ll bfs(int src)
    {
        ll cnt=1;
        queue<int>q;
        visited[src]=1;
        q.push(src);
        parent[src]=-1;
        clr[src]=color[src];
        while(!q.empty())
        {
            //cout<<"inside loop"<<endl;
            int u;
            u=q.front();
            q.pop();
            list<int>::iterator i;
            for (i = arr[u].begin(); i != arr[u].end(); ++i)
            {
                if(visited[*i]==0)
                {
                    if(color[*i]==clr[u])
                    {
                        clr[*i]=color[*i];
                    }
                    else
                    {
                        cnt++;
                        clr[*i]=color[*i];
                    }
                    visited[*i]=1;
                    q.push(*i);
                    parent[*i]=u;

                }
            }
        }
        return cnt;

    }
};

int main()
{
    int n;
    cin>>n;
    graphh g(n);
    int p;
    for(int i=2;i<=n;i++)
    {
        si(p);
        g.setedge(p,i);
    }
    f(i,1,n+1)
    {
        si(p);
        color[i]=p;
    }
    cout<<g.bfs(1)<<endl;
}
