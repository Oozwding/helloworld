/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 08时46分12秒
 *   @Last Modified: 2016年05月21日 星期六 08时48分25秒
 *   @File Name: L1-12.cpp
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
int main()
{
	int n;
	while(cin >> n)
	{
		cout << "2^" << n << " = " << pow(2,n) << endl;
	}
}
