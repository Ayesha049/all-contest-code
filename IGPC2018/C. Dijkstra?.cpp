#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f3f3f3f30

typedef pair<int, long long> iPair;

class Graph
{
    int V;
    list< pair<int, long long> > *adj;

public:
    vector<int>parent;
    Graph(int V)
    {
        this->V = V;
        adj = new list<iPair> [V];
        parent.assign(V,0);
    }
    void addEdge(int u, int v, long long w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }


    void shortestPath(int src,int n)
    {

        priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
        vector<long long> dist(V, INF);
        pq.push(make_pair(0, src));
        //ans.push_back(src);
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            if(u==n) break;
            pq.pop();
            list< pair<int, long long> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                    parent[v]=u;
                }
            }
        }
        if(dist[n]== INF) cout<<"-1"<<endl;
        else
        {
            vector<int>ans;
            int xx=n;
            ans.push_back(n);
            while(parent[xx]!=1)
            {
                ans.push_back(parent[xx]);
                xx=parent[xx];
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
        }
    }

};



int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        long long w;
        cin>>a>>b>>w;
        g.addEdge(a,b,w);
    }

    g.shortestPath(1,n);

    return 0;
}


