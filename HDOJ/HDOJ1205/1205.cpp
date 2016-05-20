/**
 *  Filename:HDOJ1205
 *  Date    :2016/4/11
 *  @Author :zwding
 *  Describe:排列组合 抽屉原理
 */
 /*** 16841492	2016-04-11 19:50:36	Accepted	1205	421MS	1572K	966 B	G++	zwding */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxN 1000010
#define LL long long
#define ll __int64
#define INF 0x7fffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
double dpow(double a,ll b){double ans=1.0;while(b){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
//head
//求出最多的那个糖果，然后查看剩余糖果能否一个一个插入
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll ans = 0;
		int M = -INF;
		for(i = 0;i < n;i++)
		{
			int a;
			scanf("%d",&a);
			//求出总糖果数
			ans += a;
			//求出最多的糖果数
			M = max(M,a);
		}
		//如果其他的加起来大于M（最多的糖果数）则YES
		if(ans - M + 1 >= M)
            printf("Yes\n");
		else
            printf("No\n");
	}
	return 0;
}
