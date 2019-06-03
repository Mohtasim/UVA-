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
#define LL long long int
#define max 1001
#define len 2600

int fact[1001][10000];
int temp[10000];

void facts()
{

int i,j,k;

fact[0][0]=fact[1][0]=1;

for(i=2;i<max;i++)
{
for(j=0;j<len;j++)
{
fact[i][j]+=fact[i-1][j]*i;

if(fact[i][j]>9)
{
fact[i][j+1]+=fact[i][j]/10;
fact[i][j]%=10;
}
}
}
}

int main()
{
    facts();
    int n;
    while(cin>>n)
    {
        int t;
        cout<<n<<"!"<<endl;
        for(int i=len-1;i>=0;i--)
        {
            if(fact[n][i]!=0)
            {
                t=i;
                break;
            }
        }
        for(int i=t;i>=0;i--)
        {
            cout<<fact[n][i];
        }
        cout<<endl;
    }

    return 0;
}
