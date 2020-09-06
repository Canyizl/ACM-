#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin); 
//	freopen("out.txt","w",stdout);
	int n;
	while(cin>>n){
		string p[n];
		for(int i=0;i<n;i++)
			cin>>p[i];
		string del;
		cin>>del;
		
		for(int i=n-1;i>=0;i--)
			cout<<p[i]<<' ';
		cout<<endl;
		bool flag=false;
		for(int i=n-1;i>=0;i--)
			if(p[i]!=del){
				cout<<p[i]<<' ';
				flag=true;
			}
		cout<<endl;
	}
	return 0;
} 
