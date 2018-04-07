#include<bits/stdc++.h>
using namespace std;
#define si(i) scanf("%d",&i)

map<int,int> mxcnt;
vector<int>vc;

int mx =0;

int main()
{
    int n;
    si(n);
    int a;
    int unq =0;
    for(int i=0;i<n;i++)
    {
        si(a);
        if(mxcnt[a]==0)
        {
            vc.push_back(a);
        }
        mxcnt[a]++;
        mx = max(mx,a);
    }
    for(int i=0;i<vc.size();i++)
    {
        if(mxcnt[vc[i]]%2!=0) unq =1;
    }
    if(unq==0) printf("Agasa\n");
    else printf("Conan\n");

}
