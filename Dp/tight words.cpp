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
#define inf 9999999
#define cini(p,q) scanf("%d%d",&k,&n)
#define cind(p,q) scanf("%lf%lf",&k,&n)



double dp[150][11],tot,tight;
int n,k;
int main()
{
    while(cini(k,n)==2)
    {
        memset(dp, 0, sizeof dp);

        for(int i=0;i<=k;i++)
        {
            dp[1][i]=1;
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {

                if(j>0)
                {
                    dp[i][j]+=dp[i-1][j-1];
                }
                dp[i][j]+=dp[i-1][j];
                if(j<k)
                {
                    dp[i][j]+=dp[i-1][j+1];
                }

            }
        }

        tight=0.0;
        for(int i=0;i<=k;i++)
        {
            tight+= dp[n][i];
            //cout<<dp[n][i]<<endl;
        }

        tot=1;
        double tm=k+1;
        for(int i=1;i<=n;i++)
        {
            tot*=tm;
        }
        //cout<<tot<<" "<<tight<<endl;

        double res=tight/tot;
        res*=100;

        printf("%.5lf\n",res);
    }


    return 0;
}
