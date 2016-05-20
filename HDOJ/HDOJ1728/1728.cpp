/**
 *  Filename:HDOJ1728
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:BFS应用
 */
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct node
{
    int x,y;
}now,tmp;

queue<struct node>q;

int m,n;
//地图
char maze[111][111];
//转弯次数 && 已访问
int vis[111][111];
int k,bx,by,ex,ey;
//方向
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool bfs()
{
    //初始化
    while(!q.empty())
        q.pop();
    //当前坐标
    now.x=bx;
    now.y=by;
    //进栈
    q.push(now);
    //BFS遍历
    while(!q.empty())
    {
        //弹出当前第一个节点
        now=q.front();
        //四个方向遍历
        for(int i=0;i<4;i++)
        {
            //移动方向
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            //不越界而且不越过障碍物
            while(tmp.x>0 && tmp.y>0 && tmp.x<=m && tmp.y<=n && maze[tmp.x][tmp.y]!='*')
            {
                //没有遍历的话，入栈而且转弯次数在now的基础上+1
                if(vis[tmp.x][tmp.y]==-1)
                {
                    q.push(tmp);
                    vis[tmp.x][tmp.y]=vis[now.x][now.y]+1;
                    //如果是当前节点 退出
                    if(tmp.x==ex&&tmp.y==ey)
                        return true;
                }
                //继续搜下去 有点DFS的感觉
                tmp.x+=dx[i];tmp.y+=dy[i];
            }
        }
        //出队列
        q.pop();
    }
    return false;
}

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            memset(vis,-1,sizeof(vis));
            scanf("%d %d",&m,&n);
            int i;
            for(i=1;i<=m;i++)
            //以字符串形式读进来
                scanf("%s",maze[i]+1);
            scanf("%d %d %d %d %d",&k,&by,&bx,&ey,&ex);
            if(bx==ex&&by==ey)
            {
                printf("yes\n");
                continue;
            }
            if(bfs())
            {
                if(vis[ex][ey]<=k)
                    printf("yes\n");
                else
                    printf("no\n");
            }
            else
                printf("no\n");
        }
    }
    return 0;
}
