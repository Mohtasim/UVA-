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

int dp[5000][100],coin[110],n;

int diff(int w,int n)
{
    if(n<0)return 0;

    if(dp[w][n]!=-1)return dp[w][n];

    return dp[w][n]=(w>=coin[n])?max((coin[n]+diff(w-coin[n],n-1)),diff(w,n-1)):diff(w,n-1);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>coin[i];
            sum+=coin[i];
        }

        memset(dp, -1, sizeof dp);
//        for(int i=0;i<=sum/2;i++)
//            for(int j=0;j<n;j++)
//                dp[i][j]=-1;
        //sum/=2;
        //cout<<diff(sum/2,n-1)<<endl;
        int p=diff(sum/2,n-1);
        int res=sum-(2*p);
        cout<<p<<" "<<res<<endl;
        memset(coin, 0, sizeof coin);
    }
    return 0;
}

