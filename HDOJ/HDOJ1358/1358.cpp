/**
 *  Filename:HDOJ1358 KMP
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:KMP算法
 */
 /** 16818978	2016-04-09 14:17:13	Accepted	1358	124MS	6464K	938B	G++	zwding*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 1000100
using namespace std;
int n;
char s[MAXN];
int nextn[MAXN];
///构建next表
void makenext()
{
    int i = 0,j = -1;
    nextn[i]=j;
    while(i < n)
    {
        if(j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            nextn[i] = j;
        }
        else
            j = nextn[j];
    }
    return;
}
int main()
{
    int i;
    int cas = 0;
    while(scanf("%d",&n) != EOF,n)
    {
        scanf("%s",s);
        printf("Test case #%d\n",++cas);
        makenext();
		for(i = 1;i <= n;i++)
		{
            //判断是否有重复子串
			if(nextn[i] != 0 && i % (i-nextn[i]) == 0)
                printf("%d %d\n",i,i/(i-nextn[i]));
		}
		printf("\n");
    }
    return 0;
}
