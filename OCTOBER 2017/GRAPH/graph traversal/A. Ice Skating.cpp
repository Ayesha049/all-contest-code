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

int matrix[1009][1009];

int main()
{
    int n;
    cin>>n;
    int a,b;
    vector<pair<int,int> >vc;
    f(i,0,n)
    {
        sii(a,b);
        matrix[a][b]=1;
        vc.pb(mp(a,b));
    }
    sort(vc.begin(),vc.end());
    int cnt=0;
    queue<pair<int,int> >q;
    f(i,0,vc.size())
    {
        if(matrix[vc[i].x][vc[i].y]==1)
        {
            cnt++;
            matrix[vc[i].x][vc[i].y]=0;
            int xx=vc[i].x;
            int yy=vc[i].y;
            q.push(mp(xx,yy));
            while(!q.empty())
            {
                xx=q.front().x;
                yy=q.front().y;
                q.pop();
                f(j,0,1009)
                {
                    if(matrix[xx][j]==1)
                    {
                        q.push(mp(xx,j));
                        matrix[xx][j]=0;
                    }
                }
                f(j,0,1009)
                {
                    if(matrix[j][yy]==1)
                    {
                        q.push(mp(j,yy));
                        matrix[j][yy]=0;
                    }
                }

            }
        }
    }
    cout<<cnt-1<<endl;

}

