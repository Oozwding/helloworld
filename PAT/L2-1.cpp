/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 15时45分11秒
 *   @Last Modified: 2016年05月22日 星期日 18时10分31秒
 *   @File Name: L2-1.cpp
 *   @Description:
**/

#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iterator>
#include<fstream>
#include<cstring>
#define MAXN 505
#define MAXL 1000000
using namespace std;
struct n
{
	int d;
	int p;
	int h;
}dist[MAXN];
int path[MAXN][MAXN];
int per[MAXN];
int previ[MAXN];
bool visit[MAXN];
void dijkstra(int s,int d,int n)
{
	memset(visit,0,sizeof(visit));
	for(int i=0;i<n;i++)
	{
		if(i == s)
		{
			dist[s].d = 0;
			dist[s].p = per[s];
			dist[s].h = 1;
		}
		else
		{
			dist[i].d = path[s][i];
			dist[i].h = 1;
			if(dist[i].d == MAXL)
			{
				previ[i] = -1;
				dist[i].p = 0;
			}
			else
			{
				previ[i] = s;
				dist[i].p = per[i] + per[s];
			}
		}
	}
	dist[s].d = 0;
	visit[s] = 1;
	for(int i=2;i<=n;i++)
	{
		int tmp = MAXL;
		int u;
		for(int i=0;i<n;i++)
		{
			if(!visit[i] && dist[i].d < tmp)
			{
				tmp = dist[i].d;
				u = i;
			}
		}
		visit[u] = 1;
		if(u == d)
			return;
		for(int i=0;i<n;i++)
		{
			if(!visit[i] && tmp+path[u][i] < dist[i].d)
			{
				dist[i].d = tmp + path[u][i];
				dist[i].p = dist[u].p + per[i];
				dist[i].h = dist[u].h;
				previ[i] = u;
			}
			else if(!visit[i] && tmp+path[u][i] == dist[i].d)
			{
				dist[i].h = dist[u].h + dist[i].h;
				if(dist[u].p + per[i] > dist[i].p)
				{
					dist[i].p = dist[u].p + per[i];
					previ[i] = u;
				}
			}
		}
	}
}
void getpath(int s)
{
	if(previ[s] == s)
	{
		cout << s;
		return;
	}
	else
	{
		getpath(previ[s]);
	}
	cout << " " << s;
}
int main()
{
	// ifstream infile("in");
	int n,m,s,d;
	while(cin >> n >> m >> s >> d)
	{
		for(int i=0;i<n;i++)
		{
			cin >> per[i];
		}
		for(int i=0;i<n;i++)
		{
			path[i][i] = 0;
			for(int j=i+1;j<n;j++)
			{
				path[i][j] = path[j][i] = MAXL;
			}
		}
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			if(path[x][y] > z)
				path[x][y] = path[y][x] = z;
		}
		/*
		 * for(int i=0;i<n;i++)
		 * {
		 *     for(int j=0;j<n;j++)
		 *     {
		 *         cout << path[i][j] << " ";
		 *     }
		 *     cout << endl;
		 * }
		 */
		dijkstra(s,d,n);
		/*
		 * for(int i=0;i<n;i++)
		 * {
		 *     cout << i << " : " << dist[i].d << " " << dist[i].p << " " << dist[i].h << endl;;
		 * }
		 */
		// cout << endl;
		cout << dist[d].h << " " << dist[d].p << endl;
		getpath(d);
		cout << endl;
	}
}
