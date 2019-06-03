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

LL coin[]={1,5,10,25,50},dp[6][300000];

LL call(LL i,LL amount)
{
    if(i>=5)
    {
        if(amount==0)return 1;
        else return 0;
    }

    LL ret1=0,ret2=0;
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(amount-coin[i]>=0)ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);

    return dp[i][amount]=ret1+ret2;

}

int main()
{
    LL n,res;
    memset(dp, -1, sizeof dp);
    while(cin>>n)
    {
    res=call(0,n);
    if(res==1)
    {
        cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
    }
    else cout<<"There are "<<res<<" ways to produce "<<n<<" cents change."<<endl;
    }

    return 0;
}
