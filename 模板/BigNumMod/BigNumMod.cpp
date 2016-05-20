#include <iostream>
#include <cstring>
using namespace std;
//乘法取余
int mul_mod(int a, int b, int n)
{
    a %= n; b %=n;
    return (int)((long long) a * b % n);
}
//大数取余
int big_int(char *n, int m)
{
    int len = strlen(n);
    int ans = 0;
    for(int i = 0; i < len; i++)
        ans = (int)(((long long)ans * 10 + (n[i]-'0')) % m);
    return ans;
}
//幂取余
int pow_mod(int a, int n, int m)
{
    if(n==1)
        return a;
    else{
        int x = pow_mod(a, n/2, m);
        long long ans = (long long)x * x % m;
        if (n % 2 == 1)
            ans = ans * a % m;
        return (int) ans;
    }
}
int main()
{
    char *x = "6534";
    /*int x = pow_mod(2,10,10);
    cout << x << endl;*/
    cout << big_int(x,5);
    return 0;
}
