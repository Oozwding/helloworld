/**
 *  Filename:XDOJ1129
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:矩阵变换 模拟题
 */
 /*
 直接模拟，两种交换操作的时间复杂度分别是O(n)、O(m)，最坏情况下总时间复杂度为O(Q × max(n, m) + nm)显然会超时。
 注意到，如果连续进行一次行交换操作和一次列交换操作，无论这两次操作顺序如何，结果都不受影响。因此，对于行和列的交换
 操作，可分别定义表line和row，表示当前的第i行是原来的第line[i]行，第j列是原来的第row[j]列。这样，对于每次交换
 操作，只要交换两个数就行了，时间复杂度是O(1)。对于查询第i行j列的操作，直接返回原矩阵第line[i]行，row[j]列的元素就行了，
 时间复杂度O(1)。总的时间复杂度O(Q + nm)。
 */
#include <iostream>
#include <cstdio>
using namespace std;
int A[1000001];
int r[1001];
int c[1001];
int main()
{
    int n,m,q;
    while(scanf("%d %d %d",&n,&m,&q) != EOF){
        for(int i=1;i<=n;i++)
            r[i] = i;
        for(int j=1;j<=m;j++)
            c[j] = j;
        for(int i=1;i<=n*m;i++)
            scanf("%d",&A[i]);
        while(q--){
            int a,b,d;
            cin >> a >> b >> d;
            if(a == 0){
                int t = r[b];
                r[b] = r[d];
                r[d] = t;
            }else{
                int t = c[b];
                c[b] = c[d];
                c[d] = t;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << A[(r[i]-1)*m + c[j]];
                if(j != m)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
