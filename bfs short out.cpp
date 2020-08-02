#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[6][6]={
    1,1,1,1,1,1,
    1,0,0,1,0,1,
    1,0,1,0,0,1,
    1,0,1,0,1,1,
    1,0,0,0,0,1,
    1,1,1,1,1,1
};

int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct State{
    int x,y=0;
    int px,py=0;
    int stepCount=0;
};

queue <State> q;
State dp[6][6];

int bfs(State st,State _end)
{

    State now,next;
    dp[1][1].x=st.x;
    dp[1][1].y=st.y;
    q.push(dp[1][1]);
    a[st.x][st.y]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==_end.x && now.y==_end.y)
            return now.stepCount;
        for(int i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x<0 || next.y<0 || next.x>=6 || next.y>=6 || a[next.x][next.y]==1)
                continue;
            dp[next.x][next.y].x=next.x;
            dp[next.x][next.y].y=next.y;
            dp[next.x][next.y].px=now.x;
            dp[next.x][next.y].py=now.y;
            a[next.x][next.y]=1;
            dp[next.x][next.y].stepCount=dp[now.x][now.y].stepCount+1;
            q.push(dp[next.x][next.y]);
 /*           for(int j=0;j<6;j++)
            {
                for(int k=0;k<6;k++)
                    cout<<a[j][k]<<' ';
                cout<<endl;
            }
            cout<<endl;     迷宫图01输出*/
        }
    }
}

void outPath(int x,int y)
{
    if(x==0 && y==0)
    {
        cout<<'('<<dp[1][1].x<<','<<dp[1][1].y<<')'<<endl;
        return ;
    }
    int nx=dp[x][y].px;
    int ny=dp[x][y].py;
    outPath(nx,ny);
    cout<<'('<<dp[x][y].x<<','<<dp[x][y].y<<')'<<endl;
}

int main()
{
    State beg,e;
    beg.x=1,beg.y=1,beg.stepCount=0;
    e.x=1,e.y=4;

    cout<<"最短路径为：";
    cout<<bfs(beg,e)<<endl;
    cout<<"Path:"<<endl;
    outPath(e.x,e.y);
    return 0;
}

