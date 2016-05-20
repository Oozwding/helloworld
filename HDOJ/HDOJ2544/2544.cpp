/**
 *  Filename:HDOJ2544
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:有向图最短路径算法-Dijkstra算法的应用 最短路径
 */
#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;
int dist[105];
int len[105][105];
void Dijkstra(int n,int first){
    bool isclu[105];
    for(int i=1;i<=n;i++){
        isclu[i] = false;
        dist[i] = len[first][i];
    }
    isclu[first] = true;
    dist[first] = 0;
    for(int i=2;i<=n;i++){
        int temp = INT_MAX;
        int u;
        for(int i=1;i<=n;i++){
            if(!isclu[i] && dist[i]<temp){
                u = i;
                temp = dist[i];
            }
        }
        isclu[u] = true;
        //更新数据
        int newpath;
        for(int i=1;i<=n;i++){
            if(len[u][i] < INT_MAX){
                newpath = dist[u] + len[u][i];
                if(newpath < dist[i])
                    dist[i] = newpath;
            }
        }
    }
}
int main()
{
    //用于测试数据 OJ时注释
    //freopen("input.txt", "r", stdin);
    int n,v;
    while(cin>>n>>v && (n!=0 && v !=0)){
        int p,q,m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                len[i][j] = INT_MAX;
        for(int i=0;i<v;i++){
            cin >> p >> q >> m;
            if(m < len[p][q]){
                len[p][q] = m;
                len[q][p] = m;
            }
        }
        /*for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                printf("%11d",len[j][k]);
            }
            cout << endl;
        }*/
        Dijkstra(n,1);
        cout << dist[n] << endl;
    }
}
