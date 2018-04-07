#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int maxv=505;
const int maxe=100005;

vector<int> vs[maxv];
int dg[maxv];
int path[maxv];
int visited[maxv];
bool draw[maxv];
int n,m;

int endd;

int dfs(int vt)
{
    if(visited[vt]==-1)
        return 0;
    if(visited[vt]==1)
    {
        endd = vt;
        return 500;
    }
    visited[vt]=1;
    int size=vs[vt].size();
    for(int i=0; i<size; i++)
    {
        path[vt]=vs[vt][i];
        int end=dfs(vs[vt][i]);
        if(end)
        {
            //cout<<end<<endl;
            return end;
        }

    }
    visited[vt]=-1;
    return 0;
}

bool topsort(int e)
{
    int id[maxv];
    queue<int> q;
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        id[i]=dg[i];
        if(id[i]==0)
            q.push(i);
    }
    --id[e];
    if(id[e]==0)
        q.push(e);
    while(!q.empty())
    {
        int vt=q.front();
        q.pop();
        ++cnt;
        int size=vs[vt].size();
        for(int i=0; i<size; i++)
        {
            --id[vs[vt][i]];
            if(id[vs[vt][i]]==0)
                q.push(vs[vt][i]);
        }
    }
    return cnt==n;
}

bool solve()
{
    int s;
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            s=dfs(i);
            if(s!=0)
                break;
        }
    }
    if(s==0)
        return true;
    int vt = endd;
    do
    {
        if(topsort(path[vt]))
            return true;
        vt=path[vt];
        cout<<vt<<endl;
    }
    while(vt!=endd);
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int from,to;
        scanf("%d%d",&from,&to);
        vs[from].push_back(to);
        ++dg[to];
    }
    if(solve())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
