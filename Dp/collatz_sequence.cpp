#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    long long int A,L,terms;
    int tc=1;
    while(scanf("%lld%lld",&A,&L)==2)
    {
        if(A<0 && L<0)break;
        terms=1;
        long long int tm=A;
        while(tm>1)
        {
            if(tm%2==0)tm/=2;
            else tm=tm*3+1;

            if(tm>L)break;

            terms++;
        }

        printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",tc,A,L,terms);
        tc++;
    }


    return 0;
}
