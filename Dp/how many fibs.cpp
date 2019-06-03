#include<iostream>
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
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
string rev(string a)
{
    int i,j;
    string b="";
    for(i=0,j=a.length()-1; i<a.length(); i++,j--)
        b+=a[j];
    return b;
}
string add(string e, string f)
{
    int i,j,x,y,sum,s;
    string c="";
    string a,b,d;
    int temp=0;
    a=rev(e);
    b=rev(f);
    for(i=0; i<a.length(); i++)
    {
        if(i<b.length())
        {
            x=a[i]-'0';
            y=b[i]-'0';
            sum=x+y+temp;
            s=sum%10;
            c+=s+'0';
            temp=0;
            if(sum>9) temp=1;
            if(i==a.length()-1 && temp==1)
                c+='1';
        }
        else
        {
            x=a[i]-'0';
            sum=temp+x;
            s=sum%10;
            c+=s+'0';
            temp=0;
            if(sum>9) temp=1;
            if(i==a.length()-1 && temp==1)
                c+='1';
        }
    }
    d=rev(c);
    return d;
}

int cmpr(string a,string g1,string g2)
{
    int p;

    if(a.length()>g1.length() && a.length()<g2.length())return 1;

    else if(a.length()==g1.length() && a.length()<g2.length())
    {

        for(int i=0;i<a.length();i++)
        {
            if(a[i]>g1[i]){p=1;break;}
            else if(a[i]<g1[i]){p=0;break;}
            if(i==a.length()-1)p=1;
        }
        return p;
    }

    else if(a.length()>g1.length() && a.length()==g2.length())
    {

        for(int i=0;i<a.length();i++)
        {
            if(a[i]<g2[i]){p=1;break;}
            else if(a[i]>g2[i]){p= 0;break;}
            if(i==a.length()-1)p=1;
        }
        return p;
    }

    else if(a.length()==g1.length() && a.length()==g2.length())
    {
        int t1=0,t2=0,t3=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]>g1[i])
            {
                if(a[i]<g2[i]){p=1;break;}
            }
            else if(a[i]<g1[i])
            {
                if(a[i]>g2[i]){p=0;break;}
            }
            else if(a[i]>g1[i] && a[i]==g2[i])t2++;
            else if(a[i]==g1[i] && a[i]<g2[i])t1++;
            else if(a[i]==g1[i] && a[i]==g2[i])t3++;

            if(t1==a.length()-1 || t1==a.length()-1 || t1==a.length()-1){p=1;break;}
        }
        return p;
    }

    else return 0;

}

int main()
{

    map<int,string>fib;
    fib[0]="0";
    fib[1]="1";
    for(int i=2;i<=500;i++)
    {
        fib[i]=add(fib[i-1],fib[i-2]);
    }
    string n,m;
    while(cin>>n>>m)
    {
       // cout<<n[0]<<" "<<n[1]<<endl;

        //if(fib[8][1]<m)cout<<"ok";
        //cout<<fib[7][]<<" "<<m[0]<<endl;
        int cnt=0;
        for(int i=0;i<500;i++)
        {
            //cout<<fib[i]<<endl;

            //if(cmpr(fib[i],n,m)==1)cout<<fib[i]<<endl;

            cnt+=cmpr(fib[i],n,m);
        }
        cout<<cnt<<endl;

    }

    return 0;
}

