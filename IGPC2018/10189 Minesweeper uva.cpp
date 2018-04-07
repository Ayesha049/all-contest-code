
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



const int DX[] = {0,1,0,-1,-1,-1,1,1};
const int DY[] = {1,0,-1,0,-1,1,-1,1};

char arr[1000][1000];


int a,b;

bool checkCell(int x, int y)
{
    if (x < 1 || x > a || y < 1 || y > b)
        return false;
    return arr[x][y]=='*';

}


int minecnt(int x,int y)
{
    int cnt=0;
    for(int i=0;i<8;i++)
    {
        int xx = x+ DX[i];
        int yy = y + DY[i];
        if(checkCell(xx,yy)) cnt++;
    }

    return cnt;
}

int main()
{

    int cs=1;
    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;
        if(cs!=1) cout<<endl;
        printf("Field #%d:\n", cs);
        cs++;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(arr[i][j]=='*') cout<<"*";
                else cout<<minecnt(i,j);
            }
            cout<<endl;
        }
    }
}

