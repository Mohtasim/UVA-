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

struct data{
int a[110],b;
}arr[1000];

int k,n;

int flag[1000];
int parent[1000];

void backtrack(int x)
{
    if(x==parent[x] || x==0)
    {
        v.pb(arr[x].b);
        return ;
    }
    backtrack(parent[x]);

    v.pb(arr[x].b);
}

bool cmpr(int p, int q)
{
    for(int i=0;i<n;i++)
    {
        if(arr[p].a[i]<=arr[q].a[i])return false;
    }

    return true;
}

void LIS()
{
    for(int i=0;i<k;i++)
    {
        flag[i]=1;
        parent[i]=1;
    }
    for(int i=1;i<k;i++)
    {
        for(int j=0;j<i;j++)
        {
            if( cmpr(i,j) && flag[i]<flag[j]+1)
            {
                flag[i]=flag[j]+1;
                parent[i]=j;
            }
        }
    }
    int maxi=0, indx;

    for(int i=0;i<k;i++)
    {
        if(maxi<flag[i])
            {
                maxi=flag[i];
                indx=i;
            }
    }

    cout<<maxi<<endl;

    backtrack(indx);

}


int main()
{

    while(cin>>k>>n)
    {
    for(int i=0;i<k;i++)
    {
        arr[i].b=i+1;
        for(int j=0;j<n;j++)
        {
            cin>>arr[i].a[j];
        }
        sort(arr[i].a,arr[i].a+n);
    }

    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            if( cmpr(i,j) )
            {
                swap(arr[i],arr[j]);
            }
        }
    }

    LIS();

    for(int i=0;i<v.size();i++)
    {
        if(i!=0)
        {
            cout<<" ";
        }
        cout<<v[i];
    }
    cout<<endl;

    v.clear();
    }
    return 0;
}
