#include<iostream>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;
//树节点
typedef struct tree{
    int num;
    struct tree* lchild;
    struct tree* rchild;
}T;
//v1为先序遍历
//v2为中序遍历
vector<int> v1,v2;
//建树
//l1：先序遍历的左边界（包括边界）r1：先序遍历的右边界（包括边界）
//l2：中序遍历的左边界（包括边界）r2：中序遍历的右边界（包括边界）
T* buildtree_pre(int l1,int r1,int l2,int r2){
	//检查边界
    if(l2 > r2)
        return NULL;
	//先取出根
    int root = v1[l1];
	//从堆上分配一个树节点并初始化
    T* t = new T;
    t->num = root;
    t->lchild = NULL;
    t->rchild = NULL;
	//左右边界重合，只有一个节点，则返回
    if(l2 == r2)
        return t;
	//确定左右子树的中序遍历的左右边界
    int tt = l2;
    int R2;
    while(tt <= r2){
        if(v2[tt] == root){
            R2 = tt - 1;
            break;
        }
        tt++;
    }
    tt = r2;
    int L2;
    while(tt >= l2){
        if(v2[tt] == root){
            L2 = tt + 1;
            break;
        }
        tt--;
    }
	//继续递归求解
    t->lchild = buildtree_pre(l1+1,l1+1+R2-l2,l2,R2);
    t->rchild = buildtree_pre(r1-(r2-L2),r1,L2,r2);
    return t;
}

//层次遍历
void bfs(T* t){
    queue<T*> q;
    q.push(t);
	//控制输出格式
    int cnt = 0;
    while(!q.empty()){
        cnt == 0 ? cout << q.front()->num:cout << " " << q.front()->num;
		//这里注意镜面反转，左右子树翻转
		//所以右子树先入队
        if(q.front()->rchild)
            q.push(q.front()->rchild);
		//然后左子树入队
        if(q.front()->lchild)
            q.push(q.front()->lchild);
        q.pop();
        cnt++;
    }
    cout << endl;
}
int main(){
    int n;
	//读取树的节点数
    while(cin >> n){
        int m;
        int t = n;
		//读取中序遍历
        while(t--){
            cin >> m;
            v2.push_back(m);
        }
        t = n;
		//读取前序遍历
        while(t--){
            cin >> m;
            v1.push_back(m);
        }
		//建树
        T* ans = buildtree_pre(0,n-1,0,n-1);
       	//层次遍历
        bfs(ans);
        v1.clear();v2.clear();
    }
    return 0;
}
