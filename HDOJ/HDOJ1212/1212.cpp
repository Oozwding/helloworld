/**
 *  Filename:大数取模 HDOJ1212
 *  Date    :2016/4/7
 *  @Author :zwding 
 *  Describe:大数取模，原理：(a+b)%m = (a%m + b%m)%m
 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//大数取余
int big_int(string& str, int m)
{
    //获得第一个数的长度
    int len = str.size();
    int ans = 0;
    //利用大数模余的基本定理分解求模
    for(int i = 0; i < len; i++)
        ans = (int)(((long long)ans * 10 + (str[i]-'0')) % m);
    return ans;
}

int main()
{
    int m;
    string str;
    //因为第一个数字肯定超过int的最大值，所以采用字符串读进来
    while(cin >> str , scanf("%d",&m) != EOF){
        cout << big_int(str,m) << endl;
    }
    return 0;
}
