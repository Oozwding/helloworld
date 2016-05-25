/**
 *   @Author: zwding
 *   @Created Time : 2016年05月25日 星期三 20时43分22秒
 *   @Last Modified: 2016年05月25日 星期三 23时18分08秒
 *   @File Name: L2-7.cpp
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
#include<cstring>
#include<iomanip>
#define MAXN 10005
using namespace std;

int Union[MAXN];
bool visit[MAXN];
int Count[MAXN];
struct family
{
	int id;
	int fa,ma;
	double i,s;
}a[1005],b[MAXN],c[MAXN];
struct ans
{
	int minl;
	int sum;
	double i;
	double s;
}res[1005];
void Union_set()
{
	for(int i=0;i<10000;i++)
		Union[i] = i;
}
int Union_find(int x)
{
	if(x == Union[x])
		return x;
	else
		return Union[x] = Union_find(Union[x]);
}
void Union_all(int x,int y)
{
	int i = Union_find(x);
	int j = Union_find(y);
	if(i < j)
		Union[j] = i;
	else
		Union[i] = j;
}
int main()
{
	freopen("in","r",stdin);
	int n;
	while(cin >> n)
	{
		Union_set();
		for(int i=0;i<n;i++)
		{
			int t , b, c, d;
			cin >> t >> b >> c >> d;
			a[i].id = t;
			visit[t] = 1;
			if(b != -1)
			{
				a[i].fa = b;
				visit[b] = 1;
				Union_all(t,b);
			}
			if(c != -1)
			{
				a[i].ma = c;
				visit[c] = 1;
				Union_all(t,c);
			}
			int tt;
			for(int j=0;j<d;j++)
			{
				cin >> tt;
				if(tt != -1)
				{
					visit[tt] = 1;
					Union_all(t,tt);
				}
			}
			cin >> a[i].i >> a[i].s;
		}
		for(int i=0;i<n;i++)
		{
			int id = Union_find(a[i].id);
			b[id].id = id;
			b[id].i += a[i].i;
			b[id].s += a[i].s;
		}
		for(int i=0;i<10000;i++)
			if(visit[i])
				Count[Union_find(i)]++;
		bool e[MAXN];
		memset(e,0,sizeof(e));
		int j = 0;
		for(int i=0;i<10000;i++)
		{
			if(visit[i])
			{
				int id = Union_find(i);
				if(!e[id])
				{
					e[id] = 1;
					res[j].minl = id;
					res[j].sum = Count[id];
					res[j].i = b[id].i / res[j].sum;
					res[j].s = b[id].s / res[j].sum;
					j++;
				}
			}
		}
		sort(res,res+j,
				[](struct ans x,struct ans y) -> bool
				{
					if(x.s == y.s)
						return x.minl < y.minl;
					return x.s > y.s;
				});
		cout << j << endl;
		for_each(res,res+j,
				[](struct ans x)
				{
					cout << setfill('0') << setw(4) <<  x.minl << " " << fixed << setprecision(3) << x.sum << " " << x.i << " " << x.s << endl;
				});
	}
	return 0;
}
