 /**
 *  Filename:HDOJ1028
 *  Date    :2016/4/20
 *  @Author :zwding
 *  Describe:母函数应用 整数拆分 
 */
 ///16921524	2016-04-20 16:49:41	Accepted	1028	0MS	1592K	590B	G++	zwding
#include <iostream>
#define MAXN 125
using namespace std;
int c1[MAXN],c2[MAXN];
int main()
{
    int n;
    while(cin >> n){
        for(int i=0;i<=n;i++){
            c1[i] = 1;
            c2[i] = 0;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k+j<=n;k+=i){
                    c2[k+j] += c1[j];
                }
            }
            for(int k=0;k<=n;k++){
                c1[k] = c2[k];
                c2[k] = 0;
            }

        }
        cout << c1[n] << endl;
    }
    return 0;
}
