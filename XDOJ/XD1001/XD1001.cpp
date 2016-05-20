/**
 *  Filename:XDOJ1001
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:第一次遇到这种问题，思想很好，不直接交换，而是记录交换，也把二维转为一维
 */
#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int A[1000005];
char s[1000005];
int r[1000005],c[1000005];
char ans[3][20]={"Phone","Empty","Tree"};
int main()
{
    int n,m;
    int cas=1;
    while(~scanf("%d%d",&n,&m))
    {
       //memset(A,0,n*m*sizeof(int));
       int cnt=0;
       for(int i=1;i<=n;i++)r[i]=i;
       for(int j=1;j<=m;j++)c[j]=j;
       for(int i=1;i<=n;i++)
       {
           r[i]=i;
           scanf("%s",s);
           int len=strlen(s);
           for(int j=0;j<len;j++)
           {
                if(s[j]=='T')
                    A[++cnt]=1;
                else if(s[j]=='i')
                    A[++cnt]=-1;
                else
                    A[++cnt]=0;
           }
       }
       int Q,a,b,op;
       cin >> Q;
       printf("Case #%d:\n",cas++);
       while(Q--)
       {
           scanf("%d%d%d",&op,&a,&b);
           if(op == 1)
           {
               int x=A[(r[a] - 1) * m + c[b]];
               puts(ans[x+1]);
           }
           else if(op == 2)
           {
               int t = r[a];
               r[a] = r[b];
               r[b] = t;
           }
           else
           {
               int t =c[a];
               c[a] = c[b];
               c[b] = t;
           }
       }
    }
    return 0;
}
