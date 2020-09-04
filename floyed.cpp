#include <iostream>
using namespace std;

int D[51][51];

void floyed(int N)
{
	for(int i=1;i<=(N/2+1);i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				if(D[i][k]+D[k][j]<D[i][j])
					D[j][i]=D[i][j]=D[i][k]+D[k][j]; //D[j][i]=D[i][j] 可以减少复杂度 
}

int main()
{	
	int i,j,k,x,y;
	int N=5,M=6;
	int e[9][3]={
	{1,2,30},{1,3,10},
	{2,4,20},{2,5,25},
	{3,4,10},{4,5,10}
	};
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j) D[i][j]=10000;	//初始化
			 
	for(int i=1;i<=M;i++)	//存入初始信息 
	{
		x=e[i-1][0];y=e[i-1][1];
		D[x][y]=D[y][x]=e[i-1][2];	
	}
	floyed(N);
	cout<<D[1][4];
	return 0;
 } 
