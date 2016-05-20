 /**
 *  Filename:HDOJ1085
 *  Date    :2016/4/21
 *  @Author :zwding
 *  Describe:母函数应用
 */
/**16930890	2016-04-21 15:56:56	Accepted	1709	93MS	1724K	1434B	G++	zwding*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 10005
using namespace std;
int num[102];
int c1[MAXN],c2[MAXN];
int ans[MAXN];
int main()
{
    int n;
    while(cin >> n){
        int sum = 0;
        for(int i=1;i<=n;i++){
            cin >> num[i];
            sum += num[i];
        }
        sort(num+1,num+n+1);
        memset(c1,0,sum*sizeof(c1[0]));
        memset(c2,0,sum*sizeof(c2[0]));
        memset(ans,0,sum*sizeof(ans[0]));
        c1[0] = 1;
        int temp = num[1];
        for(int i=1;i<=n;i++){
            for(int j=0;j+num[i] <= sum;j++){
                if(c1[j] == 1){
                    c2[j] = 1;
                    c2[j+num[i]] = 1;
                    c2[abs(j-num[i])] = 1;
                }
            }
            for(int j=0;j<=sum;j++){
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        int cou=0;
        for(int i=1;i<=sum;i++){
            if(!c1[i]){
                ans[cou] = i;
                cou++;
            }
        }
        if(cou == 0){
            cout << 0 << endl;
        }else{
            cout << cou << endl;
            for(int i=0;i<cou;i++){
                cout << ans[i];
                if(i!=(cou-1))
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
