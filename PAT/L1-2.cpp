/**
 *   @Author: zwding
 *   @Created Time : 2016年05月19日 星期四 19时54分00秒
 *   @Last Modified: 2016年05月19日 星期四 20时22分00秒
 *   @File Name: L1-2.cpp
 *   @Description:
**/
#include<iostream>
#include<string>
using namespace std;

inline int calc(int n){
	return 2*(n*n+2*n)+1;
}
inline int calc1(int n){
	return 2*n+1;
}
int main(){
	int n;
	char s;
	while(cin >> n >> s){
		int q,m;
		for(int i=1;i<=22;i++){
			if(calc(i) > n){
				q = i - 1;
				m = calc(q);
				break;
			}else if(calc(i) == n){
				q = i;
				m = calc(q);
			}
		}
		string t;
		for(int i=q;i>0;i--){
			string tt(calc1(i),s);
			tt = t + tt;
			t = t + " ";
			cout << tt << endl;
		}
		t = t + s;
		cout << t << endl;
		t.erase(t.end()-1);
		for(int i=1;i<=q;i++){
			string tt(calc1(i),s);
			if(t.length() != 0)
				t.erase(t.end()-1);
			//cout << t.size() << endl;
			tt = t + tt;
			cout << tt << endl;
		}
		cout << n - m << endl;
	}
}
