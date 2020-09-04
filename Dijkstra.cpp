#include <iostream>
#include <string.h>
using namespace std;

MAXN=100;
int dis[MAXN]; //与起点的距离 
int vis[MAXN]; //访问标记 
int a[MAX][MAXN] //a[m][n]为m到n之间的距离 

void Dij(int n)	//默认起点为1 
{
	memset(dis,MAXN,sizeof(dis));
	vis[1]=1;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(k==0 || dis[j]<dis[k]))
				k=j
		v[k]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[k]+a[k][j]<dis[j])
				dis[j]=dis[k]+a[k][j];
	}
}

