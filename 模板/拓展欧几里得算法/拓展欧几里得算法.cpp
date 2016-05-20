/**
 *  Filename:extGCD
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:拓展欧几里得算法 gcd(a,b) = ax + by
 */
#include <iostream>
using namespace std;

int exgcd(int a,int b,int & x,int & y){
	if(b == 0){
		//根据上面的推理1，基本情况
		x = 1;
		y = 0;
		return a;
	}
	int r = exgcd(b, a%b, x, y);
	//根据推理2
	int t = y;
	y = x - (a/b)*y;
	x = t;
	return r;
}

int ExtendedEuclid(int f, int d, int *result) {
    int x1, x2, x3, y1, y2, y3, t1, t2, t3, q;
    x1 = y2 = 1;
    x2 = y1 = 0;
    x3 = (f >= d) ? f : d;
    y3 = (f >= d) ? d : f;
    while (1) {
        if (y3 == 0) {
            *result = x3; /* 两个数不互素则result为两个数的最大公约数，此时返回值为零 */
            return 0;
        }
        if (y3 == 1) {
            *result = y2; /* 两个数互素则resutl为其乘法逆元，此时返回值为1 */
            return 1;
        }
        q = x3 / y3;
        t1 = x1 - q*y1;
        t2 = x2 - q*y2;
        t3 = x3 - q*y3;
        x1 = y1;
        x2 = y2;
        x3 = y3;
        y1 = t1;
        y2 = t2;
        y3 = t3;
    }
}
int main() {
	int x,y;
	int z;
	/*exgcd(2,13,x,y);
	cout << "47x+30y=1 的一个整数解为: x=" << x << ", y=" << y << endl;
	return 0;*/
	ExtendedEuclid(2,13,&z);
	cout << z << endl;
}
