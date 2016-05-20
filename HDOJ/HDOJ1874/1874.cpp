/**
 *  Filename:HDOJ1874
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:有向图最短路径算法-Dijkstra算法的应用 城镇最短路径
 */
#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;
//源点到各个顶点的最小值
int dist[205];
//用于存储路径图
int len[205][205];
//dijkstra算法
void Dijkstra(int n,int first,int end){
    //isclu数组用于表示该点是否已被加入V
    bool isclu[205];
    //初始化isclu数组和prev数组
    for(int i=0;i<n;i++){
        dist[i] = len[first][i];
        isclu[i] = false;
    }
    //源点首先被包含进来
    isclu[first] = true;
    //源点到源点的距离为0
    dist[first] = 0;
    //循环n-1次 除了源点
    for(int i=2;i<=n;i++){
        //最小值初始化为最大值
        int temp = INT_MAX;
        //当前将要被包含进来的顶点序号
        int u;
        //通过dist[u]当中介的新的距离
        int newpath;
        //寻找当前dist最小的路径且没有被包含进来
        for(int i=0;i<n;i++)
            if(!isclu[i] && dist[i] < temp){
                u = i;
                temp = dist[i];
            }
        //dist[u]最小，包含进来，设为true
        isclu[u] = true;
        if(u == end)
            return;
        //更新最新距离
        for(int i=0;i<n;i++){
            if(len[u][i] < INT_MAX){
                //最新距离
                newpath = dist[u] + len[u][i];
                //如果小的话就更新
                if(newpath < dist[i]){
                    dist[i] = newpath;
                    //prev[i] = u;
                }
            }
        }
    }
}
int main()
{
    //用于测试数据 OJ时注释
    //freopen("input.txt", "r", stdin);
    int n,v;
    int p,q;
    int lenth;
    //n为顶点的个数 v为边的个数
    while(scanf("%d %d",&n,&v) != EOF){
        //初始化距离为INT_MAX
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                len[i][j] = INT_MAX;
        //读入p顶点到q顶点的距离
        for(int i=0; i<v;i++){
            cin >> p >> q >> lenth;
            if(lenth < len[p][q]){
                len[p][q] = lenth;
                //有向图注释下条语句
                len[q][p] = lenth; //无向图
            }
        }
        int first,end;
        cin >> first >> end;
        //用于测试输入的正确与否
        /*for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                printf("%11d",len[j][k]);
            }
            cout << endl;
        }*/
        //Dijkstra算法
        Dijkstra(n,first,end);
        if(dist[end] != INT_MAX)
            cout << dist[end] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
