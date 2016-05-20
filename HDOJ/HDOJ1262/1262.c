/**
 *  Filename:HDOJ2012
 *  Date    :2016/3/29
 *  @Author :zwding
 *  Describe:素数打表
 */ 
#include <stdio.h>
//#define DEBUG
#define zwding(a) ((a)*(a)+(a)+41)

int isprime[10000];
//判断素数前事先打表，节省时间，可以当做模板
void judgeprime()
{
    //处理0和1的特殊情况，如果值为1就不是素数
    isprime[0] = isprime[1] = 1;
    //举个栗子，假如i=2，那么 2*2 肯定不是素数 2*3 肯定不是 就可以统统把他们置为1
     for(int i = 2; i < 100; i++)
        //j+=i 其实就等于 2*2 2*3 2*4 2*5 每次都加2
         for(int j = i * i; j < 10000; j += i)
            //不是素数就置为1
             isprime[j] = 1;
}
int main()
{
    #ifdef DEBUG
    freopen("in","r",stdin);
    #endif // DEBUG
    //打表
    judgeprime();
    int n,tmp;
    //循环的截至条件为a=0，b=0
    while(scanf("%d",&n) != EOF){
        tmp=n/2;   //从最接近出开始找
        while(tmp>=2)
        {
            if(!isprime[tmp] && !isprime[n-tmp])
            {
                printf("%d %d\n",tmp,n-tmp);
                break;
            }
            tmp--;  //递减
        }
    }
    return 0;
}
