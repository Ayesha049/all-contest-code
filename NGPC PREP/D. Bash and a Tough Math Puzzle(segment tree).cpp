#include<bits/stdc++.h>
using namespace std;

#define si(i) scanf("%d", &i)
#define sl(i) scanf("%I64d", &i)
#define MX 500010

long long tree[MX*3];
long long A[MX];


long long gcd(long long a,long long b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

void build(int node, int s, int e)
{
    if(s==e) tree[node] = A[s];
    else
    {
        int l = node*2;
        int r = node*2+1;
        int mid = (s+e)/2;
        build(l,s,mid);
        build(r,mid+1,e);
        tree[node] = gcd(tree[l],tree[r]);
    }
}



void update(int node, int s, int e, int ind, long long val)
{
    if(s==e)
    {
        A[ind] = val;
        tree[node] = val;
        return;
    }
    int l = node*2;
    int r = l+1;
    int mid = (s+e)/2;
    if(ind>mid)
    {
        update(r,mid+1,e,ind,val);
    }
    else
    {
        update(l,s,mid,ind,val);
    }
    tree[node] = gcd(tree[l],tree[r]);

}

int flag;

int quary(int node, int s, int e, int rl, int rr,int xx)
{
    if(flag) return 2;
    if(rr<s || rl>e) return 0;
    if(s==e)
    {
        if(tree[node]%xx==0) return 0;
        else return 1;
    }
    if(rl<=s && rr>=e)
    {
        if(tree[node]%xx==0) return 0;
        else
        {
            int l = node*2;
            int r = node*2+1;
            int mid = (s+e)/2;
            int q1 = quary(l,s,mid,rl,rr,xx);
            int q2 = quary(r,mid+1,e,rl,rr,xx);
            if(q1+q2>1) flag=1;
            return q1+q2;
        }
    }
    else
    {
        int l = node*2;
        int r = node*2+1;
        int mid = (s+e)/2;
        int q1 = quary(l,s,mid,rl,rr,xx);
        int q2 = quary(r,mid+1,e,rl,rr,xx);
        if(q1+q2>1) flag=1;
        return q1+q2;
    }
}



int main()
{
    int n;
    si(n);
    long long a;
    int xx;
    for(int i=1; i<=n; i++)
    {
        sl(a);
        A[i]=a;
    }
    build(1,1,n);
    int q;
    si(q);
    while(q--)
    {
        int tt;
        si(tt);
        if(tt==1)
        {
            int l,r;
            si(l);
            si(r);
            si(xx);
            flag=0;
            if(quary(1,1,n,l,r,xx)<=1) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            int ind;
            long long val;
            si(ind);
            sl(val);
            update(1,1,n,ind,val);
        }
    }
}
