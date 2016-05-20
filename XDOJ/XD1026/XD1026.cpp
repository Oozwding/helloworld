/**
 *  Filename:XDOJ1026
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:快速幂
 */
#include <iostream>
#include <cstdio>
using namespace std;
int MOD;
int powmod(int a,int b){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>=1;
    }
    return ans;
}
int main()
{
    int a,b;
    while(scanf("%d %d %d",&a,&b,&MOD) != EOF){
        int ans = powmod(a,b);
        cout << ans << endl;
    }
    return 0;
}
