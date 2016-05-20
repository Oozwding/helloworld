/**
 *  @Filename:HDOJ1312BFS
 *  @Date    :2016/3/15
 *  @Author  :zwding
 *  Describe :广度优先搜索应用
 */
#include <iostream>
#include <queue>
using namespace std;
struct point{
       int x,y;
       };
char grid[20][20];
bool sgrid[20][20];//是否访问过
int direction[4][2]={ {-1,0},{1,0},{0,1},{0,-1} };//左 又 上 下
int bx,by;
int X,Y;
int bfs(int x,int y)
{
    queue<point> haha;
    point p1,p2,p3;
    int ax,ay,bx,by;
    int count=0;

    p1.x=x;
    p1.y=y;

    haha.push(p1);
    sgrid[x][y]=0;
    ++count;

    while(!haha.empty())
    {
        p2=haha.front();
        ax=p2.x;
        ay=p2.y;

        for(int i=0;i<4;i++)
        {
            bx=ax+direction[i][0];
            by=ay+direction[i][1];

            if(bx<X&&bx>=0&&by<Y&&by>=0&&sgrid[bx][by]&&grid[bx][by]!='#')
            {
                p3.x=bx;p3.y=by;
                ++count;
                sgrid[bx][by]=0;
                haha.push(p3);
            }
        }
        haha.pop();
    }
    return count;
}
int main()
{
    int i,j;
    while(cin >> Y >> X && Y)
    {
        for(i=0;i<X;i++)
            for(j=0;j<Y;j++)
            {
                cin >> grid[i][j];
                if(grid[i][j]=='@')
                {
                    bx=i;
                    by=j;
                }
                sgrid[i][j]=1;
            }

        cout<<bfs(bx,by)<<endl;
    }
    return 0;
}


