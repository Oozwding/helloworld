/**
 *  Filename:XD9 16年校赛网络赛
 *  Date    :2016/4/20
 *  @Author :zwding
 *  Describe:01背包问题 只不过这题背包容量很大，内存一直超，所以就考虑将价值看做容量，容量看做价值就OK
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1005
#define INF 0x3f3f3f3f
int w[MAX],v[MAX];
int W,N;
int dp[MAX*50];
int main(){
    int sum;
    while(scanf("%d%d",&N,&W) != EOF){
        sum = 0;
        for(int i=1;i<=N;i++){
            scanf("%d%d",&w[i],&v[i]);
            sum += v[i];
        }
        for(int i=0;i<=sum;i++)
            dp[i] = INF;
        dp[0] = 0;
        for(int i=1;i<=N;i++){
            for(int j=sum;j>=v[i];j--){
                dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        for(int i=sum;i>=0;i--)
            if(dp[i]<=W){
               printf("%d\n",i);
               break;
           }

    }
}
