 /**
 *  Filename:HDOJ4285
 *  Date    :2016/4/28
 *  @Author :zwding
 *  Describe:枚举+二分
 */
 /**17014537	2016-04-28 22:17:42	Accepted	4282	140MS	14096K	1135B	G++	zwding*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstring>
#define min(a,b) a<b?a:b
#define INF 1000000007
using namespace std;
long long n;
long long x,y,z;
long long  a[50005][32];
long long cnt,tmp;
void init()
{
	memset(a,0,sizeof(a));
	for(long long i=1;i<=50000;i++){
		a[i][1]=i;
		for(long long j=2;j<=31;j++){
			a[i][j]=a[i][j-1]*i;
			if(a[i][j]>INF) break;
		}
	}
}
bool binary_search_l(long long x,long long z)
{
	long long l=x+1,r=50000,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid][z]){
			if(tmp+a[mid][z]+x*mid*z==n) return true;
			else if(tmp+a[mid][z]+x*mid*z<n) l=mid+1;
			else r=mid-1;
		}
		else r=mid-1;
	}
	return false;
}
int main()
{
	init();
    while(scanf("%lld",&n)!=EOF){
    	if(!n) break;
    	cnt=0;
    	for(x=1;x<=50000&&x<n;x++){
    		for(z=2;z<=31;z++){
    			if(a[x][z]&&(n-a[x][z])>0){
    				tmp=a[x][z];
    				if(binary_search_l(x,z)) cnt++;
    			}
    		}
    	}
    	printf("%lld\n",cnt);
    }
    return 0;
}
