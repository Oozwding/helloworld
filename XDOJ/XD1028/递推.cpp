 /**
 *  Filename:HDOJ1028
 *  Date    :2016/4/20
 *  @Author :zwding
 *  Describe:递推应用 整数拆分
 *  f[n][k] = f[n-k][k] + f[n][k-1]
 */
 /**16921951	2016-04-20 17:30:10	Accepted	1028	0MS	1700K	753B	G++	zwding*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 129;
long long f[MAX][MAX];

void init()
{
    int i, j, k;
    f[0][0] = 1;
    for (i = 1; i < MAX; ++i)
        f[i][1] = 1;
    for (i = 2; i < MAX; ++i)
        for (j = 2; j <= i; ++j) {
            if (j > i - j)
                k = i-j;
            else
                k = j;
            f[i][j] = f[i - j][k] + f[i][j-1];
        }
}

int main()
{
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", f[n][n]);
    }
    return 0;
}
