#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[6][5]={
    0,0,1,0,0,
    0,1,0,0,0,
    0,1,0,1,1,
    0,1,0,0,0,
    0,0,0,1,0,
    0,0,0,0,0
			 };
int dir[4][2]={0,1,0,-1,1,0,-1,0}; //dir控制方向 

struct State{		//用state保存该点以及当前步数 
    int x,y=0;
    int stepCount=0;
};

int bfs(State st,State _end)	// bfs核心部分 
{
    queue <State> q;	//建立队列 
    State now,next;		
    q.push(st);			//将起点入队 
    a[st.x][st.y]=1;	//入队后重置该点为走过的点（此句为起点单独列出） 
    while(!q.empty())
    {
        now=q.front();	
        q.pop();
        if(now.x==_end.x && now.y==_end.y)	//到达终点，返回步数 
            return now.stepCount;
        for(int i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x<0 || next.y<0 || next.x>=6 || next.y>=5 || a[next.x][next.y]==1)
                continue;
            a[next.x][next.y]=1;
            next.stepCount=now.stepCount+1;
            q.push(next);
         /*   for(int j=0;j<6;j++)
            {
                for(int k=0;k<5;k++)
                    cout<<a[j][k]<<' ';
                cout<<endl;
            }
            cout<<endl;	*/
        }  
    }
}

int main()
{
    State beg,e;
    beg.x=0,beg.y=0,beg.stepCount=0;
    e.x=0,e.y=4;

    cout<<bfs(beg,e);
    return 0;
}

