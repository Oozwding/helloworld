/**
 *  Filename:HDOJ1018
 *  Date    :2016/3/26
 *  @Author :zwding 
 *  Describe:数学 求n!的位数，n有10^7之大，怎么搞....log10(n!) = log10(1)+ .. +log10(n)
 *           位数就为后面的值+1因为，10^x = n!，x就为n！的位数减一
 */
#include<iostream>
#include<cmath>
using namespace std;

int DigNum(int dig);

int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		int dig;
		cin>>dig;
		cout<<DigNum(dig)<<endl;
	}
	return 0;
}
int DigNum(int number)
{
	double PI=acos(double(-1));
	double e=exp(double(1));
	return int(log10(sqrt(2*PI*number))+number*log10(number/e))+1;
}
