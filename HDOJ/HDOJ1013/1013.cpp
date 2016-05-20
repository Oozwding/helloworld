/**
 *  Filename:HDOJ 1013
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:算是水题 
 */
 /** 16825150	2016-04-09 20:18:29	Accepted	1013	15MS	1408K	683 B	G++	zwding */
#include<stdio.h>
#include<string.h>
int main()
{
    int sum,k,i;
    char num[10005];
    while(scanf("%s",num)!=EOF)
    {
        sum=0;
        if(num[0]=='0')
        break;
        else
        {
            for(i=0;i<strlen(num);i++)
            sum+=num[i]-'0';
            while(sum>9)
            {
                k=0;
                while(sum)
                {
                    k+=sum%10;
                    sum/=10;
                }
                sum=k;
            }
        printf("%d\n",sum);
        }
    }
    return 0;
}
