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


typedef struct tower{
int x,y,z;
}flr;

vector<flr>v;

int flag[1001],tall[1000];

bool cmp(flr p, flr q)
{
    if(p.x!=q.x)return p.x<q.x;
    else if(p.y!=q.y)return p.y<q.y;
    else return p.z<q.z;
}

int LIS(int x)
{
    int maxi=-1;
    for(int i=0;i<x;i++)
    {
        tall[i]=v[i].z;
        for(int j=0;j<i;j++)
        {
            if((v[i].x>v[j].x && v[i].y>v[j].y) || (v[i].y>v[i].x && v[i].x>v[i].y))
            {
                tall[i]=max(tall[i],tall[j]+v[i].z);
            }
        }
        maxi=max(tall[i],maxi);
    }
    return maxi;
}

int main()
{
    int n,x,y,z;
    int k=1;
    while(cin>>n && n)
    {
    v.clear();
    memset(tall,0,sizeof tall);
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        v.pb( (flr) {x,y,z} );
        v.pb( (flr) {y,x,z} );
        v.pb( (flr) {y,z,x} );
        v.pb( (flr) {z,y,x} );
        v.pb( (flr) {x,z,y} );
        v.pb( (flr) {z,x,y} );
    }
    sort(v.begin(),v.end(),cmp);
    cout<<"Case "<<k++<<": maximum height = ";
    cout<<LIS(v.size())<<endl;
    }
    return 0;
}
