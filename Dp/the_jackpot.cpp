#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long int
int main()
{
    LL n,arr[10010],sum;
    while(cin>>n)
    {
        if(n==0)break;
        sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)
            {
                cin>>arr[i];
                sum+=arr[i];
                if(sum>maxi)maxi=sum;
                else if(sum<0)sum=0;
            }
        if(maxi>0)printf("The maximum winning streak is %lld.\n",maxi);
        else printf("Losing streak.\n");
    }
    return 0;
}
