#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    char ss[] = {'d','l','r','u'};
    int cnt =0;
    int n,m;
    si(n);
    si(m);
    pair<int,int> start;
    char arr[100][100];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='S') start = make_pair(i,j);
        }
    }
    string s;
    cin>>s;
    pair<int,int> pos;
    //cout<<start.first<<" "<<start.second;
    do
    {
        pos=start;
        int flag=0;
        for(int j=0;j<s.length();j++)
        {

            int pp = (int)(s[j]-'0');
            char xx = ss[pp];
            int px=pos.first;
            int py=pos.second;
            if(xx=='u')
            {
                px--;
            }
            else if(xx=='d')
            {
                px++;
            }
            else if(xx=='l')
            {
                py--;
            }
            else if(xx=='r')
            {
                py++;
            }
            if(px<1 || px>n || py<1 || py>m )
            {
                //cout<<px<<" "<<py<<endl;
                break;
            }
            else if(arr[px][py]=='#')
            {
                //cout<<"# "<<px<<" "<<py<<endl;
                break;
            }
            pos = make_pair(px,py);
            if(arr[px][py]=='E')
            {
                cnt++;
                //cout<<ss[i]<<endl;
                break;
            }
        }

    } while ( std::next_permutation(ss,ss+4) );
    cout<<cnt<<endl;
}


