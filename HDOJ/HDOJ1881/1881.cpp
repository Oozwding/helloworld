/**
 *  Filename:HDOJ1881
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:背包问题 动态规划
 */
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define MAXN 1010
#define MAX(a,b) a>b?a:b
using namespace std;
struct s
{
	int h;
	int l;
	int t;
}a[MAXN];
int dp[MAXN];
bool cmp(s aa,s bb)
{
	return aa.t<bb.t;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
		break;
		for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].t);
		sort(a+1,a+1+n,cmp);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=a[n].t;j>=a[i].l;j--)
			{
				if(j>=a[i].l&&j<=a[i].t)
				dp[j]=MAX(dp[j],dp[j-a[i].l]+a[i].h);
			}
		}
		int M=-1;
		for(i=1;i<=a[n].t;i++)
		M=MAX(M,dp[i]);
		printf("%d\n",M);
	}
	return 0;
}

