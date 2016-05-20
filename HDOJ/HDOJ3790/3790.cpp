/**
 *  Filename:HDOJ3790
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:有向图最短路径算法-Dijkstra算法的应用 最短路径
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000 + 10;
const int MAX = 0xfffffff;
int map[N][N], cost[N][N];
int min_dis, min_cost;

void Dijkstra(int s, int t, int n)
{
    int dis[N], cost1[N];
    bool visit[N];
    memset(visit, false, sizeof(visit));
    for(int i = 1; i <= N; ++i)
    {
        dis[i] = map[s][i];
        cost1[i] = cost[s][i];
    }
    dis[s] = 0;
    visit[s] = true;
    for(int i = 1; i < n; ++i)
    {
        int min = MAX;
        int k;
        for(int j = 1; j <= n; ++j)
        {
            if(!visit[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        visit[k] = true;
        for(int j = 1; j <= n; ++j)
        {
            if(!visit[j] && dis[j] > min + map[k][j])
            {
                dis[j] = min + map[k][j];
                cost1[j] = cost[k][j] + cost1[k];
            }
            else if(!visit[j] && dis[j] == min + map[k][j] && cost1[j] > cost[k][j] + cost1[k])
            {
                cost1[j] = cost[k][j] + cost1[k];
            }
        }
        if(visit[t])
        {
            min_dis = dis[t];
            min_cost = cost1[t];
            return ;
        }
    }
    min_dis = dis[t];
    min_cost = cost1[t];
}

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && (m || n))
    {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <i; ++j)
            {
                map[i][j] = map[j][i] = MAX;
                cost[i][j] = cost[j][i] = MAX;
            }
        while(m--)
        {
            int a, b, d, p;
            scanf("%d%d%d%d", &a, &b, &d, &p);
            if(map[a][b] > d)
            {
                map[a][b] = map[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }
        }
        int s, t;
        scanf("%d%d", &s, &t);
        Dijkstra(s, t, n);
        printf("%d %d\n", min_dis, min_cost);
    }
    return 0;
}
/*#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXNUM = 100000000;
int len[1005][1005];
int cost[1005][1005];
int min_dis,min_cost;
void Dijkstra(int n,int first,int end){
    int dist[1005];
    int money[1005];
    bool isclu[1005];
    memset(isclu, false, sizeof(isclu));
    for(int i=1;i<=n;i++){
        dist[i] = len[first][i];
        money[i] = cost[first][i];
    }
    dist[first] = 0;
    isclu[first] = true;
    for(int i=1;i<n;i++){
        int temp = MAXNUM;
        int u;
        for(int i=1;i<=n;i++){
            if(!isclu[i] && dist[i] < temp ){
                temp = dist[i];
                u = i;
            }
        }
        isclu[u] = true;
        //更新数据
        for(int i=1;i<=n;i++){
            if(!isclu[i] && (len[u][i] + temp) < dist[i]){
                dist[i] = len[u][i] + temp;
                money[i] = money[u] + cost[u][i];
            }else if(!isclu[i] && dist[i]==(len[u][i]+temp) && money[i]>(money[u]+cost[u][i])){
                money[i] = money[u] + cost[u][i];
            }
        }
        if(isclu[end])
        {
            min_dis = dist[end];
            min_cost = money[end];
            return ;
        }
    }
    min_dis = dist[end];
    min_cost = money[end];
}
int main()
{
    int n,v;
    //用于测试数据 OJ时注释
    freopen("input.txt", "r", stdin);
    while(scanf("%d %d",&n,&v) && (n || v)){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++){
                len[i][j] = len[j][i] = MAXNUM;
                cost[i][j] = cost[j][i] = MAXNUM;
            }
        int a,b,l,m;
        for(int i=1;i<=v;i++){
            cin >> a >> b >> l >> m;
            if(l < len[a][b]){
                len[a][b]= len[b][a] = l;
                cost[a][b] = cost[b][a] = m;
            }

        }
        int first,end;
        scanf("%d%d",&first,&end);
        Dijkstra(n,first,end);
        printf("%d %d\n",min_dis,min_cost);
    }
    return 0;
}*/
