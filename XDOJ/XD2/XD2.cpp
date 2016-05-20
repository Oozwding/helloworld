#include <iostream>
#include <cstdio>
#define LL long long

using namespace std;
LL fib[100];
LL F[100];
void init(){
    fib[1] = 1;fib[2] = 1;
    F[1] = 1;F[2] = 2;
    for(int i = 3;i <= 90;i++){
        fib[i] = fib[i-1] + fib[i-2];
        F[i] = F[i-1] + fib[i];
        //cout << i << " "<< fib[i] << " " << F[i] << endl;
    }
}
int main()
{
    LL sum;
    LL ansl;
    LL ansm;
    init();
    while(scanf("%lld",&sum) != EOF){
        if(sum <= 3)
            cout << 1 << " " << 1 << endl;
        else
            for(int i=1;i<=90;i++){
                if(sum < F[i]){
                    ansl = fib[i-1] >= (sum - F[i-1]) ? i-1:i;
                    ansm = fib[i-1] >= (sum - F[i-1]) ? fib[i-1]:(sum - F[i-1]);
                    //cout << fib[i-1] << " " << sum << " " << F[i-1] << " " << F[i] << endl;
                    cout << ansl << " " << ansm << endl;
                    break;
                }else if(sum == F[i]){
                    cout << i << " " << fib[i] << endl;
                    break;
                }
            }
       // cout << fib[51] << " " << F[51] << endl;
        //cout << fib[52] << " " << F[52] << endl;
    }
    return 0;
}
