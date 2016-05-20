/**
 *  Filename:汉诺塔贰
 *  Date    :2016/3/21
 *  @Author :zwding
 *  Describe:动态规划 DP
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 70
#define LL unsigned long long
using namespace std;

LL s[M];
bool vis[M]; 

LL f(int k){
    if(vis[k])
        return s[k];
    //初始化为最大值
    s[k] = ~0;
    //x 1：k-1 取最小值
    for(int i = 1; i < k; ++ i){
        s[k] = min(s[k], f(i)*2+((LL)1<<(k-i))-1);
    }
    //已经处理过
    vis[k] = 1;
    return s[k];
}

int main(){
    int n;
    //预处理 当n=1的情况
    s[1] = 1;
    //表示已经处理过 visit = 1
    vis[1] = 1;
    //printf("%I64u\n", ~0);
    while(scanf("%d", &n) == 1){
        printf("%u\n", f(n));
    }
    return 0;
}
