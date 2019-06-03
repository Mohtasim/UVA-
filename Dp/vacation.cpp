#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long int
int dp[110][110];
int main()
{
    char a[1000],b[1000];
    int tc=1;
    while(gets(a))
    {
        if(a[0]=='#')break;
        gets(b);
        int la,lb;
        la=strlen(a);
        lb=strlen(b);
        for(int i=1;i<=la;i++)
        {
            for(int j=1;j<=lb;j++)
            {
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",tc,dp[la][lb]);
        tc++;
    }

    return 0;
}
