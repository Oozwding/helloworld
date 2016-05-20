/**
 *  Filename:HDOJ 2035
 *  Date    :2016/4/21
 *  @Author :zwding
 *  Describe:快速幂
 */
///16931387	2016-04-21 16:33:26	Accepted	2035	0MS	1596K	403B	G++	zwding
#include <iostream>
#define MOD 1000;
using namespace std;
int a,b;
int powmod(){
    int ans = 1;
    int t = a % MOD;
    int c = b;
    while(c){
        if(c & 1){
            ans = ans * t % MOD;
        }
        t = t * t % MOD;
        c >>= 1;
    }
    return ans;
}
int main()
{
    while(cin >> a >> b,a && b){
        cout << powmod() << endl;
    }
    return 0;
}
