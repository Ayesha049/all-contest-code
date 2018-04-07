#include <bits/stdc++.h>
#define ll             long long
#define f(i,a,b)       for(int i=(a);i<(b);i++)
#define si(a)          scanf("%d",&a)
#define sl(a)          scanf("%I64d",&a)
#define pb             push_back
#define MOD 1000000009
using namespace std;
#define EPS 1e-12
#define PI 3.141592653589



int main()
{
    char s1[30],s2[30];
    scanf("%s%s",s1,s2);
    sort(s1,s1+strlen(s1));
    reverse(s1,s1+strlen(s1));
    if(strlen(s2)>strlen(s1))
    {
        printf("%s",s1);
        return 0;
    }
    else
    {
        for(int i=0; i<strlen(s1); i++)
        {
            if(s2[i]>s1[i]) break;
            if(s2[i]==s1[i]) continue;
            else
            {
                int flag=0;
                for(int j=i+1; j<strlen(s1); j++)
                {
                    if(s1[j]<=s2[i])
                    {
                        char temp = s1[j];
                        for(int k=j; k>i; k--)
                        {
                            s1[k]=s1[k-1];
                        }
                        s1[i]=temp;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    for(int j=i-1; j>=0; j--)
                    {
                        int ff=0;
                        for(int k=j+1; k<strlen(s1); k++)
                        {
                            if(s1[j]>s1[k])
                            {
                                char temp = s1[k];
                                for(int l=k; l>j; l--)
                                {
                                    s1[l]=s1[l-1];
                                }
                                s1[j]=temp;
                                ff=1;
                                break;
                            }
                        }
                        if(ff==1)
                        {
                            sort(s1+j+1,s1+(strlen(s1)));
                            reverse(s1+j+1,s1+(strlen(s1)));
                            break;
                        }
                        sort(s1+j,s1+(strlen(s1)));
                        reverse(s1+j,s1+(strlen(s1)));
                        //printf("%s\n",s1);

                    }
                    break;
                }
            }
            if(s2[i]>s1[i]) break;
        }
        printf("%s\n",s1);
    }
}

