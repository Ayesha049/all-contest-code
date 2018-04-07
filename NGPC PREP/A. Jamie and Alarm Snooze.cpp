#include<bits/stdc++.h>
using namespace std;

#define si(i) scanf("%d", &i)

int main()
{
    int x,hh,mm;
    int cnt=0;
    si(x);
    si(hh);
    si(mm);
    while(1)
    {
        int m1= mm%10;
        int mm1 = mm/10;
        int m2 = mm1%10;
        int h1= hh%10;
        int hh1 = hh/10;
        int h2 = hh1%10;
        if(h1==7 || h2==7 || m1==7 || m2==7) break;
        if(mm-x<0)
        {
            mm = mm-x+60;
            if(hh==0)
            {
                hh=23;
            }
            else hh--;
        }
        else mm-=x;
        cnt++;
        //cout<<hh<<mm<<endl;
    }
    printf("%d\n",cnt);
}
