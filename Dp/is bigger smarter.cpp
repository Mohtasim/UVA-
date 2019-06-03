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
#define pb push_back
vector<int>v;

int w[1100],s[1100],wi,iq,tot,dp[1100],pos[1100];

struct elephant{
int a,b,c;
}arr[1100];

int b_search(int h,int l,int we,int qe)
{
    int m;
    while(l<h)
    {
        m=(l+h)/2;
        if(arr[m].a<we && arr[m].b>qe)
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
    arr[0].a=w[0];
    arr[0].b=s[0];
    pos[0]=0;
    for(int i=1;i<n;i++)
    {
        if(w[i]<arr[0].a && s[i]>arr[0].b)
        {
            arr[0].a=w[i];
            arr[0].b=s[i];
            pos[i]=0;
        }

        else if(w[i]>arr[len-1].a && s[i]<arr[len-1].b)
        {
            arr[len].a=w[i];
            arr[len].b=s[i];
            len++;
            pos[i]=len-1;
        }
        else if(w[i]<=arr[len-1].a && s[i]>=arr[len-1].b){

            int p=b_search(len-1,0,w[i],s[i]);
            //cout<<p<<endl;

            arr[p].a=w[i];
            arr[p].b=s[i];
            arr[p].c=arr[i].c;
            pos[i]=p;
        }
    }
    return len;
}


int main()
{
    tot=0;
    while(cin>>wi>>iq)
    {
        w[tot]=wi;
        s[tot]=iq;
        arr[tot].c=tot+1;
        tot++;
    }
//    for(int i=0;i<tot;i++)cin>>w[i]>>s[i];

    int ans=LIS(tot);
    cout<<ans<<endl;
    ans--;

    for(int i=0;i<tot;i++)cout<<arr[i].c<<" "<<pos[i]<<endl;

    int id=0;
    for(int i=tot-1;i>=0;i--)
    {
        if(pos[i]==ans)
        {
            ans--;
            dp[id++]=arr[i].c;

        }
    }

    for(int i=id-1;i>=0;i--)
    {
        cout<<dp[i]<<endl;
    }
    return 0;
}


