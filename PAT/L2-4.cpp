/**
 *   @Author: zwding
 *   @Created Time : 2016年05月22日 星期日 19时19分39秒
 *   @Last Modified: 2016年05月22日 星期日 20时11分08秒
 *   @File Name: L2-4.cpp
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
vector<int> vv;
bool IsPreorderTraversal(vector<int>& v,int b,int e)
{
	if(e == b)
	{
		vv.push_back(v[e]);
		return true;
	}
	int root = v[b];
	int i = b+1;
	while(i <= e)
	{
		if(v[i] > root)
			break;
		i++;
	}
	int j = i;
	while(j <= e)
	{
		if(v[j] < root)
			return false;
		j++;
	}
	bool left = true;
	if(i > b+1)
	{
		left = IsPreorderTraversal(v,b+1,i-1);
	}
	int right = true;
	if(i <= e)
	{
		right = IsPreorderTraversal(v,i,e);
	}
	vv.push_back(root);
	return left && right;
}
bool IsPreorderTraversal1(vector<int>& v,int b,int e)
{
	if(e == b)
	{
		vv.push_back(v[e]);
		return true;
	}
	int root = v[b];
	int i = b+1;
	while(i <= e)
	{
		if(v[i] < root)
			break;
		i++;
	}
	int j = i;
	while(j <= e)
	{
		if(v[j] > root)
			return false;
		j++;
	}
	bool left = true;
	if(i > b+1)
	{
		left = IsPreorderTraversal1(v,b+1,i-1);
	}
	int right = true;
	if(i <= e)
	{
		right = IsPreorderTraversal1(v,i,e);
	}
	vv.push_back(root);
	return left && right;
}
int main()
{
	vector<int> v;
	int n;
	while(cin >> n)
	{
		int t;
		int m = n;
		while(m--)
		{
			cin >> t;
			v.push_back(t);
		}
		bool ans = IsPreorderTraversal(v,0,v.size()-1);
		// cout << ans << endl;
		if(ans)
		{
			cout << "YES" << endl;
			int x = 1;
			for_each(vv.begin(),vv.end(),
					[&x,n] (int y)
					{
						x == n ? cout << y << endl : cout << y << " ";
						x++;
					});
		}
		else
		{
			ans = IsPreorderTraversal1(v,0,v.size()-1);
			if(ans)
			{
				cout << "YES" << endl;
				int x = 1;
				for_each(vv.begin(),vv.end(),
						[&x,n] (int y)
						{
							x == n ? cout << y << endl : cout << y << " ";
							x++;
						});
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		v.clear();
		vv.clear();
	}

}
