/**
 *   @Author: zwding
 *   @Created Time : 2016年05月19日 星期四 21时05分15秒
 *   @Last Modified: 2016年05月19日 星期四 21时15分29秒
 *   @File Name: L1-5.cpp
 *   @Description:
**/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct n{
	string name;
	int x;
	int y;
};
int z;
bool cmp(struct n xx){
	return xx.x == z;
}
vector<struct n> v;
int main(){
	int nn,mm;
	while(cin >> nn){
		while(nn--){
			struct n t;
			cin >> t.name >> t.x >> t.y;
			v.push_back(t);
		}
		cin >> mm;
		while(mm--){
			cin >> z;
			vector<struct n>::iterator it = find_if(v.begin(),v.end(),cmp);
			cout << it->name << " " << it->y << endl;
		}
		v.clear();
	}
	return 0;
}
