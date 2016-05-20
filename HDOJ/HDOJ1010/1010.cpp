/**
 *  Filename:HDOJ1010
 *  Date    :2016/3/29
 *  @Author :zwding
 *  Describe:DFS 剪枝优化 
 */
#include <iostream>
#include <cstdlib>

using namespace std;
int n,m,t;
char graph[8][8];
int visited[8][8];
int stepx[] = {-1, 0, 1, 0};
int stepy[] = {0, 1, 0, -1};
int s[2];
int d[2];
int depth;
int escape;
void DFS(int x, int y, int time)
{
    if(x<=0 || x>n || y<=0 || y>m)//防止越界
    {
        return;
    }
    visited[x][y]=1;
    depth++;
    if(graph[x][y]=='D' && depth == time)
    {
        escape = true;
        return;
    }
    //奇偶剪枝：如果起点横纵坐标和与终点坐标和奇偶性不同，则说明要走奇数步，如果要求走t步，
    //t为偶数，则肯定不可能有答案；反之亦然。
    int temp=t-abs(s[0]-d[0])-abs(s[1]-d[1]);
    if(temp<0 || temp&1)
        return;
    for(int i=0 ; i<4 ; ++i)
    {
        if(visited[x+stepx[i]][y+stepy[i]] == 0 && !escape)
        {
            DFS(x+stepx[i], y+stepy[i],time);
        }
        else if(escape)
        {
            return;
        }
    }
   depth--;
   visited[x][y] = 0;
}
int main()
{
    while((cin >> n >> m >> t) && (n || m || t))
    {
        escape = false;
        depth = -1;
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
                visited[i][j] = 1;

        }
        for(int i=1 ; i<=n ; ++i)
        {
            for(int j=1 ; j<=m ; ++j)
            {
                cin >> graph[i][j];
                if(graph[i][j] == 'S')
                {
                    s[0] = i;
                    s[1] = j;
                }
                if(graph[i][j] == 'D')
                {
                    d[0] = i;
                    d[1] = j;
                }
                if(graph[i][j] != 'X')
                {
                    visited[i][j] = 0;
                }
            }
        }
        DFS(s[0],s[1],t);
        if(escape)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
