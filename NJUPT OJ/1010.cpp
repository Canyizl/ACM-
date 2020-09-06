#include <iostream>
using namespace std;

int dp[1001];

/*int dp(int n)
{
	if(n==1) return 1;
	int result=1;
	for(int i=1;i<=n/2;i++)
		result+=dp(i);
	return result;
} */

int main()
{
	int n;
	cin>>n;
	dp[0]=0,dp[1]=1;
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i/2;j++)
			dp[i]+=dp[j];
	cout<<dp[n];
	return 0;
} 
