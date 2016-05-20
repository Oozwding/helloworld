 /**
 *  Filename:HDOJ1242
 *  Date    :2016/4/19
 *  @Author :zwding
 *  Describe:优先队列
 */
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
#define M 201
typedef struct p{
    int x,y,t;
    bool operator < (const p &a)const
    {
        return t>a.t;//取时间最少优先
    }
}Point;

char graph[M][M];
Point start;
int n,m;
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};

int bfs()
{
    priority_queue<Point> que;
    Point cur,next;
    int i;

    graph[start.x][start.y]='#';
    que.push(start);
    while(!que.empty()){
        cur=que.top();//由优先队列自动完成出队时间最少的元素
        que.pop();
        for(i=0;i<4;i++){
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            next.t=cur.t+1;
            if(next.x<0||next.x>=n||next.y<0||next.y>=m)
                continue;
            if(graph[next.x][next.y]=='#')
                continue;
            if(graph[next.x][next.y]=='r')
                return next.t;
            if(graph[next.x][next.y]=='.'){
                graph[next.x][next.y]='#';
                que.push(next);
            }
            else if(graph[next.x][next.y]=='x'){
                graph[next.x][next.y]='#';
                next.t++;
                que.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    int i,ans;
    char *p;
    while(scanf("%d%d",&n,&m)!=-1){
        for(i=0;i<n;i++){
            scanf("%s",graph[i]);
            if(p = strchr(graph[i],'a')){
                start.x=i;
                start.y=p-graph[i];
                start.t=0;
            }
        }
        ans=bfs();
        printf(ans+1?"%d\n":"Poor ANGEL has to stay in the prison all his life.\n",ans);
    }
    return 0;
}
