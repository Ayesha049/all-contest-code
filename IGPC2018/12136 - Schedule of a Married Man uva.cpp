
#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int h1,m1,h2,m2,h3,m3,h4,m4;
    char cc;
    cin>>h1>>cc>>m1>>h2>>cc>>m2>>h3>>cc>>m3>>h4>>cc>>m4;
    int flag=0;
    int t1= h1*60 +m1;
    int t2= h2*60 +m2;
    int t3= h3*60 +m3;
    int t4= h4*60 +m4;
    if(t3>=t1 && t3<=t2) flag=1;
    if(t4>=t1 && t4<=t2) flag=1;
    if(t1>=t3 && t1<=t4) flag=1;
    if(t2>=t3 && t2<=t4) flag=1;

    if(flag==0) cout<<"Hits Meeting"<<endl;
    else cout<<"Mrs Meeting"<<endl;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        printf("Case %d: ", i + 1);
        solve();
    }
    return 0;
}



