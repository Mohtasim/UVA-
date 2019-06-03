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
#define inf 9999999999LL

int cost[11][1001],x,dp[12][1005];

int DP(int i,int j,int n)
{
    if(j==n && i==0)return 0;

    else if(j==n || i<0 || i>9)return inf;

    if(dp[i][j]!=-1) return dp[i][j];

    if(i==0)
    {
        if(j==n-1)
            return dp[i][j]=min(min(60-cost[i][j]+DP(i+1,j+1,n),20-cost[i][j]+DP(i-1,j+1,n)),30-cost[i][j]+DP(i,j+1,n));
        else return dp[i][j]=min(60-cost[i][j]+DP(i+1,j+1,n),20-cost[i][j]+DP(i-1,j+1,n));
    }
    else
return dp[i][j]=min(min(60-cost[i][j]+DP(i+1,j+1,n),20-cost[i][j]+DP(i-1,j+1,n)),30-cost[i][j]+DP(i,j+1,n));

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        x/=100;
        for(int i=9;i>=0;i--)
        {
            for(int j=0;j<x;j++)
            {
                cin>>cost[i][j];
            }
        }
        memset(dp, -1,sizeof dp);
        int ans;
        ans=DP(0,0,x);
        cout<<ans<<endl<<endl;
    }
    return 0;
}
