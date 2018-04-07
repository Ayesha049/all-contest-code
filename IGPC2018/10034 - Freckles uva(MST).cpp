#include<bits/stdc++.h>

using namespace std;


typedef pair<float,float> pairz ;
typedef pair<float, pair<int,int> > doublepair;

map < int, int > parent;
vector<pairz> a;
vector< doublepair > edges;

float finddist (float x,float y,float a,float b)
{
    return sqrt( ( abs(x-a)*abs(x-a) ) + ( abs(y-b) * abs(y-b) ) );
}

void make_parent2(int n)
{
    parent.clear();
    for (int i=0; i<=n; i++)
    {
        parent[i]=-1;
    }
}

int Find(int node)
{
    if(parent[node]==-1) return node;
    parent[node]=Find(parent[node]);
    return parent[node];
}

void Union(int node1, int node2)
{
    int a= Find(node1);
    int b= Find(node2);
    parent[b]=a;
}

float kruskal(vector<doublepair> &p)
{
    int x, y;
    float cost, minimumCost = 0;
    for(int i = 0; i < p.size(); ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin >> n;
        edges.clear();
        a.clear();

        float x,y;
        for(int i=0; i<n; i++)
        {
            cin >> x >> y ;
            a.push_back(pairz(x, y));

        }


        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                pairz tz = a[i];
                pairz tz1 = a[j];
                float dz = finddist ( tz.first, tz.second, tz1.first,tz1.second) ;
                edges.push_back ( make_pair ( dz, make_pair (i, j) ) ) ;
            }

        sort(edges.begin(), edges.end());


        make_parent2(edges.size());


        float dist=kruskal(edges);
        printf("%.2f\n",dist);
        if(tc > 0) printf("\n");
    }
    return 0;
}


