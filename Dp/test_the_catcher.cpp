#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL height[33005],dp[33005];
int binery_search(int l,int h,int x)
{
    int m;
    while(l<h)
    {
        m=(l+h)/2;
        if(dp[m]<x)
        {
            l=m+1;
        }
        else h=m;
    }
    return h;
}

int LIS(int n)
{
    int len=1,p;
    dp[0]=height[0];

    for(int i=1;i<n;i++)
    {
        if(height[i]<dp[0])
        {
            dp[0]=height[i];
        }
        else if(height[i]>dp[len-1])
        {
            dp[len++]=height[i];
        }
        else{
            p=binery_search(0,len-1,height[i]);
            dp[p]=height[i];

        }
    }
    return len;
}


int main()
{
    int arr[33005],tc;
    tc=1;
    while(cin>>arr[0])
    {
        if(arr[0]==-1)break;
        int l=1;
        for(int i=1;;i++)
        {
            cin>>arr[i];
            if(arr[i]==-1)break;
            l++;
        }
        int j=0;
        for(int i=l-1;i>=0;i--)
        {
            height[j]=arr[i];
            j++;
        }
        if(tc!=1)cout<<endl;
        printf("Test #%d:\n",tc);
        cout<<"  maximum possible interceptions: ";
        cout<<LIS(l)<<endl;
        tc++;
    }
    return 0;
}

