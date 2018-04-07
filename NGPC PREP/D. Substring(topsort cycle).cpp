#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

vector<int> arr[300009];
map<int,int>indegree;
string s;
int dp[300009][30];
int n,m;

bool topsort()
{
    int cnt=0;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            dp[i][s[i]-'a']=1;
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        cnt++;
        q.pop();
        for(int i=0;i<arr[u].size();i++)
        {
            int v = arr[u][i];
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
            for(int j=0;j<26;j++)
            {
                if(j==s[v]-'a') dp[v][j] = max(dp[v][j], dp[u][j]+1);
                else dp[v][j] = max(dp[v][j], dp[u][j]);
            }
        }
    }

    if(cnt!=n) return false;
    return true;
}

int main()
{
    si(n);
    si(m);
    cin>>s;
    for(int i=0;i<m;i++)
    {
        int a,b;
        si(a);
        si(b);
        indegree[b-1]++;
        arr[a-1].push_back(b-1);
    }
    if(!topsort()) printf("-1\n");
    else
    {
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                mx = max(mx,dp[i][j]);
            }
        }
        printf("%d\n",mx);
    }

}


