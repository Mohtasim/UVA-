#include<bits/stdc++.h>
using namespace std;
int dp[110][110];
string print[110];
int main()
{
    string str1[110],str2[110];
    int sz1,sz2;
    while(cin>>str1[0])
    {

    for(sz1=1;;sz1++)
    {
        cin>>str1[sz1];
        if(str1[sz1]=="#")break;
    }

    for(sz2=0;;sz2++)
    {
        cin>>str2[sz2];
        if(str2[sz2]=="#")break;
    }

    for(int i=1;i<=sz1;i++)
    {
        for(int j=1;j<=sz2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int len=dp[sz1][sz2];
    //cout<<len<<endl;
    int indx=0;
    while(dp[sz1][sz2]>0)
    {
        if(str1[sz1-1]==str2[sz2-1])
        {
            print[indx++]=str1[sz1-1];
            sz1--;sz2--;
        }
        else if(dp[sz1-1][sz2]>dp[sz1][sz2-1])sz1--;

        else sz2--;
    }

    for(int i=indx-1;i>=0;i--)
    {
        cout<<print[i];
        if(i!=0)cout<<" ";
    }
    cout<<endl;
    }
    return 0;
}

