/**
 *   @Author: zwding
 *   @Created Time : 2016年05月20日 星期五 18时45分42秒
 *   @Last Modified: 2016年05月21日 星期六 00时23分43秒
 *   @File Name: L1-9.cpp
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
using namespace std;
struct t
{
	int fenzi;
	int fenmu;
};
vector<struct t> v;
int gcd(int x,int y){
	int r;
	while(x % y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}
int lcm(int a,int b){
	return a*b / gcd(a,b);
}
int main()
{
	int n;
	while(cin >> n)
	{
		int nn,mm;
		struct t temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d/%d",&nn,&mm);
			temp.fenzi = nn;
			temp.fenmu = mm;
			v.push_back(temp);
		}
		int x = v.front().fenmu;
		for(int i=1;i<v.size();i++)
		{
			x = lcm(x,v[i].fenmu);
		}
		// cout << x << endl;
		struct t ans;
		ans.fenzi = 0;
		ans.fenmu = x;
		for(int i=0;i<v.size();i++)
		{
			ans.fenzi += x / v[i].fenmu * v[i].fenzi;
			// cout << x / v[i].fenmu * v[i].fenzi << " ";
		}
		int y = gcd(ans.fenzi,ans.fenmu);
		// cout << "gcd:" << y << endl;
		ans.fenzi /= y;
		ans.fenmu /= y;
		int x1 = ans.fenzi / ans.fenmu;
		int x2 = ans.fenzi % ans.fenmu;
		// cout << ans.fenzi << " " << ans.fenmu << endl;
		if(x1)
		{
			if(x2)
			{
				cout << x1 << " " << x2 << "/" << ans.fenmu << endl;
			}
			else
			{
				cout << x1 << endl;
			}
		}
		else
		{
			if(x2)
			{
				cout << x2 << "/" << ans.fenmu << endl;
			}
			else
			{
				cout << x2 << endl;
			}
		}
		v.clear();
	}
	return 0;
}
