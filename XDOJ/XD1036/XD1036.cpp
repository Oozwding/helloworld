/**
 *  Filename:XDOJ1036
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:背包问题 动态规划
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10000
using namespace std;
int w[MAXN];
int f[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans = 0;
        cin >> n;
        for(int i = 0;i < n;i++){
            scanf("%d",&w[i]);
            ans += w[i];
        }
        memset(f,0,sizeof(f));
        int s = ans / 2;
        for(int i = 0;i < n;i++){
            for(int j = s;j >= w[i];j--){
                f[j] = max(f[j],f[j-w[i]]+w[i]);
            }
        }
        cout << ans-2*f[s] << endl;
    }
    return 0;
}
