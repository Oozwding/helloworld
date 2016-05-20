/**
 *  Filename:HDOJ 5479
 *  Date    :2016/4/9
 *  @Author :zwding
 *  Describe:栈应用
 */
 /** 16826973	2016-04-09 22:58:25	Accepted	5479	15MS	1556K	963 B	G++	zwding */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAXN 10001
#define LL long long
#define INF 0xfffffff
using namespace std;
char s[MAXN];
int main()
{
    int t,n,m,i;
    scanf("%d",&t);
    while(t--)
    {
        stack<char> q;
        scanf("%s",s);
        int len = strlen(s);
        int cnt = 0;
        for(i = 0;i < len;i++)
        {
            if(q.empty())
                q.push(s[i]);
            else
            {
                char ch = q.top();
                if(ch == '(' && s[i] == ')')
                    q.pop(),cnt++;
                else
                    q.push(s[i]);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
