/**
 *  Filename:HDOJ3037
 *  Date    :2016/4/14
 *  @Author :zwding
 *  Describe:排列组合 + lucas定理 组合数取模
 */
 /** 16866901	2016-04-14 16:00:34	Accepted	3037	1638MS	2392K	1054B	G++	zwding */
#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
LL f[100002];
//求逆元
LL powmod(LL a,LL b,LL MOD){
    LL ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
//打表
void init(LL p){
    f[0] = 1;
    for(int i=1;i<=p;i++){
        f[i] = (f[i-1] * i) % p;
    }
}
///Lucas定理 C(n,m) % mod = C(n/mod,m/mod)*C(n%mod,m%mod)
LL Lucas(LL x,LL y,LL MOD){
    LL ans = 1;
    while(x && y){
        int a = x % MOD,b = y % MOD;
        //因为x = n + m y = m 所以a肯定大于b，证明略
        //小于的话则不存在
        if(a < b)
            return 0;
        //里面又用到了费马小定理求逆元，当然拓展欧几里得算法也行
        ans = (ans*f[a]*powmod(f[b]*f[a-b]%MOD,MOD-2,MOD)) % MOD;
        //循环
        x = x / MOD;
        y = y / MOD;
    }
    return ans;
}
int main()
{
    //定义成LL类型，便于统一
    int t;
    LL n,m,p;
    cin >> t;
    for(int i=0;i<t;i++){
        scanf("%lld%lld%lld",&n,&m,&p);
        //将阶乘事先打表
        init(p);
        //Lucas定理
        LL ans = Lucas(n+m,m,p);
        cout << ans << endl;
    }
    return 0;
}
