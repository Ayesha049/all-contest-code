#include<bits/stdc++.h>
using namespace std;



class graphh
{
public:
    int v;
    list< pair<int, int> > *arr;
    vector<int> parent;
    vector<int> visited;
    vector<int> dist;
    int time;
    graphh(int x)
    {
        v=x;
        arr=new list< pair<int, int> >[v+1];
        for(int i=0; i<=x; i++)
        {
            parent.push_back(0);
            visited.push_back(0);
            dist.push_back(0);
        }
    }
    void setedge(int a,int b, int w)
    {
        arr[a].push_back(make_pair(b,w));
    }
    void DFSconnected(int a, int ii, int ww)
    {
        visited[a]=1;
        cout<<a<<" ";
        list<pair<int, int> >::iterator i;
        for (i = arr[a].begin(); i != arr[a].end(); ++i)
        {
            int vv = (*i).first;
            int weight = (*i).second;
            if(weight>= ww)
            {
                if(visited[vv]==0)
                {
                    DFSconnected(vv,ii, weight);
                    parent[vv] =a;
                }
                else
                {
                    dist[a] = max(dist[a], dist[vv]+1);
                }
            }

        }
        if(a!=ii) dist[parent[a]]= max(dist[parent[a]], dist[a]+1 );
    }

    void dfs(int src)
    {
        //time=0;
        DFSconnected(src,src,0);
        for(int i=1; i<=v; i++)
        {
            if(visited[i]==0)
            {
                DFSconnected(i,i,0);
            }

        }
    }
};

int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    graphh g(n);
    int a,b;
    char w;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %c", &a,&b,&w);
        g.setedge(a,b,(int)w);
    }
    g.dfs(1);
    for(int i=1;i<=n;i++) cout<<i<<" "<<g.dist[i]<<endl;
}

