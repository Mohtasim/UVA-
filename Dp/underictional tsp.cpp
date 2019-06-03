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

#define pb push_back
#define LL long long int
vector<int>v;

int m,n,mat[15][110],cost[110][110],flag[110][110];

LL tsp(LL r,LL c)
{
    if(c==n) return mat[r][c];

    if(cost[r][c]!=-1) return cost[r][c];

    LL ret=mat[r][c] , p;

    if(m==1)
    {
        p=tsp(1,c+1);
        ret+=p;
        flag[r][c]=1;
    }
    else if(m==2)
    {
        p=min(tsp(1,c+1),tsp(2,c+1));
        ret+=p;
        if(p==tsp(1,c+1))
            flag[r][c]=1;
        else flag[r][c]=2;
    }
    else if(r==m)
    {
        p=min(tsp(r,c+1),min(tsp(r-1,c+1),tsp(1,c+1)));
        ret+=p;
        if(p==tsp(1,c+1))flag[r][c]=1;
        else if(p==tsp(r-1,c+1))flag[r][c]=r-1;
        else if(p==tsp(r,c+1))flag[r][c]=r;

    }

    else if(r==1)
    {
        p=min(tsp(r,c+1),min(tsp(m,c+1),tsp(r+1,c+1)));
        ret+=p;
        if(p==tsp(r,c+1))flag[r][c]=r;
        else if(p==tsp(r+1,c+1))flag[r][c]=r+1;
        else if(p==tsp(m,c+1))flag[r][c]=m;
    }
    else {
       p=min(tsp(r,c+1),min(tsp(r-1,c+1),tsp(r+1,c+1)));
        ret+=p;
        if(p==tsp(r-1,c+1))flag[r][c]=r-1;
        else if(p==tsp(r,c+1))flag[r][c]=r;
        else if(p==tsp(r+1,c+1))flag[r][c]=r+1;
    }

    return cost[r][c]=ret;

}


int main()
{
    while(cin>>m>>n)
    {

    memset(cost, -1, sizeof(cost));
    memset(flag, 0, sizeof(flag));
    memset(mat, 0, sizeof(mat));

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        cin>>mat[i][j];

    LL ans;
    ans=tsp(1,1);
    LL start=1;
    for(LL i=2;i<=m;i++)
    {
        if(tsp(i,1)<ans)
        {
            ans=tsp(i,1);
            start=i;
        }
    }
    cout<<start;
    double qans=1;
    cout<<setprecision(6)<<fixed<<qans<<endl;
    start=flag[start][1];
    for(int i=2;i<=n;i++)
    {
        cout<<" "<<start;
        start=flag[start][i];
    }

    cout<<endl<<ans<<endl;
    }
    return 0;
}

