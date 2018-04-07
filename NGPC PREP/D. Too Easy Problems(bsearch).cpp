#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define MOD 1000000007
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589

int n;
int T;
vector< pair< pair <int,int> , int> >problems;

bool check(int nn)
{
    int tt=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        //cout<<" tt "<<tt<<endl;
        //cout<< problems[i].first <<" "<<problems[i].second<<endl;
        if(problems[i].first.second>=nn)
        {
            //cout<< problems[i].first.first <<" "<<problems[i].first.second<<endl;
            if((tt+problems[i].first.first) <= T)
            {
                cnt++;
                tt+=problems[i].first.first;
                if(cnt==nn) break;
            }
            else break;
        }
    }
    //cout<<"mid  "<<nn<<"cnt "<<cnt<<endl;
    if(cnt>=nn) return true;
    return false;
}

int main()
{
    si(n);
    si(T);
    int a;
    int b;
    for(int i=0;i<n;i++)
    {
        si(a);
        si(b);
        problems.push_back(make_pair(make_pair(b,a),i+1));
        //cout<< problems[i].first.first <<" "<<problems[i].first.second<<endl;
    }
    sort(problems.begin(),problems.end());
    int lw=0;
    int hi=n;
    int ans=0;
    while(lw<=hi)
    {
        int mid = (lw+hi)/2;
        if(check(mid))
        {
            ans=mid;
            lw=mid+1;
        }
        else hi = mid-1;
    }
    printf("%d\n",ans);
    int tt=0;
    int cnt=0;
    vector<int>output;
    for(int i=0;i<n;i++)
    {
        //cout<<" tt "<<tt<<endl;
        //cout<< problems[i].first <<" "<<problems[i].second<<endl;
        if(problems[i].first.second>=ans)
        {
            if((tt+problems[i].first.first) <= T)
            {
                cnt++;
                tt+=problems[i].first.first;
                output.push_back(problems[i].second);
                if(cnt==ans) break;
            }
            else break;
        }
    }
    printf("%d\n",output.size());
    for(int i=0;i<output.size();i++)
    {
        printf("%d ",output[i]);
    }
    printf("\n");

}


