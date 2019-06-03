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

LL n,k,dp[110][110];

LL ways(int make, int use)
{
    if(make==0 || use==1) return 1;

    if(dp[make][use]!=-1) return dp[make][use];

    LL ret=0;

    for(int i=0;i<=make;i++)
    {
        ret+=ways(make-i,use-1);
    }
    return dp[make][use]=ret;
}

int main()
{
    while(cin>>n>>k)
    {
    if(n==0 && k==0)break;
    memset(dp, -1, sizeof(dp));
    LL ans=ways(n,k);
    cout<<ans<<endl;
    }
    return 0;
}
