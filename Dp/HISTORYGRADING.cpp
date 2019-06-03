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

int arr[50][50];
int main()
{
    int cor[25],stu[25];
    int n;
    scanf("%d",&n);
    int p1,p2;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p1);
        cor[p1-1]=i+1;
    }
    //for(int i=0;i<n;i++)cout<<cor[i]<<" ";

    while(scanf("%d",&p2)==1)
    {
        stu[p2-1]=1;
        //memset(stu, -1,sizeof stu);
        //memset(arr, 0,sizeof arr);

        for(int i=1;i<n;i++)
        {
            //cin>>p2;
            scanf("%d",&p2);
            stu[p2-1]=i+1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cor[i-1]==stu[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        printf("%d\n",arr[n][n]);
        //cout<<arr[n][n]<<endl;

    }

    return 0;
}
