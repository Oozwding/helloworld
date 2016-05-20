/**
 *  Filename:HDOJ1272 小希的迷宫
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:并查集 简单
 *           不用并查集检查连通直接AC 46MS，所以只要判定 点 = 边 + 1 就行了
 *           感觉这道题的初衷应该就是要判断是不是有回路
 */
/** 16815459	2016-04-09 09:56:24	Accepted	1272	78MS	8612K	1508B	G++	zwding */ ///并查集
/** 16815503	2016-04-09 10:00:43	Accepted	1272	46MS	1976K	1566B	G++	zwding */ ///不检查连通
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 101000
using namespace std;

int number[N];
int xset[N];
int Find(int x){
    if(x != xset[x])
        xset[x] = Find(xset[x]);
    return xset[x];
}
void Merge(int x,int y){
    int a = Find(x),b = Find(y);
    xset[a] = b;
}
int main(){
    int x,y,xsets,lines,points,n;
    while(scanf("%d%d",&x,&y),~x || ~y){
        //初始化
        n=0;
        //边数
        lines=0;
        xsets=0;
        //点数
        points=0;
        for(int i=0;i<N;i++){
            number[i]=0;
            //xset[i]=i;
        }
        //构造
        while(x || y){
            n = max(x,n);
            n = max(y,n);
            number[x] = 1;
            number[y] = 1;
            lines++;
            //Merge(x,y);
            scanf("%d%d",&x,&y);
        }
        //统计
        for(int i=1;i<=n;i++)
        {
            if(number[i] == 1)
            {
                points++;
                /*if(xset[i] == i)
                    xsets++;*/
            }
        }
        //分析[注意n为0的情况]
        //if((xsets == 1 && points == lines+1)||(points == 0))
        if(points == lines + 1 || points == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
