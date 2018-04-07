#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define pb             push_back
#define MOD 1000000009
using namespace std;
#define INF 1e12
#define EPS 1e-12
#define PI 3.141592653589

map<string,string> input;


int main()
{
    int n,m;
    si(n);
    si(m);
    for(int i=0;i<n;i++)
    {
        string name, ip;
        cin>>name>>ip;
        ip += ";";
        input[ip] = name;
    }
    for(int i=0;i<m;i++)
    {
        string name, ip, command;
        cin>>command>>ip;
        name = input[ip];
        cout<<command<<" "<<ip<<" #"<<name<<endl;
    }


}



