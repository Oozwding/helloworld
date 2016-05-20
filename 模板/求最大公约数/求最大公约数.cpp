#include <iostream>
//该程序实现了求两个数的最大公约数，求若最小公倍数只要稍作变换：zuixiaogongbeishu = (a  /  zuidagongyueshu) * b。
using namespace std;
int gcd(int a,int b){
    int r;
    while(a%b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return  b;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
