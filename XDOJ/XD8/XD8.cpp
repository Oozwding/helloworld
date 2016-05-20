#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 100000007
#define LL long long
using namespace std;

void mul(LL A[][3],LL B[][3]){
    LL c[3][3];
    memset(c,0,sizeof(c));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                c[i][j] += A[i][k] * B[k][j] % MOD;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            A[i][j] = c[i][j];
        }
    }
}
LL tri(LL i){
    if(i==0 || i==1 || i==2)
        return 1;
    LL a[3][3] = {{1,1,1},{0,0,0},{0,0,0}};
    LL b[3][3] = {{1,1,0},{1,0,1},{1,0,0}};
    int p=i-2;
    while(p){
        if(p & 1){
            mul(a,b);
        }
        p >>= 1;
        mul(b,b);
    }
    return a[0][0];
}

int main()
{
    LL a,b;
    while(scanf("%d%d",&a,&b) != EOF){
        tri
    }
    return 0;
}
