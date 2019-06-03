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

LL input,n;

priority_queue<int>pq;

int main()
{
    while(cin>>n)
    {
    if(n==0)break;

    for(int i=0;i<n;i++)
    {
        cin>>input;
        pq.push(-input);
    }
    LL sum=0,c=0;
    for(int i=0;i<n-1;i++)
    {
    LL p=pq.top()*(-1);
    pq.pop();
    LL q=pq.top()*(-1);
    pq.pop();
    c=p+q;

    sum+=c;

    pq.push(-c);

    }
    cout<<sum<<endl;
    }
    return 0;
}
