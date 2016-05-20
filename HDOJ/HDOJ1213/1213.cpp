/**
 *  Filename:HDOJ1213
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:并查集 简单
 */
/** 16814672	2016-04-09 08:56:45	Accepted	1213	31MS	1604K	1032 B	G++  zwding*/

#include <iostream>
#define MAX 1005
using namespace std;
int father[MAX];
//数据预处理
void init(int n){
    for(int i=1;i<=n;i++)
        father[i] = i;
}
//路径压缩，有效的节省查找祖先的时间
int get_father(int a){ 
    if(a != father[a])
        father[a] = get_father(father[a]);
    return father[a];
   /* while(a != father[a])
        a = father[a];
    return a;*/
}
//合并两棵树
void Union(int a,int b){
    int xfa = get_father(a),yfa = get_father(b);
    father[xfa] = yfa;
}
int main(){
    int n;
    int a1,a2;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        init(a);
        for(int j=0;j<b;j++){
            cin >> a1 >> a2;
            //一边读入数据，一边合并
            Union(a1,a2);
        }
        int count = 0;
        //查找一共有几棵树
        for(int j=1;j<=a;j++){
            if(father[j] == j)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
