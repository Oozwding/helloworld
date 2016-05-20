 /**
 *  Filename:HDOJ1398
 *  Date    :2016/4/20
 *  @Author :zwding
 *  Describe:母函数应用
 */
 /**16924108	2016-04-20 20:09:54	Accepted	1398	15MS	1588K	728 B	G++	zwding*/
#include <iostream>
#include <cmath>
#define MAXN 305
#define X 17
using namespace std;
int c1[MAXN],c2[MAXN];
int main()
{
    int n;
    while(cin >> n,n){
        for(int i=0;i<=n;i++){
            c1[i] = 1;
            c2[i] = 0;
        }
        for(int i=2;i<=X;i++){
            for(int k=0;k<=n;k++){
                for(int j=0;j+k<=n;j+=i*i){
                    c2[j+k] += c1[k];
                }
            }
            for(int j=0;j<=n;j++){
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[n] << endl;
    }
    return 0;
}
