#include<bits/stdc++.h>
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

#define pb push_back
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define pii pair<int,int>

template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template <typename T>inline T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
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

//for(__typeof(pp.begin()) i=pp.begin(); i!=pp.end(); i++ )

//knight and king move....



//int Dx[]={-2,-1,1,2,1,2,-2,-1};
//int Dy[]={-1,-2,2,1,-2,-1,1,2};
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//////////////////////////////////////////////////

LL n,n1,n2,c1,c2;

pair<LL,LL> extended_euclid(LL a,LL b)
{
    if(b==0)
    {
        return mp(1,0);
    }

    pair<LL,LL> tmp=extended_euclid(b,a%b);
    LL x1=tmp.first, y1=tmp.second;
    LL x=y1;
    LL y=x1-(a/b)*y1;
    return mp(x,y);
}


int main()
{
    while(SLL(n)==1)
    {
        if(n==0)break;
        SLL2(c1,n1);
        SLL2(c2,n2);
        LL g=__gcd(n1,n2);

        if(n%g!=0)
        {
            printf("failed\n");
            continue;
        }

        pair<LL,LL>res=extended_euclid(n1,n2);
        LL x=res.first;
        LL y=res.second;

        n/=g;
        n1/=g;
        n2/=g;

        x*=(n);
        y*=(n);

        LL lb,rb;

        lb=(LL)ceil(-(double)x/n2);
        rb=(LL)floor((double)y/n1);

        if(lb>rb)
        {
            printf("failed\n");
            continue;
        }

        LL ans1=c1*(x+(n2)*lb)+c2*(y-(n1)*lb);
        LL ans2=c1*(x+(n2)*rb)+c2*(y-(n1)*rb);

        if(ans1<ans2)
        {
            cout<<(x+(n2*lb))<<" "<<(y-(n1*lb))<<endl;
//            printf("%lld %lld\n",(x+(n2)*lb),(y-(n1)*lb));
        }
        else
        {
                cout<<(x+(n2*rb))<<" "<<(y-(n1*rb))<<endl;

//            printf("%lld %lld\n",(x+(n2/g)*rb),(y-(n1/g)*rb));
        }


    }
    return 0;
}


