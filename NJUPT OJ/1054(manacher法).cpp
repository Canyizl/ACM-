#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAXN=256;
char S[MAXN],T[MAXN*2];
int P[MAXN*2];

bool manacher(char S[],int len)
{
	int k=0;
	T[k++]='$',T[k++]='#';
	for(int i=0;i<len;i++)
	{
		T[k++]=S[i];
		T[k++]='#';
	}
	T[k++]='0';
	
	int c=0,r=0;
	for(int i=0;i<k;i++){
		int &p=P[i];
		p = r > i ? min(P[2*c-i],r-i):0;
		while(T[i+p+1]==T[i-p-1])p++;
		if(i+p>r){
			r=i+p;
			c=i;
		}
	}
	
/*	for(int i=0;i<k;i++){
		cout<<T[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<k;i++){
		cout<<P[i]<<" ";
	}  */ 

	int maxlen=0,maxi=0;
	for(int i=0;i<k;i++){
		if(P[i]>maxlen){
			maxlen=P[i];
			maxi=i;
		}
	}
	
	int hwlen=maxlen;
	if(len==hwlen) return true;
	else return false;
	//开始为(i-P[i])/2 终点为开始+P[i]-1    长度为P[i]-1;(从第0位开始算的话） 
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>S){
		int len=strlen(S);
		for(int i=0;i<len;i++){
			if(S[i]>='A'&&S[i]<='Z') S[i]=S[i]-'A'+'a'; //注意等于号！！！ 
		}
		manacher(S,len);
		bool flag=manacher(S,len);
		if(flag){cout<<"Bingle! Palindrome.";}
		else{cout<<"Not Palindrome.";}
		cout<<endl; 
	}
	return 0;
}
