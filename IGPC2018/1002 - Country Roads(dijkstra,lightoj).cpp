
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
#define EPS 1e-15
//#define double long double
#define PI acos(-1.0)



typedef pair<int, long long> iPair;

class Graph
{
    int V;
    list< pair<int, long long > > *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<iPair> [V];
    }
    void addEdge(int u, int v, long long w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }


    void shortestPath(int src)
    {
        priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
        vector<ll> dist(V, INF);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            ll dd =pq.top().first;
            pq.pop();
            list< pair<int, ll> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                ll weight = (*i).second;

                ll mxlength = max(weight,dd);
                if (dist[v] > mxlength)
                {
                    dist[v] = mxlength;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int i = 0; i < V; ++i)
        {
            if(dist[i]==INF)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n",dist[i]);
            }
        }

    }


};



void solve()
{
    int n,m;
    sii(n,m);
    Graph g(n);
    int a,b,w;
    f(i,0,m)
    {
        siii(a,b,w);
        g.addEdge(a,b,w);
    }
    int t;
    si(t);
    g.shortestPath(t);
}

int main()
{
    int tc;
    si(tc);
    for (int i = 0; i < tc; ++i)
    {
        printf("Case %d:\n", i + 1);
        solve();
    }
    return 0;
}


