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

char str1[1002],str2[1003];
LL dp[1001][1001];
int main()
{

    while(gets(str1))
    {
        gets(str2);
        int l1,l2;
        l1=strlen(str1);
        l2=strlen(str2);

        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        cout<<dp[l1][l2]<<endl;


    }
    return 0;
}
