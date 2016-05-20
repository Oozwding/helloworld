/**
 *  Filename:HDOJ 1276
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:队列应用
 */
 /** 16825616	2016-04-09 20:56:50	Accepted	1276	15MS	1696K	1365 B	G++	zwding */
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<algorithm>
#define MAXN 100100
using namespace std;
struct s
{
	int last;
	int end;
}a[MAXN],d;
queue<s> q;
queue<s> qq;
int main()
{
	int t,n,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i].last=i;
			a[i].end=i;
			q.push(a[i]);
		}
		int c1=0;
		int c2=1;
		int num=2;
		while(n>3)
		{
			sum=0;
			while(!q.empty())
			{
				d=q.front();
				if(d.end%2==0)
				{
					q.pop();
				}
				else
				{
					q.pop();
					d.end=++sum;
					qq.push(d);
				}
			}
			sum=0;
			if(qq.size()<=3)
                break;
			while(!qq.empty())
			{
				d=qq.front();
				if(d.end%3==0)
				{
					qq.pop();
				}
				else
				{
					qq.pop();
					d.end=++sum;
					q.push(d);
				}
			}
			n=q.size();
	    }
	    if(!q.empty())
	    {
	    	while(q.size()!=1)
	    	{
	    		printf("%d ",q.front().last);
	    		q.pop();
			}
			printf("%d\n",q.front().last);
			q.pop();
		}
		else
		{
			while(qq.size()!=1)
	    	{
	    		printf("%d ",qq.front().last);
	    		qq.pop();
			}
			printf("%d\n",qq.front().last);
			qq.pop();
		}
   }
   return 0;
}
