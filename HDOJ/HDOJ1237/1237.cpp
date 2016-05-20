/**
 *  Filename:中缀表达式求值 1237
 *  Date    :2016/3/20
 *  @Author :zwding
 *  Describe:中缀表达式求值 并且转为后缀表达式RPN
 */
#include<stdio.h>
#include<string.h>
#define MAX 250
int main()
{
    int j,i,top;
    double n,m,sum,a,c;
    char fu;
    double zhan[MAX];
    char kongge;
    while(scanf("%lf",&a) != EOF)
    {
        memset(zhan,0,sizeof(zhan));
        kongge = getchar();  //输入空格
        if(a == 0 && kongge == '\n')
            break;
        top=0;
        zhan[top++]=a;  //第一个数存栈
        scanf("%c",&fu);//输入运算符
        kongge = getchar();
        while(scanf("%lf",&a) != EOF)
        {
            if(fu == '*')          //如果运算符是乘号或者除号则直接运算并且将参与运算的栈中的因式删去
            {                     //将得到的结果存入栈中
                sum = zhan[top-1];
                sum *= a;
                zhan[top-1] = sum;
            }
            else if(fu == '/')
            {
                sum = zhan[top-1];
                sum /= a;
                zhan[top-1]=sum;
            }
            else if(fu == '+')   //如果是加法则将其存入栈中
                zhan[top++] = a;
            else if(fu == '-')//如果是减法将其相反数存入栈中
                zhan[top++]=-a;
            kongge = getchar();
            if(kongge == '\n')
                break;
            scanf("%c",&fu);
            kongge = getchar();
        }
        c = 0;
        for(i = 0;i < top;i++)
        {
            c += zhan[i];
        }
        printf("%.2lf\n",c);
    }
    return 0; 
}
