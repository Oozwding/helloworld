/**
 *   @Author: zwding
 *   @Created Time : 2016年05月21日 星期六 00时29分20秒
 *   @Last Modified: 2016年05月21日 星期六 00时36分33秒
 *   @File Name: L1-10.cpp
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
#include<iterator>
using namespace std;
int main()
{
	int n,m,k;
	while(cin >> n >> m >>k){
		vector<int> v;
		v.push_back(n);
		v.push_back(m);
		v.push_back(k);
		sort(v.begin(),v.end());
		copy(v.begin(),v.end()-1,
				ostream_iterator<int>(cout,"->"));
		cout << v.back() << endl;
	}
}
