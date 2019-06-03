#include<bits/stdc++.h>
using namespace std;
int arr[1000005],dp[1000005],pos[1000009],aa[1000009];

int binary_search(int h,int l,int b)
{
    int m;

    while (l<h)
    {
        m=(l+h)/2;
        if(dp[m]<b)
        {
            l=m+1;
        }
        else h = m;
    }

    return h;
}


int LIS(int n)
{
    int len=1;
    dp[0]=arr[0];
    pos[0]=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<dp[0])
        {
            dp[0]=arr[i];
            pos[i]=0;
        }

        else if(arr[i]> dp[len-1])
        {
            dp[len++]=arr[i];
            pos[i]=len-1;
        }

        else{
            int p=binary_search(len-1,0,arr[i]);

            dp[p]=arr[i];
            pos[i]=p;

        }

    }
    return len;
}

int print[1000009];

int main()
{
    int n,tot=0;
    while(cin>>n)
    {
        arr[tot]=n;
        tot++;
    }

    int ansl=LIS(tot);
    cout<<ansl<<endl<<"-"<<endl;

    int id=0;
    ansl--;
    for(int i=tot-1;i>=0;i--)
    {
        if(pos[i]==ansl)
        {
            ansl--;
            print[id++]=arr[i];
        }
    }

    for(int i=id-1;i>=0;i--)
    {
        cout<<print[i]<<endl;
    }

    return 0;
}

