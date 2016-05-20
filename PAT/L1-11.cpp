/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 00时36分37秒
 *   @Last Modified: 2016年05月21日 星期六 00时43分38秒
 *   @File Name: L1-11.cpp
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
int main()
{
	string str1;
	string str2;
	map<char,int> m;
	while(getline(cin,str1),getline(cin,str2))
	{
		for(int i=0;i<str2.size();i++)
		{
			m[str2[i]] = 1;
		}
		for(int i=0;i<str1.size();i++)
		{
			if(!m[str1[i]])
				cout << str1[i];
		}
		cout << endl;
		m.clear();
	}
	return 0;
}
