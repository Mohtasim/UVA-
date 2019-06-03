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

#define LL long long
#define pb push_back
vector<int>v;

LL n,r[20],c[20],mem[20][20];
string s[20][20];

LL seq(int lt,int rt)
{
    if(mem[lt][rt]!=-1) return mem[lt][rt];

    s[lt][rt]="";
    if(lt==rt)
    {
        stringstream str;
        str<<"A"<<lt+1;
        str>>s[lt][rt];
        return 0;
    }

    LL tem,p,mid;
    tem=(1LL<<62);
    for(int i=lt; i<rt; i++)
    {
        p=r[lt]*c[i]*c[rt]+seq(lt,i)+seq(i+1,rt);
        if(p<tem)
        {
            tem=p;
            mid=i;
        }

    }
    s[lt][rt]="("+s[lt][mid]+"x"+s[mid+1][rt]+")";

    return mem[lt][rt]=tem;
}

int main()
{
    int it=1;
    while(cin>>n && n)
    {

        memset(mem, -1, sizeof(mem));

        for(int i=0; i<n; i++)
        {
            cin>>r[i]>>c[i];
        }
        LL t=seq(0,n-1);

        cout<<"Case "<<it++<<": "<<s[0][n-1]<<endl;

    }
    return 0;
}



