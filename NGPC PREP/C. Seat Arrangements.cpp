#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

char arr[2009][2009];
int cnt;

int main()
{
    int n,m,k;
    si(n);
    si(m);
    si(k);
    int dot=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf(" %c",&arr[i][j]);
            if(arr[i][j]=='.') dot++;
            //cin>>arr[i][j];
        }
    }
    if(k==1) cout<<dot<<endl;
    else
    {

        for(int i=0; i<n; i++)
        {
            int cc = 0;
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]!='*') cc++;
                else
                {
                    int xx = cc-k;
                    xx++;
                    if(xx<0) xx=0;
                    cc=0;
                    cnt+=xx;
                }
            }
            int xx = cc-k;
            xx++;
            if(xx<0) xx=0;
            cnt+=xx;
        }
        for(int i=0; i<m; i++)
        {
            int cc = 0;
            for(int j=0; j<n; j++)
            {
                if(arr[j][i]!='*') cc++;
                else
                {
                    int xx = cc-k;
                    xx++;
                    if(xx<0) xx=0;
                    cc=0;
                    cnt+=xx;
                }

            }
            int xx = cc-k;
            xx++;
            if(xx<0) xx=0;
            cnt+=xx;
        }
        cout<<cnt<<endl;
    }
}


