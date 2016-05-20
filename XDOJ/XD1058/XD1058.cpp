#include <iostream>
#include <cstdio>
#define MAXN 100001
using namespace std;
int a[MAXN][MAXN];
bool visit[MAXN];
void BFS(int n){

}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        int u,v,w;
        for(int i = 1;i<=m;i++){
            cin >> u >> v >> w;
            a[u][v] = a[v][u] = w;
        }
        BFS(n);
    }
    return 0;
}
