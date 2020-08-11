#include <iostream>
#include <cmath>
using namespace std;

int c[6]={0,2,2,4,5,6};
int w[6]={0,6,3,6,4,5};
int dp[11]; //

int pack()
{
    int v=10;
    for(int i=0;i<=v;i++)
        dp[i]=0;
    for(int i=1;i<=5;i++)
        for(int j=v;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
    return dp[10];
}

int main()
{
    cout<<pack();
    return 0;
}
