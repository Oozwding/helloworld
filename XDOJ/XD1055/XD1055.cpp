/**
 *  Filename:XDOJ1055
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:水题
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
struct node{
    int x;
    int y;
};
int martri[100][100];
bool visit[100][100];
int n,m;
queue<struct node> p;
void BFS(){
    struct node be;
    be.x = be.y = 1;
    memset(visit,0,sizeof(visit));
    visit[1][1] = true;
    cout << martri[1][1] << " ";
    p.push(be);
    int a[2] = {0,0};
    while(!p.empty()){
        struct node cc = p.front();
        if(cc.x == n && cc.y == m){
            p.pop();
            break;
        }
        struct node ne;
        p.pop();
        if((cc.y - 1 == 0 || cc.y + 1 > m) && !a[0] && !a[1]){
            if(cc.x + 1 <= n){
                ne.x = cc.x + 1;ne.y = cc.y + 0;
                visit[ne.x][ne.y] = true;
                cout << martri[ne.x][ne.y] << " ";
                p.push(ne);
                a[0] = 1;
            }else if(ne.y + 1 <= m){
                ne.y = ne.y + 1;ne.x = ne.x + 0;
                visit[ne.x][ne.y] = true;
                cout << martri[ne.x][ne.y] << " ";
                p.push(ne);
                a[1] = 1;
            }
        }else if((cc.x - 1 == 0 || cc.x + 1 > n) && !a[0] && !a[1]){
            if(cc.y + 1 <= m){
                ne.x = cc.x + 0;ne.y = cc.y + 1;
                visit[ne.x][ne.y] = true;
                p.push(ne);
                cout << martri[ne.x][ne.y] << " ";
                a[1] = 1;
            }else if(cc.x + 1 <= n){
                ne.x = cc.x + 1;ne.y = cc.y + 0;
                visit[ne.x][ne.y] = true;
                cout << martri[ne.x][ne.y] << " ";
                p.push(ne);
                a[0] = 1;
            }
        }else{
            if(!visit[cc.x + 1][cc.y - 1] && (cc.x + 1 <= n) && (cc.y - 1 >= 1)){
                ne.x = cc.x + 1;ne.y = cc.y - 1;
                visit[ne.x][ne.y] = true;
                cout << martri[ne.x][ne.y] << " ";
                p.push(ne);
                a[0] = 0;
                a[1] = 0;
            }else if(!visit[cc.x - 1][cc.y + 1] && (cc.x - 1 >= 1) && (cc.y + 1 <= m)){
                ne.x = cc.x - 1;ne.y = cc.y + 1;
                visit[ne.x][ne.y] = true;
                cout << martri[ne.x][ne.y] << " ";
                p.push(ne);
                a[0] = 0;
                a[1] = 0;
            }
        }
    }
}
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d %d",&n,&m) != EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin >> martri[i][j];
        BFS();
        cout << endl;
    }
    return 0;
}
