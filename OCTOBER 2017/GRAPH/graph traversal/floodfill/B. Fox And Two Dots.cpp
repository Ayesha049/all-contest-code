#include<bits/stdc++.h>
using namespace std;
int cnt;
bool visited[55][55];
char s[55][55];
int n,m,k;
pair<int,int> parent[55][55];


const int DX[] = {0,1,0,-1};
const int DY[] = {1,0,-1,0};


bool checkCell(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

bool dfs(int x, int y)
{
    cout<<x<<" "<<y<<"   ";
    if(visited[x][y]==1) return true;
    visited[x][y] = 1;
    for (int d = 0; d < 4; d++)
    {
        int xx = x + DX[d];
        int yy = y + DY[d];

        if (!checkCell(xx, yy))
            continue;
        if(s[x][y]==s[xx][yy])
        {
            if(make_pair(xx,yy)!=parent[x][y])
            {
                parent[xx][yy]=make_pair(x,y);
                if(dfs(xx, yy))
                {
                    //cout<<"bingooo   "<<xx<<" "<<yy<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void dfs2()
{
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(visited[i][j]==0)
            {
                parent[i][j]=make_pair(-1,-1);
                if(dfs(i,j))
                {
                    cout<<"Yes"<<endl;
                    return;
                }
                cout<<endl;
            }
    }
    cout<<"No"<<endl;
}


int main()
{

    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>>s[i][j];
    dfs2();
}

