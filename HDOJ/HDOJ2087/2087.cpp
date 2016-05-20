/**
 *  Filename:HDOJ 2087
 *  Date    :2016/4/11
 *  @Author :zwding
 *  Describe:KMP 简单应用
 */
/** 16837556	2016-04-11 10:00:26	Accepted	2087	0MS	1600K	1022 B	G++	zwding */
#include <iostream>
#include <string>
using namespace std;

int nextn[1001];
//构建nextn表
void build_nextn(const string& P){
    int t = nextn[0] = -1;
    int j = 0;
    while(j < P.size()){
        if (t < 0 || P[j] == P[t]){
            nextn[++j] = ++t;
        }else{
            t = nextn[t];
        }
    }
}
int match(const string& T,const string& P){
    int j = 0,i = 0;
    int sum = 0;
    while(j < T.size()){
        if(i == -1 || T[j] == P[i]){
            ++j;++i;
        }else{
            i = nextn[i];
        }
        if(i == P.size()){
            sum++;
            i = 0;
        }
    }
    return sum;
}
int main()
{
    string T,P;
    while(cin >> T,T[0] != '#'){
        cin >> P;
        build_nextn(P);
        cout << match(T,P) << endl;
    }
    return 0;
}
