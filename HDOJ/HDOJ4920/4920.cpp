/**
 *  Filename:HDOJ4920
 *  Date    :2016/
 *  @Author :zwding
 *  Describe:矩阵相乘
 */
 /*** 16849291	2016-04-12 17:38:53	Accepted	4920	1544MS	9220K	1738B	G++	zwding */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 810
#define LL long long
#define INF 0x7fffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
double dpow(double a,LL b){double ans=1.0;while(b){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
//head

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int ans[MAXN][MAXN];
int main(){
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF){
        for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
			    scanf("%d",&a[i][j]);
			    a[i][j] %= 3;
		    }
	    }
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
			    scanf("%d",&b[i][j]);
			    b[i][j] %= 3;
		    }
	    }
        mem(ans);
        //下面这个版本超市了，TLE
       /* for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]);//在这里取余的话会TLE
                }
            }
        }*/
        for(k=0;k<n;k++){//这一层放在最里边会超时
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					ans[i][j]+=a[i][k]*b[k][j];
				}
		}
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
            printf(j == n-1?"%d\n":"%d ",ans[i][j] % 3);
        }
    }
    return 0;
}
