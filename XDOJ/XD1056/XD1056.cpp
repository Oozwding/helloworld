/**
 *  Filename:XDOJ1056
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:卡特兰数+拓展欧几里得
 */
#include <iostream>
#include <cstdio>
#define LL long long
#define MOD 10007
using namespace std;
int h[1001];
LL exp_mod(LL a){
	LL b = MOD - 2;
	LL res = 1;
	while (b){
		if (b & 1)
			res = (res*a) % MOD;
		b >>= 1;
		a = (a*a) % MOD;
	}
	return res;
}

void init(){
	LL i;
	h[0] = h[1] = 1;
	for (i = 2; i <= 1000; i++){
		h[i] = (((4 * i - 2) % MOD * exp_mod(i + 1)) % MOD * h[i - 1]) % MOD;
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n) != EOF){
        cout << h[n] << endl;
    }
    return 0;
}
