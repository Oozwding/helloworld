/**
 *   @Author: zwding
 *   @Created Time : 2016年05月23日 星期一 14时46分19秒
 *   @Last Modified: 2016年05月23日 星期一 16时32分47秒
 *   @File Name: L2-5.cpp
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
using namespace std;

vector<set<int> > v;
int main()
{
	int n;
	while(cin >> n)
	{
		int t,tt;
		while(n--)
		{
			set<int> q;
			cin >> t;
			for(int i=1;i<=t;i++)
			{
				cin >> tt;
				q.insert(tt);
			}
			v.push_back(q);
		}
		cin >> t;
		int aa,bb;
		/*
		 * cout << endl;
		 * for_each(v.begin(),v.end(),
		 *         [](set<int> s)
		 *         {
		 *             copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
		 *             cout << endl;
		 *         });
		 */
		while(t--)
		{
			cin >> aa >> bb;
			int nc = 0,nt = 0;
			for(auto it=v[aa-1].begin();it != v[aa-1].end();it++)
			{
				if(v[bb-1].find(*it) != v[bb-1].end())
					nc++;
			}
			nt = v[bb-1].size() - nc + v[aa-1].size();
			float ans = (float)nc / nt;
			cout << fixed << setprecision(2) << ans * 100 << "%" << endl;
		}
	}
	return 0;
}
