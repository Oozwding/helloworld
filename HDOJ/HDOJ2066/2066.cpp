//多源多汇最短路
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int dist[2005],map[2005][2005];
bool visit[2005];
int n;
void init()
{
     int i,j;
     for( i=0; i<=n; i++){
          for( j=0; j<=n; j++)
               if( !map[i][j])
                   map[i][j]=INF;
          dist[i]=INF;
          visit[i]=false;
     }
}
void Dijkstra(int s)
{
    int mim,pt,i;
    dist[s]=0;
    pt=s;
    while( true){
           visit[pt]=true;
           for( i=0; i<=n; i++)
                if( !visit[i]&&map[pt][i]!=INF)
                    dist[i]=min(dist[i],dist[pt]+map[pt][i]);
           mim=INF;
           pt=-1;
           for( i=0; i<=n; i++){
                if( !visit[i]&&mim>dist[i]){
                    mim=dist[i];
                    pt=i;
                }
           }
           if( pt==-1) break;
    }
}
int main()
{
    //freopen("input","r",stdin);
    int s,t,d,i,j,x;
    while( scanf("%d%d%d",&t,&s,&d)!=EOF){
           memset(map,0,sizeof(map));
           while( t--){
                  scanf("%d%d%d",&i,&j,&x);
                  n=max(n,max(i,j));
                  if( map[i][j]==0||x<map[i][j])
                      map[i][j]=map[j][i]=x;
           }
           init();
           while( s--){
                  scanf("%d",&i);
                  map[0][i]=map[i][0]=0;
           }
           Dijkstra(0);
           x=INF;
           while( d--){
                  scanf("%d",&t);
                  if( x>dist[t])
                      x=dist[t];
           }
           printf("%d\n",x);
    }
    return 0;
}

