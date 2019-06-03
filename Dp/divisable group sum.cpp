#include<bits/stdc++.h>
using namespace std;

#define LL long long int

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SLL(a) scanf("%lld",&a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d",a)
#define PS(a) printf("%s",a)
#define PLL(a) printf("%lld",a)
#define PCASE(kk) printf("Case %d: ",kk++)
#define PCASENL printf("Case %d:\n",kk++)
#define NL puts("")

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))

int n,q,num[10000],d,m;

LL dp[220][250][25];

int func(int idx,int pos,int mode)
{
    if(pos==m)
    {
        if(mode==0)
        {
            return 1;
        }
        else return 0;
    }

    if(idx==n) return 0;

    if(dp[idx][pos][mode]!=-1) return dp[idx][pos][mode];

    int ret=0;

    ret+= func(idx+1,pos,mode);
    ret+=func(idx+1,pos+1,(((mode+num[idx])%d+d)%d));


    return dp[idx][pos][mode]=ret;

}


int main()
{
    int t=1;
    while(S2(n,q)==2)
    {
        if(!n && !q) break;
    for(int i=0;i<n;i++)
    {
        S(num[i]);
    }
    printf("SET %d:",t++),NL;
    int tc=1;
    for(int i=0;i<q;i++)
    {
        S2(d,m);
        memset(dp , -1, sizeof dp);
        LL res=func(0,0,0);
        printf("QUERY %d: %lld",tc++,res),NL;
    }
    }
    return 0;
}
