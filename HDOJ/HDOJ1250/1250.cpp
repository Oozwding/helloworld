/**
 *  Filename:HDOJ1250
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:C++大数应用  自定义Fibonacci 每个数组存储8位
 */ 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[10000][260];//每个数组存8位数字 所以260*8 > 2005
int main()
{
    a[1][0] = 1;
    a[2][0] = 1;
    a[3][0] = 1;
    a[4][0] = 1;
    for(int i=5;i<10000;i++){
        //时间换空间 将260位都处理一下
        for(int j=0;j<260;j++)
            a[i][j]+=a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j];
        for(int j=0;j<260;j++)
        //每八位考虑进位。
            if(a[i][j]>100000000)
            {
                //进位
                a[i][j+1]+=a[i][j]/100000000;
                a[i][j]=a[i][j]%100000000;
            }
    }
    int n,j;
    while(scanf("%d",&n) != EOF){
        for(j=259;j>=0;j--)
            if(a[n][j]!=0) break;      //不输出高位的0
        printf("%d",a[n][j]);
        for(j=j-1;j>=0;j--)
            printf("%08d",a[n][j]);     //每个元素存储了八位数字，所以控制输出位数为8，左边补0
        printf("\n");
    }
}
