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
#define inf -199999999LL
vector<int>v[30];

LL m,c,dp[210][50],maxi;

LL expense(int tot,int item)
{
    if(tot<0)return inf;
    if(item==0)return 0;
    LL &ret =dp[tot][item],tm,cm;
    if(dp[tot][item]!=-1)return dp[tot][item];
    ret=inf;
    for(int i=0;i<v[item].size();i++)
    {
        tm=v[item][i];
        if(expense(tot-tm,item-1)!=inf)
        {


            if(ret<(expense(tot-tm,item-1)+tm) )ret=expense(tot-tm,item-1)+tm;
        }
    }
    //cout<<ret<<endl;
    return ret;
}
//
//void expense(int tot,int item)
//{
//    if(item==c)
//    {
//        if(tot<=m && tot>maxi)maxi=tot;
//        return ;
//    }
//    if(tot>m)return ;
//    if(dp[tot][item]!=-1)return ;
//
//    for(int i=0;i<v[item].size();i++)
//        expense(tot+v[item][i],item+1);
//
//}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>m>>c;
        memset(dp,-1,sizeof dp);
        memset(v,0,sizeof v);
        for(int i=1;i<=c;i++)
        {
            int num,t;
            cin>>num;
            for(int j=0;j<num;j++)
            {
                cin>>t;
                v[i].push_back(t);
            }
        }
        //maxi=-123456789LL;
        //expense(0,1);
        if(expense(m,c)==inf)cout<<"no solution"<<endl;
        else cout<<expense(m,c)<<endl;
    }
    return 0;
}
