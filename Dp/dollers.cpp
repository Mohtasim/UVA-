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
LL coin[]={10000,5000,2000,1000,500,200,100,50,20,10,5};

LL dp[15][40000];
LL ways(LL i, LL amount)
{
    if(i>=11)
    {
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    LL ret1=0,ret2=0;
    if(amount-coin[i]>=0)ret1=ways(i,amount-coin[i]);
    ret2=ways(i+1,amount);

    return dp[i][amount]=ret1+ret2;


}


int main()
{
    double p,q;
    memset(dp, -1, sizeof dp);
    while(cin>>p)
    {
    LL n= int ( (p+.005)*100);
    if(n==0)break;
    LL res=ways(0,n);
    printf("%6.2lf%17lld\n",p,res);
    }
    return 0;
}
