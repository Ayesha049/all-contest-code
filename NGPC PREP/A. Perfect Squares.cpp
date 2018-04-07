#include<bits/stdc++.h>
using namespace std;

#define MX 1000100
#define MN -1000100

#define si(i) scanf("%d",&i)

map<int,int> sqr;
vector<int> vc;

int main()
{
    for(int i=0;i<=sqrt(MX);i++)
    {
        sqr[i*i]=1;
    }
    int n;
    si(n);
    int a;
    for(int i=0;i<n;i++)
    {
        si(a);
        vc.push_back(a);
    }
    sort(vc.begin(),vc.end());
    //reverse(vc.begin(),vc.end());
    for(int i=n-1;i>=0;i--)
    {
        if(sqr[vc[i]]==0)
        {
            printf("%d\n", vc[i]);
            return 0;
        }

    }
}
