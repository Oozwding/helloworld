/**
 *   @Author: zwding
 *   @Created Time : 2016年05月19日 星期四 20时30分49秒
 *   @Last Modified: 2016年05月19日 星期四 20时52分33秒
 *   @File Name: L1-3.cpp
 *   @Description:
**/
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	string str;
	while(cin >> str){
		map<char,int> m;
		for(int i=0;i<str.size();i++){
			m[str[i]]++;
		}
		for(map<char,int>::iterator it = m.begin();it != m.end();it++){
			cout << it->first << ":" << it->second << endl;
		}
	}
	return 0;
}
