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
    int a,b,i;
    //循环的截至条件为a=0，b=0
    while(scanf("%d%d",&a,&b) , (a || b)){
        //循环判断区间[a,b]的每一个数字
        for(i = a;i <= b; i++){
            //我定义了一个宏 zwding 其实就是那个等式 宏展开一定要注意安全...
            //如果有一个不是的话就 break
            //下面#ifdef DEBUG 是条件编译，也就是如果define DEBUG 就执行后面那句话，否则不执行，用来执行调试期间的语句
            #ifdef DEBUG
            printf("i = %d %d %d\n",i,zwding(i),isprint(zwding(i)));
            #endif // DEBUG
            if(isprime[zwding(i)])
                break;
        }
        //用于判断i是不是循环完毕，完毕就说明都是素数
        //i完成全部循环的条件应该是 i=b+1
        if(i != b+1)
            printf("Sorry\n");
        else
            printf("OK\n");
    }
    return 0;
}
