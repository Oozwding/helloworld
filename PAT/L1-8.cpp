/**
 *   @Author: zwding
 *   @Created Time : 2016年05月20日 星期五 18时34分57秒
 *   @Last Modified: 2016年05月20日 星期五 18时43分56秒
 *   @File Name: L1-8.cpp
 *   @Description:
**/

#include<iostream>
#include<iomanip>
#include<vector>
#include<deque>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	while(cin >> n >> m){
		int sum = 0;
		for(int i=n;i<=m;i++){
			(i-n+1) % 5 == 0 ? cout << setw(5) << i << endl: cout << setw(5) << i;
			sum += i;
		}
		if((m-n+1) % 5 != 0)
			cout << endl;
		cout << "Sum = " << sum << endl;
	}
	return 0;
}
