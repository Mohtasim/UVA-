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

int arr[10004],dp[505][10003];
int n,k;

int divi(int sum, int pos)
{
    sum=((sum%k)+k)%k;
    if(pos>=n)
    {
        if(sum==0)return 1;
        else return 0;
    }

    if(dp[sum][pos]!=-1) return dp[sum][pos];

    int ret=0;
    ret=ret | divi(sum+arr[pos],pos+1);
    ret=ret | divi(sum-arr[pos],pos+1);

    return dp[sum][pos]=ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof dp);
        cin>>n>>k;

        //memset(arr, 0, sizeof arr);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int res=divi(0,0);

        if(res==1)cout<<"Divisable"<<endl;
        else cout<<"Not divisable"<<endl;

    }
    return 0;
}
