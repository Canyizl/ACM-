#include <iostream>
using namespace std;

void quicksort(int s[],int l,int r)	//快速排序  时间为O(nlogn) 
{
	if(l>=r) return;
	int i = l,j = r;
	int x = s[l];
	while(i < j){
		while(i < j && s[j]>=x)
			j--;
		if(i<j)
			s[i++]=s[j];
		while(i < j && s[i]<x)
			i++;
		if(i<j)
			s[j--]=s[i];
	}
	s[i]=x;
	quicksort(s,l,i-1);
	quicksort(s,i+1,r);
}

int main()
{
	int s[8]={22,5,17,99,3,64,8,10};
	quicksort(s,0,7);
	for(int i=0;i<8;i++)
		cout<<s[i]<<' ';
	cout<<endl;
	return 0;
}
