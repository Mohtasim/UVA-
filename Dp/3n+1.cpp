#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;

int main()
{
    int a,b;

    while(cin>>a>>b)
    {
    cout<<a<<" "<<b;

    if(a>b)swap(a,b);
    //cout<<a<<" "<<b<<endl;

    int cnt,c,t;

    int maxi=0;

    for(int i=a;i<=b;i++)
    {

        c=i;
        cnt=1;
        while(c>1)
        {
            if(c%2==0)c=c/2;
            else c=c*3+1;

            cnt++;
        }

        if(cnt>maxi)maxi=cnt;

    }

    cout<<" "<<maxi<<endl;

    }
    return 0;

}
