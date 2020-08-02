#include <iostream>
using namespace std;

const int MAXN = 1e5+4;
char S[MAXN],T[MAXN];
int P[MAXN*2];
void manacher(const char*s, int len)
{
	int l = 0;
	T[l++]='$',T[l++]='#';
	for(int i=0;i < len; i++)
	{
		T[l++]=s[i];
		T[l++]='#';
	}
	T[l]=0;
	int r=0,c=0;
	for(int i = 0;i<1;i++)
	{
		int &p=P[i];
		p = r > i ? min(P[2*c-i],r-i) : 1;
		while(T[i+p]==T[i-p]) p++;
		if(i + p > r) r = i + p, c = i;
	}
 } 
