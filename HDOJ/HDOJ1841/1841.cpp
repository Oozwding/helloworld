/**
 *  Filename:HDOJ1841 KMP
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:KMP算法
 */
 /** 1: 16816947	2016-04-09 11:41:19	Time Limit Exceeded	1841	1000MS	11612K	1127 B	G++	zwding*/
#include <iostream>
#include <string>
#define MAX 1000005
using namespace std;
int next1[MAX];
int next2[MAX];
void build_next(const string p,int *next){
    int t = next[0] = -1;
    int j = 0;
    int s = p.size();
    while(j < s){
        if(t < 0 || p[j] == p[t])
            next[++j] = ++t;
        else
            t = next[t];
    }
}
int kmp(const string& T,const string& P,const int *next){
    int n = T.size(),i = 0;
    int m = P.size(),j = 0;
    while(i < n){
        if(j == m){
            i = i - j + 1;
            j = 0;
        }
        if(j < 0 || T[i] == P[j]){
            i++;j++;
        }else
            j = next[j];
    }
    return i + m - j;
}
int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int xmin = 0x7fffffff;
        string x,y;
        cin >> x >> y;
        build_next(x,next1);
        build_next(y,next2);
        xmin = min(xmin,kmp(x,y,next2));
        xmin = min(xmin,kmp(y,x,next1));
        cout << xmin << endl;
    }
    return 0;
}
