/**
 *   @Author: zwding
 *   @Created Time : 2016年05月19日 星期四 20时56分15秒
 *   @Last Modified: 2016年05月19日 星期四 20时58分53秒
 *   @File Name: L1-4.cpp
 *   @Description:
**/
#include<iostream>
using namespace std;
// 5*(F-32)/9
int main(){
	int n;
	while(cin >> n){
		cout << "Celsius = " << 5*(n-32)/9 << endl;
	}
	return 0;
}
