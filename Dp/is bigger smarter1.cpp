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
vector<int>v;

int tot,w,s,flag[1100],parent[1100];

struct elp{
int ind,wi,si;
}arr[1100];

bool cmp(int p, int q)
{
    if(arr[p].wi>arr[q].wi && arr[p].si<arr[q].si) return true;
    else return false;
}

bool cmpr(elp p, elp q)
{
    if(p.wi<q.wi) return true;

    else return false;
}


void backtrack(int x)
{
    if(x==parent[x])
    {
        v.pb(arr[x].ind);
        return ;
    }
    backtrack(parent[x]);

    v.pb(arr[x].ind);

}

void LIS()
{
    for(int i=0;i<tot;i++)
    {
        flag[i]=1;
        parent[i]=i;
    }

    for(int i=1;i<tot;i++)
    {
        for(int j=0;j<i;j++)
        {
            if( cmp(i,j) && flag[i]<flag[j]+1 )
            {
                flag[i]=flag[j]+1;
                parent[i]=j;
            }
        }
    }
    int maxi=0, ind;

    for(int i=0;i<tot;i++)
    {
        if(flag[i]>maxi)
        {
            maxi=flag[i];
            ind=i;
        }
        //cout<<flag[i]<<" "<<parent[i]<<endl;
    }

    cout<<maxi<<endl;
    backtrack(ind);

}



int main()
{
    tot=0;
    while(cin>>w>>s)
    {
        arr[tot].ind=tot+1;
        arr[tot].wi=w;
        arr[tot].si=s;
        tot++;
    }

    sort(arr,arr+tot,cmpr);

    for(int i=0;i<tot;i++)cout<<arr[i].wi<<" "<<arr[i].si<<endl;

    LIS();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    //cout<<v.size();

    return 0;
}

