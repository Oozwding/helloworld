/**
 *   @Author: zwding
 *   @Created Time : 2016年05月20日 星期五 09时30分23秒
 *   @Last Modified: 2016年05月20日 星期五 11时40分48秒
 *   @File Name: L1-6.cpp
 *   @Description:
**/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		int l = sqrt(n);
		bool sign = 1;
		for(int i=2;i<=l;i++){
			if(n % i == 0){
				sign = 0;
				break;
			}
		}
		int maxn = 0,maxq = 0;
		int tt = n;
		if(sign){
			cout << 1 << endl << n << endl;
			continue;
		}else{
			int cn=0,cq=0,tc=0;
			for(int i=2;i<=l+1;i++){
				if(tt % i == 0){
					if(cn == 0){
						cq = i;
						cn++;
					}else{
						cn++;
					}
					tt /= i;
					tc = cq;
				}else{
					if(cn > maxn){
						maxn = cn;
						maxq = cq;
					}
					if(cq == 0)
						tc++;
					i = tc;
					cn = 0;
					cq = 0;
					tt = n;
				}
			}
			if(cn > maxn){
				maxn = cn;
				maxq = cq;
				cn = 0;
				cq = 0;
			}
		}
		cout << maxn << endl;
		for(int i=maxq;i<maxq+maxn;i++){
			i == maxq ? cout << i : cout << "*" << i;
		}
		cout << endl;
	}
	return 0;
}
