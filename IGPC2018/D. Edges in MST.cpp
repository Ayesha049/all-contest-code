/*
 *1.first Union all the edge which has same value;in this process if node
 *between this edge has been connected it couldn't be the edge in MST
 *(proof.  if it is the case ,this means we can use this edge a to exchage a
 *edge c which c<a,this will never happend(be carful the cut edge has been tag)

 *2.then find the edge that is bridge(in current subgraph!!)(use Tarjan algorithm,if those edge not
 *  in MST  ,it can't be a tree;(then all the cut edge left has been taged)

 *3.all the edge left is any(if it is the only one,this,must be cut edge)
 *	be carful cut edge can be updated in every prcess;

 *4.in Tarjan  if there are multiplu edge we can not use pre to judge if it is cut edge
 *

 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
const int maxm=4e5+10;
int ans[maxm],rk[maxn],uset[maxn];
class Edge
{
public:
    int x,y,dis,next,id;
    bool operator<(const Edge &a)const
    {
        return dis<a.dis;
    }
};
Edge edge[maxm],eT[maxm];
int N,M,head[maxn],dfn[maxn],low[maxn],mem[maxm],ds,cur,hT[maxn],vis[maxn];
inline int min(int a,int b)
{
    return a<b?a:b;
}
void addedge(int a,int b,int v,int &cur)
{
    edge[cur].x=a;
    edge[cur].dis=v;
    edge[cur].id=cur;
    edge[cur].y=b;
    edge[cur].next=head[a];
    head[a]=cur++;
}
void addedge2(int a,int b,int id,int &cur)
{
    eT[cur].x=a;
    eT[cur].y=b;
    eT[cur].next=hT[a];
    eT[cur].id=id;
    hT[a]=cur++;
}
void init()
{
    memset(rk,0,sizeof(rk));
    for(int i=0; i<=N; i++)uset[i]=i;
}
inline int Find(int a)
{
    int tmp,rt=a;
    while(rt!=uset[rt])rt=uset[rt];
    while(uset[a]!=a)
    {
        tmp=uset[a];
        uset[a]=rt;
        a=tmp;
    }
    return rt;
}
inline void  Union(int a,int b)
{
    int ra=Find(a),rb=Find(b);
    if(ra==rb)return ;
    uset[rb]=ra;
}
void Tarjan(int now )
{
    dfn[now]=low[now]=++ds;
    for(int i=hT[now]; i!=-1; i=eT[i].next)
    {
        if(vis[eT[i].id]==0)
        {
            //be careful it can not be pre-node
            vis[eT[i].id]=1;
            if(dfn[eT[i].y]==-1)
            {
                Tarjan(eT[i].y);
                low[now]=min(low[now],low[eT[i].y]);
                if(low[eT[i].y]>dfn[now])ans[eT[i].id]=1;
            }
            else low[now]=min(low[now],dfn[eT[i].y]);
        }
    }
}
void Kru(int cur)
{
    int cnt=0,ps=0;
    init();
    sort(edge,edge+cur);
    memset(hT,-1,sizeof(hT));
    memset(dfn,-1,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=0; i<cur&&cnt<N-1; i++)
    {
        int r=i,e=i;
        ps=ds=0;
        while(e<cur&&edge[e].dis==edge[r].dis)e++;
        for(int j=r; j<e; j++)
        {
            int ra=Find(edge[j].x),rb=Find(edge[j].y);
            if(ra==rb)continue;
            else
            {
                ans[edge[j].id]=2;
                vis[edge[j].id]=0;
                addedge2(ra,rb,edge[j].id,ps);
                addedge2(rb,ra,edge[j].id,ps);
            }
        }
        for(int j=r; j<e; j++)
        {
            int ra=Find(edge[j].x),rb=Find(edge[j].y);
            if(ra==rb)continue;
            else
            {
                Tarjan(ra);
                Union(ra,rb);
                cnt++;
            }
        }
        for(int j=i; j<e; j++)
        {
            int ra=Find(edge[j].x),rb=Find(edge[j].y);
            hT[ra]=hT[rb]=dfn[ra]=dfn[rb]=-1;
        }
        i=e-1;
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    cur=ds=0;
    memset(head,-1,sizeof(head));
    memset(ans,-1,sizeof(ans));
    for(int i=0; i<M; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c,cur);
    }
    Kru(cur);
    for(int i=0; i<cur; i++)
        if(ans[i]==1)printf("any\n");
        else if(ans[i]==2)printf("at least one\n");
        else if(ans[i]==-1)printf("none\n");
}

