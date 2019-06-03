#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define LL long long int

LL n,p,t;
LL dp[100][100];
LL recur(LL sub,LL rem)
{
    if(sub==1 || rem==0)return 1;

    if(dp[sub][rem]!=-1)return dp[sub][rem];
    LL ret=0;
    for(int i=0;i<=rem;i++)
    {
        ret+=recur(sub-1,rem-i);
        //cout<<ret<<endl;
    }
    return dp[sub][rem]=ret;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        scanf("%lld%lld%lld",&n,&t,&p);
    memset(dp,-1,sizeof dp);
    int rem=t-(n*p);


    printf("%lld\n",recur(n,rem));
    }
    return 0;
}
