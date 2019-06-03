#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#include<cstdio>
using namespace std;
#define LL long long int

int input[100005],dp[100005],pos[100005],ans[100005];
char ch[10005];
int binery_search(int h,int l,int b)
{
    int m;

    while(l<h)
    {
        m=(l+h)/2;

        if(dp[m]<b)
        {
            l=m+1;
        }

        else h=m;
    }

    return h;
}

int LIS(int n)
{
    int len=1;
    dp[0]=input[0];
    pos[0]=0;
    for(int i=1;i<n;i++)
    {
        if(input[i]<dp[0])
        {
            dp[0]=input[i];
            pos[i]=0;
        }
        else if(input[i]>dp[len-1])
        {
            dp[len++]=input[i];
            pos[i]=len-1;
        }
        else{
            int p=binery_search(len-1,0,input[i]);
            dp[p]=input[i];
            pos[i]=p;
        }
    }
    return len;

}


int main()
{
    int n;
    cin>>n;
    getchar();
    gets(ch);
    int fl=false;
    while(n--)
    {
        int p,tot=0;
        while(gets(ch) && strlen(ch))
        {
            input[tot]=atoi(ch);
            tot++;
        }
        if(fl)cout<<endl;
        fl=true;
        int hit=LIS(tot);
        cout<<"Max hits: "<<hit<<endl;
        int indx=0;
        hit--;
        for(int i=tot-1;i>=0;i--)
        {
            if(pos[i]==hit)
            {
                hit--;
                ans[indx++]=input[i];
            }
        }

        for(int i=indx-1;i>=0;i--)
        {
            cout<<ans[i]<<endl;
        }
        //if(fl!=0){cout<<endl;fl=1;}
    }
    return 0;
}
