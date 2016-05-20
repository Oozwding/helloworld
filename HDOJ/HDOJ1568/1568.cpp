/**
 *  Filename:1568 Fibonacci
 *  Date    :2016/3/19
 *  @Author :zwding
 *  Describe:Fibonacci 通项公式
 */
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n;
    int i;
    int f[31];
    double temp1=log10((1.0+sqrt(5.0))/2.0),temp2=log10(sqrt(5.0));
    f[0]=0;
    f[1]=1;
    for(i=2;i<31;i++)
        f[i]=f[i-1]+f[i-2];
    while(~scanf("%d",&n))
    {
        if(n<31)
        {
            int temp=f[n];
            while(temp>=10000)
                temp/=10;
            printf("%d\n",temp);
        }
        else
        {
            double t;
            int ans;
            t=(n*temp1-temp2);
            t-=(int)t;
            ans=pow(10.0,t)*1000.0;
            printf("%d\n",ans);
        }
    }
    return 0;
}
