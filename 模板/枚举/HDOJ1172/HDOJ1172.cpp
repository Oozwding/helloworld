 /**
 *  Filename:HDOJ1172
 *  Date    :2016/4/29
 *  @Author :zwding
 *  Describe:枚举
 */
#include <stdio.h>
#include <string.h>
#define M 100;

int main(){
	int arr[100][4] = { {0}};
	int a[100] ={ 0 };
	int b[100] ={ 0 } ;
	int N;
	int result = 0;
	int t;
	int t1 = 0, t2 = 0;
	int k;
	int i,j,p;
	int flag = 0;
	int tmp[4] = {0};
	int ass[4] = {0};

	while(scanf("%d",&N)!= EOF && N != 0){
		for( i = 0; i < N ; i ++){
			scanf("%d%d%d",&arr[i][0],&a[i],&b[i]);
			for(j = 3; j > 0 ; j --){
				arr[i][j] = arr[i][0] % 10;
				arr[i][0] = arr[i][0] / 10;
			}

		}
		flag = 0;
		for( i = 1000; i <= 9999; i ++){
			//将i转换成数组中的四个数
			t = i;
			for( j = 3; j >= 0 ; j --){
				tmp[j] = t % 10;
				t = t /10;
			}
			//对照待测数组
			for( k = 0; k < N ; k ++){
				memset(ass,0,4*sizeof(int));
				//首先位置对照
				t1 = 0;
				t2 = 0;
				for( j = 0 ; j < 4; j ++){
					if(arr[k][j] == tmp[j] ){
						t2 += 1;
					}
				}
				if(t2 != b[k]){
					break;
				}
				else{
					//数字对照
					for( j = 0; j < 4; j ++){
						for( p = 0; p < 4 ; p ++){
							if(arr[k][j] == tmp[p] && ass[p] == 0){
								t1 += 1;
								ass[p] = 1;
								break;
							}
						}
					}
					if(t1 != a[k]){
						break;
					}
				}
			}
			if(k >= N ){
				//printf("%d\n",i);
				result = i;
				flag += 1;
			}
			if(flag > 1){
                break;
			}

		}
		if(flag <= 1){
			printf("%d\n",result);
		}
		if(flag > 1){
			printf("Not sure\n");
		}
		//
	}
}
