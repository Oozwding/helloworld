/**
 *  Filename:HDOJ3791
 *  Date    :2016/4/11
 *  @Author :zwding
 *  Describe:二叉搜索树
 */
 /*** 16840926	2016-04-11 19:15:05	Accepted	3791	0MS	1420K	1164 B	G++	zwding */
//题目意思是：根据第一组数据建成二叉搜索树，然后又给了n组数据，让你判断后面n组数据建成的二叉搜索树是不是和第一组一样
//二叉搜索树：二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。
//题目的数据量很小，所以直接数组模拟建树，为了比较的方便直接建成完全二叉树。
//这样就便于比较了，只要是相同位置必有相同的值，否则不是相同的二叉树。
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

const int MAX = 1025;

char tra[MAX],trb[MAX],seq[11];
//插入建树
bool Insert(char tr[],char c){
	//根节点所在下标
	//他的左子树下标为 他*2 右子树下标为 他*2+1 （你们可以模拟的试一试，一定要知道这个）
	int st = 1;
	bool mark = true;
	
	//循环寻找合适的位置
	while(1){
		//当此前位置空时，则可以插入，因为刚开始默认初始化为0，表示当前位置没有数据
		if(tr[st] == 0){
			//插入数据
			tr[st] = c;
			//每插入一次就对比一次，因为只要一经插入，他的位置就不会改变，可以节省时间
			//当然你也可以全部插完之后再进行比对，就是有点耗时
			if(tr[st]!=tra[st])
                		mark = false;
			//退出循环
			break;
		}
		//如果插入数据 > 大于当前节点 则插到右子树
		if(tr[st] < c){
			//右子树
			st = (st << 1) + 1;
		}else{
			//否则就左子树
			st = (st << 1);
		}
	}
	return mark;
}
//建树
bool BuildTree(char tr[],char seq[],int len){
	int i;
	bool mark = true;

	for(i=0;i<len;++i){
		//插入建树，和以前的都一样
		mark = Insert(tr,seq[i]);
		//如果不匹配，直接退出
		if(!mark)
            		break;
	}
	return mark;
}

int main(){
	int n,len;
	bool mark;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n) && n){
		memset(tra,0,sizeof(tra));
		//第一组数据
		scanf("%s",seq);
		len = strlen(seq);
		//将第一组数据建成二叉搜索树
		//存在tra数组里面，以后每次都和tra数组进行对比
		BuildTree(tra,seq,len);
		while(n--){
			//循环读入n组对比数据
			scanf("%s",seq);
			len = strlen(seq);
			//用来标记二叉搜索树是否一样
			mark = true;
			memset(trb,0,sizeof(trb));
			mark = BuildTree(trb,seq,len);
			if(mark){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
