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
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct State{
    int x,y=0;
    int stepCount=0;
};

int bfs(State st,State _end)
{
    queue <State> q;
    State now,next;
    q.push(st);
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
            if(next.x<0 || next.y<0 || next.x>=6 || next.y>=5 || a[next.x][next.y]==1)
                continue;
            a[next.x][next.y]=1;
            next.stepCount=now.stepCount+1;
            q.push(next);
            for(int j=0;j<6;j++)
            {
                for(int k=0;k<5;k++)
                    cout<<a[j][k]<<' ';
                cout<<endl;
            }
            cout<<endl;
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

