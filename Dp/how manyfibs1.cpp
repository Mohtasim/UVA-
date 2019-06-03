
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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;

#define BIT 10009
#define GRP     5
#define RADIX   100000  // 10^GRP

typedef complex<long double> Complex;
long double PI = 2 * acos(0.0L);

unsigned revtab[65536];
char fin[4000000];
void init()
{
    for (int x = 0; x < 65536; x++)
    {
        int y = 0;
        for (int i = 0; i < 16; i++)y |= ((x >> i) & 1) << (15 - i);
        revtab[x] = y;
    }
}

void FFT(Complex *a, int N, int dir)
{
    int lgN;
    for (lgN = 1; (1 << lgN) < N; lgN++);
    assert((1 << lgN) == N);
    for (unsigned i = 0; i < N; i++)
    {
        unsigned j = ((revtab[i & 65535] << 16) | revtab[i >> 16]) >> (32 - lgN);
        if (i < j) swap(a[i], a[j]);
    }
    for (int s = 1; s <= lgN; s++)
    {
        int m = 1 << s, h = m/2;
        Complex w, w_m = exp(Complex(0, dir*2*PI/m));
        for (int k = 0; k < N; k += m)
        {
            // even=a[k..k+n), odd=a[k+n..k+m)
            w = 1;
            for (int j = 0; j < h; j++)
            {
                Complex t = w * a[k+h+j];
                a[k+h+j] = a[k+j] - t;
                a[k+j] += t;
                w *= w_m;
            }
        }
    }
}
void parse(vector<Complex> &v, const char *s)
{
    int n = strlen(s);
    int m = (n + GRP-1) / GRP;
    v.resize(m);
    for (int i = 0; i < m; i++)
    {
        int b = n - GRP * i, x = 0;
        for (int a = max(0, b - GRP); a < b; a++)x = x * 10 + s[a] - '0';
        v[i] = x;
    }
}
void Extract(const vector<Complex> &v,int signa,int signb)
{
    int i, N = v.size();
    vector<long long> digits(N + 1, 0);
    long double err = 0;
    for (i = 0; i < N; i++)
    {
        long long x = (long long)(v[i].real() + 0.5);
        err = max(err, abs(x - v[i].real()));
        err = max(err, abs(v[i].imag()));
        digits[i] = x;
    }
    long long c = 0;
    for (i = 0; i < N; i++)
    {
        c += digits[i];
        digits[i] = c % RADIX;
        c /= RADIX;
    }
    //cout << "_______________" << c << endl;
    assert(c == 0);
    for (i = N-1; i > 0 && digits[i] == 0; i--);
    int idx=0,blen=0;
    char buff[30];
    sprintf(buff,"%lld", digits[i]);
    if(signa!=signb)fin[idx++]='-';
    while(buff[blen]!='\0')fin[idx++]=buff[blen++];
    for (i--; i >= 0; i--)
    {
        sprintf(buff,"%.*lld", GRP, digits[i]);
        blen=0;
        while(buff[blen]!='\0')fin[idx++]=buff[blen++];
    }
    fin[idx]='\0';
}
void mul(string &xx,string &yy,int signa,int signb)
{
    vector<Complex> A, B;
    parse(A, xx.c_str());
    parse(B, yy.c_str());
    int N = 1;
    while (N < max(A.size(), B.size())) N *= 2;
    N *= 2;
    A.resize(N);
    B.resize(N);
    FFT(&A[0], N, +1);
    FFT(&B[0], N, +1);
    for (int i = 0; i < N; i++) A[i] *= B[i];
    FFT(&A[0], N, -1);
    for (int i = 0; i < N; i++) A[i] /= N;
    Extract(A,signa,signb);
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}

int iniflag;
struct Bigint
{
    // representations and structures
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise
    void getInt()
    {
        a.clear();
        char ch;
        while(true)
        {
            ch=getchar();
            if(ch=='\n' || ch==' ')break;
            a.push_back(ch);
        }
        (*this) = a;
    }
    // constructors
    Bigint() {if(!iniflag){init();iniflag=1;}} // default constructor
    Bigint( string b )
    {
        if(!iniflag){init();iniflag=1;}
        (*this) = b;   // constructor for string
    }
    // some helpful methods
    int size()
    {
        return a.size();   // returns number of digits
    }
    Bigint inverseSign()
    {
        sign *= -1;
        return (*this);
    }
    // changes the sign
    Bigint normalize( int newSign )   // removes leading 0, fixes sign
    {
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }
    void operator = ( int b )
    {
        (*this)=toString(b);
    }
    // assignment operator
    void operator = ( string b )
    {
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
        //a.
    }
    // conditional operators
    bool operator < ( const Bigint &b ) const   // less than operator
    {

        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator < ( const int &b ) const
    {
        return (*this) < toString(b);
    }
    bool operator == ( const Bigint &b ) const   // operator for equality
    {
        return a == b.a && sign == b.sign;
    }
    bool operator == ( const long long &b ) const
    {
        return (*this) == toString(b);
    }
// mathematical operators
    Bigint operator + ( Bigint b )   // addition operator overloading
    {
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ )
        {
            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator + ( long long b )
    {
        return (*this) + toString(b);
    }
    Bigint operator - ( Bigint b )   // subtraction operator overloading
    {
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign;
        sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ )
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator - ( long long  b )
    {
        return (*this) - toString(b);
    }
    Bigint operator * ( Bigint b )   // multiplication operator overloading
    {
        reverse( a.begin(), a.end() );
        reverse( b.a.begin(), b.a.end() );
        mul(a,b.a,this->sign,b.sign);
        reverse( a.begin(), a.end() );
        reverse( b.a.begin(), b.a.end() );
        return Bigint((string)fin);
    }
    Bigint operator * ( long long b )
    {
        return (*this) * toString(b);
    }

    Bigint operator / ( Bigint b )   // division operator overloading BI/BI
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator / ( long long n )   // division operator overloading BI/BI
    {
        reverse( a.begin(), a.end() );
        //reverse( b.begin(), b.end() );
        long long int rem=0,i,j=0;
        int f=1;
        int idx=0;
        int len=a.length();
        for(i=0; i<len; i++)
        {
            rem=a[i]-'0'+rem*10;
            if(rem/n!=0)f=0;
            if(f==0)fin[idx++]=((char)((rem/n)+'0'));
            rem=rem%n;
        }
        if(f==1)fin[idx++]='0';
        fin[idx]='\0';
        reverse( a.begin(), a.end() );
        //reverse( b.begin(), b.end() );
        return Bigint((string)fin);
    }
    Bigint operator % ( Bigint b )   // modulo operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }
    Bigint operator % ( long long n )   // modulo operator overloading
    {
        reverse( a.begin(), a.end() );
        long long int i,rem=0,j;
        int idx=0;
        int len=a.length();
        for(i=0; i<len; i++)
        {
            rem=a[i]-'0'+rem*10;
            rem=rem%n;
        }
        reverse( a.begin(), a.end() );
        return Bigint(toString(rem));
    }
    void print()
    {
        if( sign == -1 ) putchar('-');
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
    }
    Bigint sqrt()
    {
        reverse( this->a.begin(), this->a.end() );
        string a=this->a;
        int idx=0;
        int n = a.size();
        bool f = n%2;
        n = (f)?n+1:n;
        vector <int> num (n, 0);
        int i;
        if (f)for (i = 0; i < n-1; i++)num[i+1] = a[i] - 48;
        else for (i = 0; i < n; i++)num[i] = a[i] - 48;
        n /= 2;
        vector <int> root(n, 0);
        vector <int> recieve;
        for (i = 0; i < n; i++)
        {
            recieve.push_back (num[i*2]);
            recieve.push_back(num[i*2+1]);
            vector <int> cand(i+1, 0);
            int tmp, ac = 0;
            for (int j = i; j > 0; j--)
            {
                tmp = root[j-1]*2 + ac;
                cand[j] = tmp%10;
                ac = tmp/10;
            }
            if (ac) cand[0] += ac;
            int j;
            for (j = 9; j >= 0; j--)
            {
                int l = 2*(i+1);
                vector <int>  m (l, 0);
                m[l-1] = j*j;
                m[l-2] = m[l-1]/10;
                m[l-1] %= 10;
                int k, o;
                int ac = 0;
                for (k = l-2, o = i; o >= 0 && k > 0; k--, o--)
                {
                    m[k] += cand[o]*j;
                    m[k-1] = m[k]/10;
                    m[k] %= 10;
                }
                bool flag = 1;
                for (k = 0; k < l; k++)
                {
                    if (recieve[k] > m[k]) break;
                    if (recieve[k] < m[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    ac = 0;
                    for (k = l-1; k >= 0; k--)
                    {
                        tmp = recieve[k] - m[k] - ac;
                        if (tmp < 0)recieve[k] = tmp+10,ac = 1;
                        else recieve[k] = tmp;
                        ac = 0;

                    }
                    break;
                }
            }
            root[i] = j;
            fin[idx++]=(j+'0');
        }
        fin[idx]='\0';
        reverse( this->a.begin(),this->a.end() );
        //reverse( b.begin(), b.end() );
        return Bigint(string(fin));
    }
};
istream& operator >> (istream &in, Bigint &x)
{
    in >> x.a;
    x=Bigint(x.a);
    return in;
}
ostream& operator << (ostream &out, const Bigint &x)
{
    string p=x.a;
    reverse(p.begin(),p.end());
    if(x.sign==-1)p="-"+p;
    out << p;
    return out;
}
char inp[BIT];

Bigint fib[500],a,b;
int main()
{
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<500;i++)fib[i]=fib[i-1]+fib[i-2];

    while(cin>>a>>b)
    {
        if(a==0 && b==0)break;
        int cnt=0;
        for(int i=1;i<500;i++)
        {
            if(a<fib[i] && fib[i]<b || (a==fib[i] || b==fib[i]))cnt++;
        }
        cout<<cnt<<endl;
    }


    return 0;
}

