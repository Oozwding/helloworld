 /**
 *  Filename:HDOJ1286
 *  Date    :2016/4/22
 *  @Author :zwding
 *  Describe:欧拉函数的应用,由于数据量很小，所以两种方法都哦开
 */
///16952015	2016-04-22 17:12:37	Accepted	1286	0MS	1728K	532B	G++	zwding
///16952136	2016-04-22 17:15:30	Accepted	1286	0MS	1736K	979B	G++	zwding
#include <iostream>
#include <cstdio>
#define MAXN 32768
using namespace std;
int phi[MAXN+1];
void init(){
    phi[1] = 1;
    for(int i=2;i<=MAXN;i++){
        if(!phi[i]){
            for(int j=i;j<=MAXN;j+=i){
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i *(i-1);
            }
        }
    }
}
int euler(int n){
    int ans = n;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            n = n / i;
            while(n%i==0)
                n = n / i;
            ans = ans / i * (i - 1);
        }
        if(n < i+1)
            break;
    }
    if(n > 1)
        ans = ans / n * (n - 1);
    return ans;
}
int main()
{
    init();
    int T;
    cin >> T;
    while(T--){
        int t;
        cin >> t;
        cout << euler(t) << endl;
        //cout << phi[t] << endl;
    }
    return 0;
}
