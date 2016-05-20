/**
 *  Filename:HDOJ1198
 *  Date    :2016/4/9
 *  @Author :zwding 
 *  Describe:
 *   并查集（简单）：
 *   这题麻烦在各种方向的设定，其实用到的并查集很少，就是最后算集合数的
 *   方向设定好后，直接扫一遍n*m的图，对当前位置的处理就是 对可延伸方向（也就是水管能到下个方块的方向）
 *   的相邻方块判断，如果该延伸方向的水管同样能延伸过来，就把这两个方块的根节点合并起来。
 *   其实也就是并查集最基础的应用了。
 *   等扫完一遍图后，再去算最后的集合数就行了。
 *   p.s.因为开的fa[]数组是一维数组，就有个从开始二维的Map转换到一维的fa[]（记录根节点的数组）数组的过程
 *   其实这一想也很简单， 就是 一维位置pos = i * m + j;
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define MAXS 2505
using namespace std;
int n, m;
int fa[MAXS], vis[MAXS],
/**  顺序： 上、左、下、右.  */
    kinds[11][4] = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1},
                 {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 0},
                 {0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 1} },
    dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char Map[51][51];

//路径压缩，将数组后驱直接表示成自己的祖先，为之后寻找节省了时间
int get_fa(int x) {
    if(x != fa[x])
        fa[x] = get_fa(fa[x]);
    return fa[x];
}
//初始化工作
void init(int n, int m) {
    for(int i = 1; i <= n * m; i ++) {
        fa[i] = i;
        vis[i] = 0;
    }
}
//是否越界
bool out(int x, int y) {
    if(x >= n || y >= m || x < 0 || y < 0) return true;
    return false;
}
//合并集合，直接将另一个的祖先赋值给另一个
void Union(int x, int y) {
    int xfa = get_fa(x), yfa = get_fa(y);
    fa[yfa] = xfa;
}

void solve(int n, int m) {
    //遍历二维数组
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            //线性数组的相对位置
            int pos = m * i + j + 1;
            for(int k = 0; k < 4; k ++) {
            //遍历四个方向 上左下右
                int nextx = i + dir[k][0], nexty = j + dir[k][1],
                //同上，数组的相对位置
                    nextPos = pos + m * dir[k][0] + dir[k][1];
                //保证没有越界
                if(!out(nextx, nexty)) {
                //如果都有管子，将两个集合合并
                //注意后面的k+2 % 4
                    if(kinds[Map[i][j] - 'A'][k] && kinds[Map[nextx][nexty] - 'A'][(k + 2) % 4]) {
                        if(get_fa(pos) != get_fa(nextPos)) {
                            Union(pos, nextPos);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m)) {
        if(n == -1 || m == -1) break;
        init(n, m);
        for(int i = 0; i < n; i ++)
            scanf("%s", Map[i]);
        solve(n, m);
        int ans = 0;
        for(int i = 1; i <= n * m; i ++) {
            if(!vis[get_fa(i)]) {
                ans ++;
                vis[get_fa(i)] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

