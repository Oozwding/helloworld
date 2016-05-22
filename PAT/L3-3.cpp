/**
 *   @Author: zwding
 *   @Created Time : 2016年05月22日 星期日 20时30分42秒
 *   @Last Modified: 2016年05月22日 星期日 22时27分56秒
 *   @File Name: L3-3.cpp
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
using namespace std;
vector<int> a[1010];
int main(){
	int N;
	scanf("%d",&N);
	int mmax = 0;
	for(int i=1;i<=N;i++)
	{
		int n;
		scanf("%d:",&n);
		for(int j=0;j<n;j++)
		{
			int num;
			scanf("%d",&num);
			if(mmax<num)
				mmax = num;
			a[num].push_back(i);
		}
	}
	int x[1010],y[1010];        //x:person   y:problem
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(int i=1;i<=N;i++)
	{
		if(!x[i])
		{
			x[i] = i;
			queue<int>q;
			q.push(i);
			while(!q.empty())
			{
				int p = q.front();
				q.pop();
				for(int j=0;j<=mmax;j++)
				{
					if(a[j].size() != 0 && !y[j] && find(a[j].begin(),a[j].end(),p) != a[j].end())
					{
						y[j] = 1;
						for(int k=0;k<a[j].size();k++)
						{
							if(!x[a[j][k]])
							{
								x[a[j][k]] = i;
								q.push(a[j][k]);
							}
						}
					}
				}
			}
		}
	}
	int c[1100];
	memset(c,0,sizeof(c));
	for(int i=1;i<=N;i++)
	{
		c[x[i]]++;
	}
	sort(c,c+N+10,greater<int>());
	int time = 0;
	for(int i=0;c[i];i++)
	{
		time++;
	}
	printf("%d\n",time);
	if(time)
	{
		printf("%d",c[0]);
		for(int i=1;c[i];i++)
		{
			printf(" %d",c[i]);
		}
		printf("\n");
	}
	return 0;
}
