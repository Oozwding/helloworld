/**
 *  Filename:HDOJ1222
 *  Date    :2016/3/30
 *  @Author :zwding
 *  Describe:里面涉及到了两处数论知识
 *           1.gcd也就是两个数的最大公约数的求法
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (gcd(a, b) == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
