#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
vector<int>v;
int dp[100][100][100];
int n,t,p,ha;
int ways(int num, int amount,int make)
{
    if(amount<0)return 0;
    if(num==n)
    {
        if(amount<=ha)
        {
            if(make==0)return 1;
            else return 0;
        }
        else return 0;

    }
    if(dp[num][amount][make]!=-1)return dp[num][amount][make];
    int ret1=0,ret2=0;

    if(make-amount>=0)ret1=ways(num+1,amount,make-amount);

    ret2=ways(num,amount+1,make);

    return dp[num][amount][make]=ret1+ret2;

}

int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>t>>p;
    int make1=t;
    int least=p;
    int n1=t/p-1;
    int ha=make1-(n1*p);

    cout<<ways(0,least,make1);
    return 0;
}
