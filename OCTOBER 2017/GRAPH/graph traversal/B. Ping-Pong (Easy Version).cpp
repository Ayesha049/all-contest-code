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

vector<int >vc[109];

int visited[109];

bool bfs(int src,int dest)
{
    f(i,0,109)
    {
        visited[i]=0;
    }
    visited[src]=1;
    queue<int>q;
    q.push(src);
    //cout<<src<<" ";
    while(!q.empty())
    {
        int u=q.front();
        //cout<<u<<" ";
        if(u==dest) return true;
        q.pop();
        f(i,0,vc[u].size())
        {
            if(visited[vc[u][i]]==0)
            {
                //if(vc[u][i]==dest) return true;
                visited[vc[u][i]]=1;
                q.push(vc[u][i]);
            }
        }
    }
    //cout<<endl;
    return false;
}



int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >qur;
    qur.pb(mp(-1,-1));
    int a,b,c;
    f(i,0,n)
    {
        siii(a,b,c);
        if(a==1)
        {
            int pos=qur.size();
            qur.pb(mp(b,c));
            f(j,1,qur.size())
            {
                if((b>qur[j].x && b<qur[j].y) || (c>qur[j].x && c<qur[j].y))
                {
                    //vc[j].pb(pos);
                    vc[pos].pb(j);
                }
                if((b<qur[j].x && c>qur[j].x) || (b<qur[j].y && c>qur[j].y))
                {
                    vc[j].pb(pos);
                }
            }
        }
        else
        {
            if(bfs(b,c)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}


