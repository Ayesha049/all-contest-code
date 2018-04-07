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

vector<int>lang;
vector<int>parent;

int Find(int node)
{
    if(parent[node]==-1) return node;
    parent[node]=Find(parent[node]);
    return parent[node];
}

void Union(int node1, int node2)
{
    int a= Find(node1);
    int b= Find(node2);
    if(a==b) return;
    parent[b]=a;
}



int main()
{
    int n,m;
    cin>>n>>m;

    f(i,0,m+1)
    {
        lang.pb(-1);
    }
    f(i,0,n+1)
    {
        parent.pb(-1);
    }
    int ff=0;
    f(i,1,n+1)
    {
        int k;
        cin>>k;
        if(k!=0) ff=1;
        vector<int>temp;
        int a;
        f(j,0,k)
        {
            si(a);
            temp.pb(a);
        }
        int flag=0;
        f(j,0,k)
        {
            if(lang[temp[j]]!=-1)
            {
                Union(i,lang[temp[j]]);
                flag=lang[temp[j]];
            }
        }
        if(flag==0)
        {
            f(j,0,k)
            {
                lang[temp[j]]=i;
            }
        }
        else
        {
            f(j,0,k)
            {
                lang[temp[j]]=flag;
            }
        }
    }
    if(ff==0) cout<<n<<endl;
    else
    {
        int cnt=0;
        f(i,1,n+1)
        {
            if(parent[i]==-1) cnt++;
        }
        cout<<cnt-1<<endl;
    }
}


