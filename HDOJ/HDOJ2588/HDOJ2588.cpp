 /**
 *  Filename:HDOJ2588
 *  Date    :2016/4/22
 *  @Author :zwding
 *  Describe:欧拉函数的应用
 */
///16951306	2016-04-22 16:54:58	Accepted	2588	15MS	1404K	826B	G++	zwding
#include<stdio.h>
#include<string.h>
//欧拉函数定义 phi[i] = i * (1 - 1/p1).....
int euler(int n){
    int res=n,i,j;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            n=n/i;
            while(n%i==0)
                n=n/i;
            res=res/i*(i-1);
        }
        if(n<(i+1))
            break;
    }
    if(n>1)
        res=res/n*(n-1);
    return res;
}
int main()
{
    int T,n,m,i,sum;
    while(scanf("%d",&T)!=EOF){
        while(T--){
          sum=0;
          scanf("%d%d",&n,&m);
          for(i=1;i*i<=n;i++)
              if(n%i==0){
                  if(i>=m)
                      sum=sum+euler(n/i);
                  if((n/i)!=i&&(n/i)>=m)
                      sum=sum+euler(i);
              }
          printf("%d\n",sum);
        }
    }
    return 0;
}
