 /**
 *  Filename:HDOJ2824
 *  Date    :2016/4/22
 *  @Author :zwding
 *  Describe:帅选法求欧拉函数的应用
 */
///16946935	2016-04-22 14:00:29	Accepted	2824	140MS	13332K	588B	G++	zwding
#include <iostream>
#define LL long long
#define MAXN 3000001
using namespace std;
int phi[MAXN];
void Euler(){
    phi[1] = 1;
    for(int i=2;i<MAXN;i++)
        if(!phi[i]){
            for(int j = i;j < MAXN;j+=i){
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i *(i - 1);
            }
        }
}
int main()
{
    Euler();
    int a,b;
    while(cin >> a >> b){
        LL ans = 0;
        for(int i = a;i <= b;i++){
            ans += phi[i];
        }
        cout << ans << endl;
    }
    return 0;
}
