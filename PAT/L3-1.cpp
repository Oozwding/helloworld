/**
 *   @Author: zwding
 *   @Created Time : 2016年05月26日 星期四 22时53分46秒
 *   @Last Modified: 2016年05月26日 星期四 23时33分16秒
 *   @File Name: L3-1.cpp
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
#define MAXN 10005
using namespace std;

vector<int> v;
vector<int> ans;
bool visit[MAXN];
bool exitl;
void DFS(int sum,int s)
{
	if(exitl)
		return;
	if(sum == 0)
	{
		if(!ans.empty())
			for(auto it = ans.begin();it != ans.end(); it++)
				it == ans.end()-1 ? cout << *it << endl : cout << *it << " ";
		exitl = true;
		return;
	}
	if(sum < 0)
		return;
	if(sum - s > 0)
		return;
	for(int i=0;i<v.size();i++)
		if(!visit[i])
		{
			if(sum - v[i] < 0)
				return;
			visit[i] = true;
			ans.push_back(v[i]);
			s -= v[i];
			DFS(sum - v[i],s);
			s += v[i];
			visit[i] = false;
			ans.erase(ans.end()-1);
		}
}
int main()
{
	int n,t,m,s=0;
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
		{
			cin >> t;
			v.push_back(t);
			s += t;
		}
		sort(v.begin(),v.end());
		memset(visit,0,sizeof(visit));
		exitl = false;
		DFS(m,s);
		if(!exitl)
			cout << "No Solution" << endl;
		ans.clear();
		v.clear();
	}
}
