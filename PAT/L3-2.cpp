/**
 *   @Author: zwding
 *   @Created Time : 2016年05月26日 星期四 23时41分54秒
 *   @Last Modified: 2016年06月01日 星期三 23时13分55秒
 *   @File Name: L3-2.cpp
 *   @Description:
**/

#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iterator>
#define N 100001
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
using namespace std;
stack<int> pq;
int st[N<<2];
void build(int l,int r,int n,int key);
void change(int l,int r,int n,int key);
void updata(int n);
int query(int l,int r,int n,int key);
int main(void){
    //freopen("in.txt","r",stdin);
    int n,key;
    char s[15];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        switch(s[1])
        {
			case 'o':
				if(pq.empty())
					printf("Invalid\n");
				else
				{
					key=pq.top();
					printf("%d\n",key);
					pq.pop();
					change(1,100000,1,key);
				}
				break;
			case 'u':
				scanf("%d",&key);
				pq.push(key);
				build(1,100000,1,key);
				break;
			case 'e':
				if(pq.empty())
					printf("Invalid\n");
				else
				{
					key=pq.size()+1;
					key>>=1;
					printf("%d\n",query(1,100000,1,key));
				}
				break;
		}
    }
    return 0;
}
void build(int l,int r,int n,int key){
    if(l >= r)
    {
        st[n]++;
        return;
    }
    int m=(l+r)/2;
    if(key <= m)
    	build(lson,key);
    else
    	build(rson,key);
	updata(n);
}
void change(int l,int r,int n,int key){
    if(l==r)
    {
        st[n]--;
        return;
    }
    int m = (l + r) / 2;
    if(key <= m)
    	change(lson,key);
    else
    	change(rson,key);
    updata(n);
}
void updata(int n){
    st[n] = st[n<<1] + st[n<<1|1];
}
int query(int l,int r,int n,int key){
    if(l == r)
    	return l;
    int m = (l + r) / 2;
    if(key <= st[n<<1])
    	return query(lson,key);
    else
    	return query(rson,key-st[n<<1]);
}
