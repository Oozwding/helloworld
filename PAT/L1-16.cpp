/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 15时06分47秒
 *   @Last Modified: 2016年05月21日 星期六 15时41分20秒
 *   @File Name: L1-16.cpp
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
#include<numeric>
using namespace std;

const int a[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char b[] = {'1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2'};
int main()
{
	int n;
	while(cin >> n)
	{
		string s;
		int m = 0;
		for(int i=0;i<n;i++)
		{
			cin >> s;
			// cout << "s" << s << endl;
			auto it = find_if(s.begin(),s.end(),
							[] (char c)
							{
								return c > '9';
							});
			if(it == s.end() || it == s.end()-1)
			{
				// cout << s << endl;
				int num = 0;
				int i = 0;
				for_each(s.begin(),s.end()-1,
						[&num,&i](char x)
						{
							num += (x - '0')*a[i++];
						});
				int modl = num % 11;
				if(b[modl] == s.back())
				{
					m++;
				}
				else
				{
					copy(s.begin(),s.end(),ostream_iterator<char>(cout));
					cout << endl;
				}
			}
			else
			{
				copy(s.begin(),s.end(),ostream_iterator<char>(cout));
				cout << endl;
			}
		}
		if(m == n)
			cout << "All passed" << endl;
	}
	return 0;
}
