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
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;

#define LL long long int
#define uLL unsigned long long int

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SLL(a) scanf("%lld",&a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define SC(a) scanf("%c",&a)
#define P(a) printf("%d",a)
#define PS(a) printf("%s",a)
#define PLL(a) printf("%lld",a)
#define PCASE(kk) printf("Case %d: ",kk++)
#define PCASENL(kk) printf("Case %d:\n",kk++)
#define NL puts("")

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define pii pair<int,int>

#define inf 100000000000000LL
#define md 1000000007


template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template <class T> inline T BMOD(T p,T e,T m)
{
    T ret=1;
    while(e)
    {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <typename T>inline T ModInv(T b,T m)
{
    return BMOD(b,m-2,m);
}
template<typename T>inline T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}
template<typename T>inline T gcd(T a,T b)
{
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template<typename T>inline T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/gcd(a,b));
}


//for(__typeof(pp.begin()) i=pp.begin(); i!=pp.end(); i++ )

//knight and king move....



//int Dx[]={-2,-1,1,2,1,2,-2,-1};
//int Dy[]={-1,-2,2,1,-2,-1,1,2};
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//////////////////////////////////////////////////////////////////////////////

int n,tree[4*100004],lazy[4*100002];

void PushDown(int idx)
{
    int l=idx<<1;
    int r=l|1;

    tree[l]=tree[idx];
    tree[r]=tree[idx];
    lazy[idx]=1;
}

void update(int idx,int st,int en,int x,int y,int h)
{
    if(st==x && en==y && lazy[idx]==0)
    {
        if(h>tree[idx])tree[idx]=h;
        return ;
    }
    int mid=(st+en)>>1;
    int l=idx<<1;
    int r=l|1;


    if(lazy[idx]==0)PushDown(idx);


    if(y<=mid)update(l,st,mid,x,y,h);
    else if(x>mid)update(r,mid+1,en,x,y,h);
    else{
        update(l,st,mid,x,mid,h);
        update(r,mid+1,en,mid+1,y,h);
    }

}

int query(int idx,int st,int en,int x,int y,int h)
{

    if(lazy[idx]==0) /// 0 means same value under whole seg
    {
        if(h>=tree[idx])
        {
//            cerr<<idx<<" "<<st<<" "<<en<<" "<<x<<" "<<y<<" "<<h<<endl;
            update(idx,st,en,x,y,h);
//            cerr<<"ok\n";
            return y-x+1;
        }
        else return 0;
    }

    int mid=(st+en)>>1;
    int l=idx<<1;
    int r=l|1;

    if(!lazy[idx])
        PushDown(idx);

    if(y<=mid)return query(l,st,mid,x,y,h);
    else if(x>mid)return query(r,mid+1,en,x,y,h);
    else{
        return query(l,st,mid,x,mid,h)+query(r,mid+1,en,mid+1,y,h);
    }

}

int main()
{
    n=100000;
    int t,tc=1;
    S(t);
    while(t--)
    {
        int N;
        S(N);
        LL res=0;
        for(int i=1;i<=N;i++)
        {
            int l,r,h;
            S3(l,r,h);
            int ans=query(1,1,n,l,r-1,h);
//            cerr<<ans<<endl;
            res+=ans;
        }
        PLL(res),NL;
        memset(lazy,0,sizeof lazy);
    }
    S(n);
    return 0;
}
