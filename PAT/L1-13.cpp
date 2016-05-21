/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 08时49分32秒
 *   @Last Modified: 2016年05月21日 星期六 08时53分08秒
 *   @File Name: L1-13.cpp
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


int f(int n){
	if(n == 1)
		return 1;
	return n*f(n-1);
}
int main()
{
	int n;
	while(cin >> n)
	{
		int sum = 0;
		for(int i=1;i<=n;i++)
		{
			sum += f(i);
		}
		cout << sum << endl;
	}
}
