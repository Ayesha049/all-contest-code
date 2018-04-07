#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

#define white 0
#define gray 2
#define black 4

vector<int>arr[1000];
map<int,int>indegree;
map<int,int>visited;
map<int,int>path;
int n,m,endd;

int dfs(int src)
{
    if(visited[src]== black) return 0;
    if(visited[src]== gray)
    {
        endd = src;
        return 1;
    }
    visited[src] = gray;
    for(int i=0;i<arr[src].size();i++)
    {
        int v = arr[src][i];
        path[src]= v;
        if(dfs(v)) return 1;
    }
    visited[src]=black;
    return 0;
}

bool topsort(int edge)
{
    queue<int> q;
    map<int,int>local;
    for(int i=1;i<=n;i++)
    {
        local[i]=indegree[i];
        if(indegree[i]==0) q.push(i);
    }
    local[edge]--;
    if(local[edge]==0) q.push(edge);
    int cnt =0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for(int i=0;i<arr[u].size();i++)
        {
            int v = arr[u][i];
            local[v]--;
            if(local[v]==0) q.push(v);
        }
    }
    if(cnt==n) return true;
    return false;
}


bool solve()
{
    int cycle=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            cycle = dfs(i);
            if(cycle) break;
        }
    }
    if(cycle==0) return true;
    int start = endd;
    while(1)
    {
        start = path[start];
        //cout<<start<<endl;
        if(topsort(start)) return true;
        if(start==endd) break;
    }
    return false;

}

int main()
{
    si(n);
    si(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        si(a);
        si(b);
        arr[a].push_back(b);
        indegree[b]++;
    }
    if(solve()) printf("YES\n");
    else printf("NO\n");

}

