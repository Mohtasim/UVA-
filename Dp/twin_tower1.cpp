#include<iostream>
#include<cstdio>


using namespace std;

long long int dp[110][110],n1,n2,na[110],nb[110];

int main()
{
    int tc=1;
    while(cin>>n1>>n2)
    {
        if(n1==0 && n2==0)break;
        for(int i=0;i<n1;i++)cin>>na[i];

        for(int i=0;i<n2;i++)cin>>nb[i];

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(na[i-1]==nb[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //if(tc!=1)cout<<endl;
        printf("Twin Towers #%d\n",tc);
        printf("Number of Tiles : %lld\n\n",dp[n1][n2]);
        tc++;

    }
    return 0;
}

