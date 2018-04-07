#include<bits/stdc++.h>
using namespace std;


priority_queue<int> q;
stack<int> s;

int main()
{
    int n,x;
    char c[10];
    while(scanf("%d",&n)!=EOF)
    {
       int ans=0,cnt=1;
        while(!q.empty()) q.pop();
        while(!s.empty()) s.pop();

        for(int i=0;i<2*n;++i)
        {
            getchar();
            scanf("%s",c);
            if(c[0]=='a')
            {
                scanf("%d",&x);
                s.push(x);
                //q.push(x);
            }
            else
            {
                if(!s.empty())
                {
                    if(s.top()!=cnt)
                    {
                        ans++;
                        while(!s.empty()) s.pop();
                    }
                    else
                    {
                        s.pop();
                        //q.pop();
                    }
                }
                cnt++;


            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
