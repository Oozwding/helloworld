 /**
 *  Filename:HDOJ1085
 *  Date    :2016/4/21
 *  @Author :zwding
 *  Describe:母函数应用
 */
 /** 16928424	2016-04-21 10:37:49	Accepted	1085	31MS	1636K	1257 B	G++	zwding*/
#include <iostream>
#include <cstdio>
#define MAXN 8005
using namespace std;
int c1[MAXN],c2[MAXN];
int main()
{
    int num[4];
    while(cin >> num[1] >> num[2] >> num[3],num[1] || num[2] || num[3]){
         int _max = num[1]*1+num[2]*2+num[3]*5;
        // 初始化
        for(int i=0; i<=_max; ++i){
            c1[i] = 0;
            c2[i] = 0;
        }
        for(int i=0; i<=num[1]; ++i)
            c1[i] = 1;
        for(int i=0; i<=num[1]; ++i)
            for(int j=0; j<=num[2]*2; j+=2)
                c2[j+i] += c1[i];
        for(int i=0; i<=num[2]*2+num[1]*1; ++i){
            c1[i] = c2[i];
            c2[i] = 0;
        }
        for(int i=0; i<=num[1]*1+num[2]*2; ++i)
            for(int j=0; j<=num[3]*5; j+=5)
                c2[j+i] += c1[i];
        for(int i=0; i<=num[2]*2+num[1]*1+num[3]*5; ++i){
            c1[i] = c2[i];
            c2[i] = 0;
        }
        int i; 
        for(i=0; i<=_max; ++i)
            if(c1[i] == 0){
                printf("%d\n", i);
                break;
            }
        if(i == _max+1)
            printf("%d\n", i);
    }
    return 0;
}
