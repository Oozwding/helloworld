/**
 *  Filename:HDOJ1016
 *  Date    :2016/3/29
 *  @Author :zwding
 *  Describe:网上百度，然后获得思路 
 */
#include <iostream>
#include <cstdio>

using namespace std;
///因为数字是唯一的
///所以输出就置visit为true
bool visit[21];
//保存结果
int res[21];
int n;
//判断素数，这次没有采用素数表，果然慢了很多 312ms
bool isprime(int a){
    int i;
    for(i = 2;i < a;i++){
        if(a % i == 0)
            break;
    }
    if(i == a)
        return true;
    else
        return false;
}
///深搜遍历 参数表示当前为第几个数
void DFS(int cur){
    //如果为最后一个数，则输出结果，但是还要确保最后一个数和第一个数的和为素数
    if(cur == n && isprime(res[0] + res[n-1])){
        int i;
        printf("1");
        for(i=1;i<n;i++)
            printf(" %d",res[i]);    //打印方案
        printf("\n");
    }else{
        //循环枚举结果，尝试放置每一个数字
        for(int i = 2;i <= n;i++){
            /**  判断条件
              *  1.没有访问过
              *  2.与前项的和为素数
              */
            if(!visit[i] && isprime(res[cur-1] + i)){
                //满足条件加入结果集
                res[cur] = i;
                //置访问标志为true
                visit[i] = true;
                //继续深搜
                DFS(cur+1);
                //返回之后，置为false，清除标记
                visit[i] = false;
            }
        }
    }
}
int main()
{
    int count = 1;
    while(scanf("%d",&n) != EOF){
        printf("Case %d:\n",count++);
        res[0] = 1;
        DFS(1);
        cout << endl;
    }
    return 0;
}
