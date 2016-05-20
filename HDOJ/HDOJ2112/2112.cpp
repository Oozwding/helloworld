#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;
const int INF = 0x7fffffff;
string start,endi;
map<string,int> bus;
int num;
int path[151][151];
int dist[151];
bool visit[151];
void Dijkstra(int begini)
{
    for(int i=1;i<=num;i++){
        dist[i] = path[begini][i];
        visit[i] = false;
    }
    dist[begini] = 0;
    visit[begini] = true;
    for(int i=2;i<=num;i++){
        int temp = INF;
        int u;
        int newpath;
        for(int j=1;j<=num;j++){
            if(!visit[j] && dist[j]<temp){
                temp = dist[j];
                u = j;
            }
        }
        visit[u] = true;
        for(int j=1;j<=num;j++){
            if(!visit[j] && path[u][j] < INF){
                newpath = dist[u] + path[u][j];
                if(newpath < dist[j])
                    dist[j] = newpath;
            }
        }
    }
}
int main()
{
    //freopen("input","r",stdin);
    int n;
    for(int i=1;i<=150;i++)
        for(int j=1;j<=150;j++)
            path[i][j] = INF;
    while(cin >> n && n!=-1){
        cin >> start >> endi;
        for(int i=0;i<n;i++){
            int time;
            string a,b;
            cin >> a >> b >> time;
            if(bus.find(a) == bus.end())
                bus[a] = ++num;
            if(bus.find(b) == bus.end())
                bus[b] = ++num;
            if(path[bus[a]][bus[b]]==0 || time<path[bus[a]][bus[b]])
                path[bus[a]][bus[b]] = path[bus[b]][bus[a]] = time;
        }
        Dijkstra(bus[start]);
        if(dist[bus[endi]] == INF)
            cout << -1 << endl;
        else if(start == endi)
            cout << 0 << endl;
        else
            cout << dist[bus[endi]] << endl;
    }
    return 0;
}
