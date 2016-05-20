/**
 *  Filename:XDOJ1057
 *  Date    :2016/4/14
 *  @Author :zwding
 *  Describe:排列组合+组合数取模+费马小定理求逆元+从n个数取m个数，可重复，不考虑顺序
 */
#include <iostream>
#include <cstdio>
#define LL long long
#define MOD 10007
using namespace std;

LL f[MOD+1];
void init(){
    f[0] = 1;
    for(int i=1;i<=MOD;i++)
        f[i] = f[i-1] * i % MOD;
}

LL powmod(LL a,LL b){
    LL ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

LL Lucas(LL x,LL y){
    LL ans = 1;
    while(x && y){
        int a = x % MOD,b = y % MOD;
        if(a < b)
            return 0;
        ans = (ans * f[a] * powmod(f[b] * f[a-b] % MOD,MOD - 2)) % MOD;
        x = x / MOD;
        y = y / MOD;
    }
    return ans;
}

int main()
{
    LL n,m;
    init();
    while(scanf("%lld%lld",&n,&m) != EOF){
        cout << Lucas(n+m-1,m) << endl;
    }
    return 0;
}
