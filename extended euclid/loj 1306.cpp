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

LL gc;

pair<LL,LL> extended_euclid(LL a,LL b)
{
    if(b==0)
    {
        gc=a;
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
//    #ifndef ONLINE_JUDGE
//    freopen("test.inp", "r", stdin);
//    //freopen("test.out", "w", stdout);
//#endif
    LL a,b,c,x1,x2,y1,y2,x,y;

    int t,tc=1;
    S(t);
    while(t--)
    {
        SLL3(a,b,c);
        SLL2(x1,x2);
        SLL2(y1,y2);
//        c=-c;
        pair<LL,LL>rr=extended_euclid(a,b);
        x=rr.first;
        y=rr.second;


        LL res=0;
        if (!a && !b)
        {
            if (c) res = 0;
            else res = (x2 - x1 + 1) * (y2 - y1 + 1);

//            cout<<x2-x1+1<<" "<<y2-y1+1<<endl;
        }
        else if (!a)
        {
            if (c % b) res = 0;
            else
            {
                c = -c / b;
                if (y1 <= c && c <= y2) res = (x2 - x1 + 1);
                else res = 0;
            }
        }
        else if (!b)
        {
            if (c % a) res= 0;
            else
            {
                c = -c / a;
                if (x1 <= c && c <= x2) res = (y2 - y1 + 1);
                else res = 0;
            }
        }
        if (gc && c % gc == 0)
        {
            //d = abs(d);
            x *= (-c / gc);
            y *= (-c / gc);
            b /= gc;
            a /= gc;
            swap(a, b); // x + ka, y - kb

            double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
            if (p > q) swap(p, q);
            x1 = (LL)ceil(p);
            x2 = (LL)floor(q);

            p = (y - y1) / (double)b;
            q = (y - y2) / (double)b;
            if (p > q) swap(p, q);
            y1 = (LL)ceil(p);
            y2 = (LL)floor(q);

            //printf("xy %lld %lld : ab %d %d : x %lld %lld : y %lld %lld\n", x, y, a, b, x1, x2, y1, y2);

            x1 = max(x1, y1);
            x2 = min(x2, y2);

            res = x2-x1+1;
            res=max(res,0LL);
        }
        PCASE(tc);
        PLL(res),NL;
    }
    return 0;
}

