#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    int police=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a<0)
        {
            if(police>0) police+=a;
            else ans++;
        }
        else police+=a;
    }
    cout<<ans<<endl;
}

