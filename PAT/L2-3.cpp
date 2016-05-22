/**
 *   @Author: zwding
 *   @Created Time : 2016年05月22日 星期日 17时13分21秒
 *   @Last Modified: 2016年05月22日 星期日 17时49分05秒
 *   @File Name: L2-3.cpp
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
#include<iomanip>
#define MAXN 1005
using namespace std;
struct t
{
	float k;
	float s;
	float m;
}a[MAXN];
int main()
{
	int n;
	float m;
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
			cin >> a[i].k;
		for(int i=0;i<n;i++)
		{
			cin >> a[i].s;
			a[i].m = a[i].s / a[i].k;
			// cout << a[i].m << " ";
		}
		// cout << endl;
		sort(a,a+n,
				[](struct t x,struct t y)
				{
					return x.m > y.m;
				});
		float cou = 0;
		int temp = m;
		for(int i=0;i<n;i++)
		{
			if(temp >= a[i].k)
			{
				cou += a[i].s;
				temp -= a[i].k;
			}
			else
			{
				cou += a[i].m * temp;
				temp = 0;
			}
			if(temp == 0)
				break;
		}
		cout << fixed << setprecision(2) << cou << endl;
	}
}
