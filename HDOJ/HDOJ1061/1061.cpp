/**
 *  Filename:HDOJ 1061
 *  Date    :2016/4/10
 *  @Author :zwding  
 *  Describe:快速幂
 */
/** 16827618	2016-04-10 00:40:22	Accepted	1061	0MS	1924K	532 B	G++	zwding */
#include <iostream>
#include <cstdio>
using namespace std;
//快速幂 运用二分的思想
//这是非递归算法，从下往上合并
int mod_exp(int a, int b, int c)        //快速幂取余a^b%c
{
    int res, t;
    res = 1 % c;
    t = a % c;
    while (b)
    {
        if (b & 1)
        {
            res = res * t % c;
        }
        t = t * t % c;
        b >>= 1;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << mod_exp(n, n, 10) << endl;
    }
    return 0;
}
