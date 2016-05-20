#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 1000001
#define MAXN 0x7fffffff
#define LL long long
using namespace std;
int f[MAX];
int prime[MAX];
int pri(){
    prime[1] = 1;
    for(int i = 2;i <= 1000;i++){
        if(!prime[i]){
            for(int j = i * i;j <= MAX; j += i){
                if(!prime[j])
                    prime[j] = j / i;
            }
        }
    }
    //cout << cou << " " << prim[--cou] << endl;
}
int getroot(int i){
    if(prime[i] != 0){
        prime[i] = getroot(prime[i]);
    }else
        return i;
    return prime[i];
}

void init(){
    for(int i = 2;i <= 1000000;i++){
        f[i] = prime[i] == 0 ? f[i-1] + 1:1 + f[i / getroot(i)];
        //cout << f[i] << " " << prime[i] << " " << f[i-1] << " " << f[i / getroot(i)] << endl;
    }
}
int main()
{
    //freopen("in","r",stdin);
    int n;
    pri();
    init();
    while(scanf("%d",&n) != EOF){
        cout << f[n] << endl;
    }
    return 0;
}
