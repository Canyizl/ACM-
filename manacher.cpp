#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e5+1;
char S[MAXN],T[MAXN];
int P[MAXN];

void manacher(char S[], int len)
{
	int k = 0;
	T[k++]='$',T[k++]='#';
	for(int i=0;i < len; i++)
	{
		T[k++]=S[i];
		T[k++]='#';
	}
	T[k]='0';
	
	int r=0,c=0;	//r代表当前对称的最远距离，c代表该对称的中心 
	for(int i = 0;i < k; i++)
	{
		int &p=P[i];
		p = r > i ? min(P[2*c-i],r-i) : 0; 		//P[2*c-i] --> 对称点x + i = 2*c 对称点坐标为P[2*c-i] 
		while(T[i+p+1]==T[i-p-1]) p++;
		if(i + p > r) {r = i + p; c = i;}		//如果i+p>r 有更大的扩展范围，则把i设为新中心，r为新半径。 
	}
	
/*	for(int i=0;i<k;i++)
	{
		cout<<P[i]<<' ';
	}   输出检验*/
	
	// 其中原字符串的开头下标 = (i - P[i])  / 2  只要返回 开头 到 开头+P[i]-1 之间的字符串 
 } 
 
int main()
{
	int n;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>S[i];
	}
	manacher(S,n);

	return 0;
} 
