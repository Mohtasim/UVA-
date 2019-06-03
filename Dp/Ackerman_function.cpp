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


int main()
{
    LL l,h;
    while(cin>>l>>h)
    {
        if(l>h)swap(l,h);
        if(l==0 && h==0)break;
        LL max1=-1,ind;
        for(int i=l;i<=h;i++)
        {
            LL t=i,cnt=0;
            if(t>0){
            for(;;)
            {
                cnt++;
                if(t%2==0)t=t/2;
                else t=t*3+1;
                if(t==1)break;
            }
            }
            if(cnt>max1)
                {
                max1=cnt;
                ind=i;
                }

        }
        //cout<<max1<<" "<<ind<<endl;
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,h,ind,max1);

    }




    return 0;
}
