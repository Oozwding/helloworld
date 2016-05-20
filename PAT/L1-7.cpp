/**
 *   @Author: zwding
 *   @Created Time : 2016年05月20日 星期五 16时18分51秒
 *   @Last Modified: 2016年05月20日 星期五 16时25分35秒
 *   @File Name: L1-7.cpp
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
using namespace std;
map<char,string> m;
void init(){
	m['-'] = "fu";
	m['0'] = "ling";
	m['1'] = "yi";
	m['2'] = "er";
	m['3'] = "san";
	m['4'] = "si";
	m['5'] = "wu";
	m['6'] = "liu";
	m['7'] = "qi";
	m['8'] = "ba";
	m['9'] = "jiu";
}
int main(){
	init();
	string str;
	while(cin >> str){
		for(int i=0;i<str.size();i++){
			i == str.size()-1 ? cout << m[str[i]] << endl: cout << m[str[i]] << " ";
		}
	}
	return 0;
}
