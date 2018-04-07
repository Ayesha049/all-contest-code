#include<bits/stdc++.h>
using namespace std;
int cnt;
bool visited[1009][1009];
char s[1009][1009];
map<pair<int,int>,int>dis;
int n,m,k;


const int DX[] = {0,1,0,-1};
const int DY[] = {1,0,-1,0};


bool checkCell(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return s[x][y] == '.';
}

bool bfs(int x1, int y1,int x2,int y2)
{
    visited[x1][y1] = 1;
    queue<pair<int,int> >q;
    q.push(make_pair(x1,y1));

    while(!q.empty())
    {
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        if(xx==x2 && yy==y2) return true;

        for (int d = 0; d < 4; d++)
        {
            int xxx = xx + DX[d];
            int yyy = yy + DY[d];
            if (!checkCell(xxx, yyy))
                continue;
            if (visited[xxx][yyy])
                continue;

            visited[xxx][yyy] =  true;
            q.push(make_pair(xxx,yyy));
            dis[make_pair(xxx,yyy)]= dis[make_pair(xx,yy)]+1;
        }
    }


    return false;
}




int main()
{

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>s[i][j];

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if(bfs(x1,y1,x2,y2)) cout<<dis[make_pair(x2,y2)]<<endl;
    else cout<<"-1"<<endl;


}

