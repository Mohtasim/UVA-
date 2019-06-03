#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int dp[1010][1010];
int main()
{

    char ch1[1010],ch2[1010];
    int tc=1;
    while(gets(ch1))
    {
        memset(dp,0,sizeof dp);
        gets(ch2);
        int chk=0;
        if(ch2[0]=='\0' || ch1[0]=='\0')
            {
                printf(" %d. Blank!\n",tc++);
                chk=1;
            }
        string str1[1000],str2[1000];
        int l1=strlen(ch1);
        int l2=strlen(ch2);
        int p1=0,p2=0;
        int j1=-1;
        for(int i=0;i<l1;i++)
        {

            if(isalpha(ch1[i]) || isdigit(ch1[i]))
            {
                if(p1==0)
                    {
                        j1++;
                        str1[j1]+=ch1[i];
                        p1=1;

                    }
                else str1[j1]+=ch1[i];

            }
            else{
                p1=0;
            }
        }

        int j2=-1;
        for(int i=0;i<l2;i++)
        {

            if(isalpha(ch2[i]) || isdigit(ch2[i]))
            {
                if(p2==0)
                    {
                        j2++;
                str2[j2]+=ch2[i];
                p2=1;
                    }
                    else str2[j2]+=ch2[i];

            }
            else{
                p2=0;
            }
        }
   //     cout<<j1<<" "<<j2<<endl;
        for(int i=0;i<=j1;i++)cout<<str1[i]<<" ";
        cout<<endl;
        for(int j=0;j<=j2;j++)cout<<str2[j]<<" ";
        cout<<endl;

       for(int i=1;i<=j1+1;i++)
       {
           for(int j=1;j<=j2+1;j++)
           {
               if(str1[i-1]==str2[j-1])
               {
                   dp[i][j]=dp[i-1][j-1]+1;
               }
               else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }

       }
       if(chk==0)printf(" %d. Length of longest match: %d\n",tc++,dp[j1+1][j2+1]);
   //     cout<<dp[j1+1][j2+1]<<endl;


    }


    return 0;
}
