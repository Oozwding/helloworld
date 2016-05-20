/**
 *  Filename:HDOJ
 *  Date    :2016/
 *  @Author :zwding
 *  Describe:
 */
 /*** 16849487	2016-04-12 17:58:59	Accepted	1575	0MS	1584K	1752 B	G++	zwding */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 10
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
int Mart[MAXN][MAXN];
int ans[MAXN][MAXN];
void Matrix(int A[10][10],int B[10][10],int n)
{
	int T[10][10];
	mem(T);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			for(int k=0;k<n;k++){
                //求模
				T[i][j] = (T[i][j] + A[i][k] * B[k][j])%9973;
			}

		}
	}
	for(int i = 0;i < n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = T[i][j];
		}
	}
}
//矩阵快速幂
void Matrixpow(int A[10][10],int n,int m){
	mem(ans);
	//初始化
	for(int i = 0;i < n;i++)
        ans[i][i] = 1;
	//类似于快速幂
	while(m){
        //当m为奇数时
		if(m % 2)
            Matrix(ans,A,n);
		Matrix(A,A,n);
		m /= 2;
	}
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int m,k;
        cin >> m >> k;
        for(int j = 0;j < m;j++){
            for(int l = 0;l < m;l++){
                cin >> Mart[j][l];
            }
        }
        Matrixpow(Mart,m,k);
		int sum = 0;
		for(int p = 0;p < m;p++)
            sum = (sum + ans[p][p]) % 9973;
		printf("%d\n",sum);
    }
}








