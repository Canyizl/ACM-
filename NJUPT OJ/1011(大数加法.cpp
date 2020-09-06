#include <iostream>
#include <string>
using namespace std;

int ctoN(char s)
{
	return s-'0';
}

char ntoC(int n)
{
	return char(n+'0');
}

string sum(string a,string b)
{
	int len_a=a.length();
	int len_b=b.length();
	char *c=new char [len_a+1];
	int k=0,i=len_a-1,j=len_b-1;
	int temp=0,jw=0;
	while(i>=0&&j>=0){
		temp=ctoN(a[i])+ctoN(b[j])+jw;
		jw=temp/10;
		temp=temp%10;
		c[k]=ntoC(temp);
		i--;j--;k++;
	}
	while(i>=0){
		temp=jw+ctoN(a[i]);
		jw=temp/10;
		temp=temp%10;
		c[k]=ntoC(temp);
		i--;k++;
	}
	if(jw>0) c[k++]=ntoC(jw);
	c[k]='#';
	return c;
}

int main()
{
	string a,b;
	cin>>a>>b;
	if(b.length()>a.length()) swap(a,b);  //a为较大数  注意不能直接拿string的a b 比较!! 
	else if(b.length()==a.length() && b[0]>a[0]) swap(a,b);
	string c=sum(a,b);
	int i=c.length()-1;
	while(c[i]<'0' || c[i]>'9') i--;
	for(;i>=0;i--)
		cout<<c[i]; 
	return 0;
}
