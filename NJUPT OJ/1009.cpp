#include <iostream>
using namespace std;

int a[305]={0};
int main()
{
	int N,temp;
	cin>>N;	
	a[0]=1;
	for(int k=0;k<N;k++){
		temp=0;
		for(int i=0;i<k/2+1&&i<305;i++){
			a[i]*=2;
			a[i]+=temp;
			temp=a[i]/10;
			a[i]%=10;
		}
	}
	int i=304;
	while(a[i]==0){
		i--;
	}
	for(int j=i;j>=0;j--)
		cout<<a[j];
	cout<<endl;
	return 0;
} 
