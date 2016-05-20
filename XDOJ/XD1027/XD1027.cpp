/**
 *  Filename:XDOJ1027
 *  Date    :2016/4/12
 *  @Author :zwding
 *  Describe:fib数列 矩阵快速幂 大数模余
 */
 /*** 36388	14020310043 1027 正确 1688 468 C++/Edit 991B 2016-04-12 23:56:26 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define M 1000000007
#define LL long long
using namespace std;
//定义矩阵的乘法
///注意：由于对1000000007取模，也就是两个数相乘绝对超int所以就定义为long long，这样就不会超了
void MarMul(LL C[2][2],LL B[2][2]){
    LL D[2][2];
    memset(D,0,sizeof(D));
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++)
                D[i][j] += C[i][k] * B[k][j];
                D[i][j] %= M;
        }
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++)
            B[i][j] = D[i][j];
}
void Martrix(int n){
    //初始化工作
    ///一定要建好模型，找出正确的矩阵
    LL B[2][2] = {{1,0},{0,1}};
    LL A[2][2] = {{2,1},{1,0}};
    LL C[2][2] = {{2,1},{1,0}};
    while(n){
        //如果是奇数，就乘起来
        if(n & 1){
            MarMul(A,B);
        }
        MarMul(A,A);
        //除以2
        n >>= 1;
    }
    cout << B[0][0] << endl;
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        //前两项直接输出
        if(n == 0)
            cout << 0 << endl;
        else if(n == 1)
            cout << 1 << endl;
        else
            Martrix(n-1);
    }
    return 0;
}
