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

LL coin[]={1,5,10,25,50},dp[6][748000];

LL call(LL i, LL amount)
{
    if(i>=5)
    {
        if(amount==0)return 1;
        else return 0;
    }

    if(dp[i][amount]!=-1)return dp[i][amount];
    LL ret1=0,ret2=0;

    if(amount-coin[i]>=0)ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);

    return dp[i][amount]=ret1+ret2;
}

int main()
{

    LL n;
    memset(dp,-1,sizeof dp);
    while(cin>>n)
    {
        cout<<call(0,n)<<endl;
    }

    return 0;
}
