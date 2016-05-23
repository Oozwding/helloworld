/**
 *   @Author: zwding
 *   @Created Time : 2016年05月23日 星期一 19时11分40秒
 *   @Last Modified: 2016年05月23日 星期一 19时34分45秒
 *   @File Name: L2-6.cpp
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
using namespace std;
const int maxn = 30;

int a[maxn + 10], b[maxn + 10];
map<int,int> L, R;

int build(int la, int ra, int lb, int rb)
{
	if (la > ra)
		return 0;
	int root = a[ra];
	int i;
	for (i = lb; i <= rb && b[i] != root; i++) {}
	if (i <= rb)
	{
		R[root] = build(ra - rb + i, ra - 1, i + 1, rb);
		L[root] = build(la, ra - rb + i - 1, lb, i - 1);
	}
	return root;
}

void bfs(int root)
{
	queue<int> Q;
	Q.push(root);

	int cnt = 0;
	while (!Q.empty())
	{
		int tn = Q.front(); Q.pop();
		printf(cnt++ == 0 ? "%d" : " %d", tn);
		if (L[tn])
		{
			Q.push(L[tn]);
		}
		if (R[tn])
		{
			Q.push(R[tn]);
		}
	}
	cout << endl;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &b[i]);
	int root = build(1, N, 1, N);
	bfs(root);
	return 0;
}
