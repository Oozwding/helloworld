/**
 *  Filename:XDOJ1054
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:水题
 */
 /*** 36414	14020310043	1054 正确 1688 1 C++/Edit	1013B	2016-04-13 09:04:41 */
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<char,int> p;
void init(){
    p['0'] = 1;p['1'] = 0;p['2'] = 0;p['3'] = 0;
    p['5'] = 0;p['6'] = 1;p['7'] = 0;p['8'] = 2;
    p['9'] = 1;p['4'] = 0;
}
int main()
{
    int n;
    char x[7];
    init();
    while(scanf("%s",x) != EOF){
        int ans = 0;
        for(int i=0;i<strlen(x);i++){
            ans += p[x[i]];
        }
        cout << ans << endl;
    }
    return 0;
}
