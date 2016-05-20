/**
 *  Filename:HDOJ1164
 *  Date    :2016/3/29
 *  @Author :zwding
 *  Describe:整数分解为素数，看完题马上想到DFS，然后，没然后了，直接AC，也许是昨天做过素数环的问题。
 */
#include <iostream>
#include <cstdio>
using namespace std;
//事先打一下表，以防万一总是好的
bool notprime[70000];
//分解的素数数组
int res[1000];
//结束深搜标志
bool sign = false;
//打表
void judgeprime(){
    notprime[0] = true;
    notprime[1] = true;
    for(int i=2;i<256;i++){
        for(int j=i*i;j<=65536;j+=i)
            notprime[j] = true;
    }
}
//深搜，两个参数，当前数还有分解的第几个数
void DFS(int a,int cur){
    //结束标志，如果最后一个是素数，直接打印结果输出，并置标志位为true，退出递归
    if(!notprime[a]){
        //格式化输出
        res[cur] = a; 
        cout << res[0];
        for(int i=1;i<=cur;i++)
            printf("*%d",res[i]);
        cout << endl;
        //置标志位
        sign = true;
        return;
    }
    //循环选择素数，然后测试
    for(int i=2;i<=a;i++){
        /**   如果满足两个条件
          *   1.当前数能整除i
          *   2.i为素数
          *   然后i就为符合条件的素数，记录，并继续搜索，如果标志位为true，结束循环
          */
        if(a%i == 0 && !notprime[i]){
            res[cur] = i;
            DFS(a/i,cur+1);
            if(sign)
                break;
        }
    }
}
int main(){
    int n;
    judgeprime();
    while(scanf("%d",&n) != EOF){
        DFS(n,0);
        sign = false;
    }
    return 0;
}
