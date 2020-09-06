#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,n;
	cin>>n;
	for(a=2;a<=n;a++)
		for(b=2;b<=a;b++)
			for(c=b;c<=a;c++)
				for(d=c;d<=a;d++)
					if((a*a*a)==(b*b*b+c*c*c+d*d*d)) 
						cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl; 
	return 0;
} 
