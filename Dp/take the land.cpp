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

int mat[110][110],m,n,p;

int main()
{
    while(cin>>m>>n)
    {
    if(m==0 && n==0)break;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>p;
            mat[i][j]=1-p;
        }
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mat[i][j]!=0)
            mat[i][j]=mat[i-1][j]+mat[i][j];
        }
    }

//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<endl;
//    }


    LL area=0,tm;
    for(int i=1;i<=m;i++)
       {
        for(int j=1;j<=n;j++)
        {
           tm=mat[i][j];
           if(tm>area)area=tm;
           for(int k=j+1;k<=n;k++)
           {
               if(mat[i][j]<=mat[i][k])tm+=mat[i][j];
               else tm=0;
               if(tm>area)area=tm;
           }
           for(int k=j-1;k>=0;k--)
           {
               if(mat[i][j]<=mat[i][k])tm+=mat[i][j];
               else tm=0;
               if(tm>area)area=tm;
           }
           //if(tm>area)area=tm;

        }
        //cout<<area<<endl;
       }
    cout<<area<<endl;
    }
    return 0;
}
//* 11450, 437, 562, 836, 10036, 10337, 10616, 10635, 10721, 10891, 11762.
