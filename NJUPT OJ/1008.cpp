#include <iostream>
using namespace std;

int month[13]={0,
	31,28,31,30,31,30,31,31,30,31,30,31
};
int year=365;
bool run(int n)
{
	bool flag=false;
	if(n%4==0) flag=true;
	if(n%100==0&&n%400!=0) flag=false;
	return flag;
}

int main()
{
	int y,m,d;
	while(cin>>y){
		if(y==-1) break;
		cin>>m>>d;
		int sum1=0;
		int sum2=d-1;

		for(int i=2000;i<y;i++){
			if(run(i)) month[2]=29;
			else month[2]=28;	
			for(int j=1;j<=12;j++){
				sum1=sum1+month[j];
			}		
		}
		
		for(int i=1;i<m;i++)
		{
			if(run(y)) month[2]=29;
			else month[2]=28;	
			sum2=sum2+month[i];
		} 
		
		int sum=sum1+sum2;
		cout<<sum<<endl;
		cout<<sum2+1<<endl;
	}
	return 0;
}
