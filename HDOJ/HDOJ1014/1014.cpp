/**
 *  Filename:HDOJ1014
 *  Date    :2016/3/30
 *  @Author :zwding
 *  Describe:里面涉及到了一处数论知识 
 *           2.a和b两个数互质，那么m = (a*i)%b i=0,1,2,3... 那么m恰好能得到任意的余数(0<m<b)
 */
#include <iostream>
#include <cstdio>
using namespace std;

///辗转相除法求最大公约数（更相减损术）
///最小公倍数 = (a*b)/最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF)
    {
        if (gcd(a, b) == 1)
            printf("%10d%10d    Good Choice\n",a,b);
        else
            printf("%10d%10d    Bad Choice\n",a,b);
        printf("\n");
    }
}
