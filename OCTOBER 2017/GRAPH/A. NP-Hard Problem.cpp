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

vector<int>vc[100009];
int color[100009];
vector<int>c1;
vector<int>c2;

bool isbipertite(int src)
{
    color[src]=1;
    c1.pb(src);
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        f(i,0,vc[u].size())
        {
            if(color[u]==color[vc[u][i]])
            {
                return false;
            }
            else
            {
                if(color[vc[u][i]]==0)
                {
                    q.push(vc[u][i]);
                    if(color[u]==1)
                    {
                        color[vc[u][i]]=2;
                        c2.pb(vc[u][i]);
                    }
                    else
                    {
                        color[vc[u][i]]=1;
                        c1.pb(vc[u][i]);
                    }
                }
            }
        }
    }
    return true;
}


int main()
{
    int n,m;
    sii(n,m);

    int a,b;
    f(i,0,m)
    {
        sii(a,b);
        vc[a].pb(b);
        vc[b].pb(a);
    }
    int flag=0;
    f(i,1,n+1)
    {
        if(color[i]==0)
        {
            if(!isbipertite(i))
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
       cout<<c1.size()<<endl;
       f(i,0,c1.size())
       {
            cout<<c1[i]<<" ";
       }
       cout<<endl;
       cout<<c2.size()<<endl;
       f(i,0,c2.size())
       {
            cout<<c2[i]<<" ";
       }

    }


}

