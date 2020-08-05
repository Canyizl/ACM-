#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAXN=100001;

struct qnode{
	int v,c;				//v代表起点，c代表当前路径长 
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator < (const qnode &r) const
	{
		return c>r.c;
	}
};

struct Edge{           	//邻接矩阵 
	int v,cost;			//v代表指向的点，cost代表路径 
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[MAXN];		//E[i][j]代表从i指向j，E[i][j].cost为两者间路径， E[i][j].v代表指向的点j。 

bool vis[MAXN];			//是否访问标志 
int dist[MAXN];			//存放距离,起点到每个点的最短距离 

void Dijkstra(int n,int start) 			//n为结点个数，start为选取的起点 
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	priority_queue<qnode> que;
	while(!que.empty()) que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty())
	{
		tmp=que.top();
		que.pop();
		int u=tmp.v;				//u为当前队首作为起点 
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<E[u].size();i++)		//E[u].size()等价于节点数 
		{
			int v=E[u][i].v;				//v为指向的下一个节点 
			int cost=E[u][i].cost;			//cost为当前起点u到目标点v的已知长度 
			if(!vis[v]&&dist[v]>cost+dist[u])		//比较起点直接到v点，和先到u点再到v点的路径 
			{
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));			///将目标点塞入队列，进行下一次松弛 
			}
		}
	}
}

void addedge(int u,int v,int w)  			//用于初始化邻接矩阵 
{
	E[u].push_back(Edge(v,w));
}

int main()
{
	/*  2 
	P1--->P3 
 1	↓     ↓4
	P2--->P4 
	   4
	*/ 
	
	int n=4;
	int v,w;
	freopen("in.txt","r",stdin); //输入输出分别在in.txt和out.txt中； 
	freopen("out.txt","w",stdout);
	for(int i=1;i<=n;i++)
	{
		addedge(i,0,-1);		//使得开始点为1，而不是0。 
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			if(w==-1)			//无限用-1输入 
				addedge(i,j,INF); 
			else
				addedge(i,j,w);
		} 
	}
	
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<E[i][j].cost<<' ';
		} 
		cout<<endl;
	}*/
	
	Dijkstra(4,1);
	for(int i=1;i<=4;i++)
		cout<<dist[i]<<' '; 
	return 0;
} 

/*
	in.txt:	0 1 2 -1
			1 0 -1 4
			2 -1 0 4
			-1 4 4 0   
			
	out.txt标准答案： 0 1 2 5 
*/
