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
#define pii pair<int,int>

long long int gcd(long long int c,long long int d)
{
    if(d==0) return c;
    else return gcd(d,c%d);
}

//knight and king move....

//int Dx[]={-2,-1,1,2,1,2,-2,-1};
//int Dy[]={-1,-2,2,1,-2,-1,1,2};
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//////////////////////////////////////////////////

int n,p,q,ps[62502],qs[62502],dp[62520][62520];

int main()
{
    int t,tc=1;
    S(t);
    while(t--)
    {
        S3(n,p,q);
        for(int i=0;i<=p;i++)
            S(ps[i]);

        for(int i=0;i<=q;i++)
            S(qs[i]);

        for(int i=1;i<=p+1;i++)
        {
            for(int j=1;j<=q+1;j++)
            {
                if(ps[i-1]==qs[j-1])dp[i][j]=dp[i-1][j-1]+1;

                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        PCASE(tc);
        P(dp[p+1][q+1]),NL;
        memset(dp, 0, sizeof dp);
        memset(ps, 0, sizeof ps);
        memset(qs, 0, sizeof qs);

    }
    return 0;
}
