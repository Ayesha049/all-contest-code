#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
map < int , int > parent;

int  nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void make_parent2(int n)
{
    for (int i=1; i<=n; i++)
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
    if(a==b && a!=-1 && b!=-1) return;
    parent[b]=a;
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
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
    int x, y;
    long long weight, cost, minimumCost;

    cin >> nodes >> edges;
    make_parent2(nodes);
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
