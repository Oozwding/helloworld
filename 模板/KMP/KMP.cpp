/**
 *  Filename:KMP template
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:KMP算法
 */
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#define MAX 1000
using namespace std;
int next[MAX];
//构建next表
void build_next(const string p){
    int j = 0;
    int s = p.size();
    int t = next[0] = -1;
    while(j < s){
        if(t < 0 || p[j] == p[t])
            next[++j] = ++t;
        else{
            t = next[t];
        }
    }
}
int kmp(const string T,const string P){
    int n = T.size(), i = 0;//文本串指针
    int m = P.size(), j = 0;//模式串指针
    while(j < m && i < n)
        if(j < 0 || T[i] == P[j]){
            i++;j++;
        }else
            j = next[j];
    return i-j;
}
int main()
{
    string x;
    cin >> x;
    build_next(x);
    //测试next表
    for(int i=0;i<=x.size();i++)
        cout << next[i] << " ";
    string y;
    cin >> y;
    int n = y.size();
    int m = x.size();
    int sign = kmp(y,x);
    if(sign <= n - m)
        cout << "匹配成功 位置为:" << sign << endl;
    else
        cout << "匹配失败" << endl;
    return 0;
}
