/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 08时54分51秒
 *   @Last Modified: 2016年05月21日 星期六 09时09分48秒
 *   @File Name: test.cpp
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
using namespace std;
int round(float x)
{
	int x1 = x;
	int x2 = x*10;
	x2 %= 10;
	if(x2 >= 5)
		return x1 + 1;
	else
		return x1;
}
int main()
{
	int n;
	char c;
	while(cin >> n >> c)
	{
		int col = round(n / 2.0);
		for(int i=0;i<col;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << c;
			}
			cout << endl;
		}
	}
}
