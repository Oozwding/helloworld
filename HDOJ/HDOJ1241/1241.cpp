/**
 *  Filename:HDOJ1241
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:BFS应用
 */
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct n{
    int x;
    int y;
}node;
const int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char grid[101][101];
int count;
int m,n;

bool BFS(int x,int y)
{
    if(grid[x][y] == '*')
        return false;
    queue<node> q;
    grid[x][y] = '*';
    node now;
    now.x = x;
    now.y = y;
    q.push(now);
    while(!q.empty()){ 
        now = q.front();
        node tmp;
        for(int i=0;i<8;i++){
            tmp.x = now.x + dir[i][0];
            tmp.y = now.y + dir[i][1];
            if(tmp.x>=0 && tmp.y>=0 && tmp.x<m && tmp.y<n && grid[tmp.x][tmp.y] != '*'){
                grid[tmp.x][tmp.y] = '*';
                q.push(tmp);
            }
        }
        q.pop();
    }
    return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    while(cin >> m >> n && m){
        for(int i=0;i<m;i++)
            scanf("%s",grid[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(BFS(i,j))
                    count++;
            }
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}
