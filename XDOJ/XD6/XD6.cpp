#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[3][3];
int visit[3][3];
int b[3][3];
int cou;
int gcd(int a,int b){
    int r;
    while(a%b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return  b;
}
void DFS(int k){
    if(k==9){
        cou++;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!visit[i][j]){
                if(k/3>0 && k%3>0){
                    if(gcd(a[i][j],b[k/3-1][k%3]) == 1 && gcd(a[i][j],b[k/3][k%3-1])==1){
                        visit[i][j] = 1;
                        b[k/3][k%3] = a[i][j];
                        DFS(k+1);
                        visit[i][j] = 0;
                    }
                }else if(k==0){
                    visit[i][j] = 1;
                    b[0][0] = a[i][j];
                    DFS(k+1);
                    visit[i][j] = 0;
                }else if(k%3==0){
                    if(gcd(a[i][j],b[k/3-1][k%3]) == 1){
                        visit[i][j] = 1;
                        b[k/3][k%3] = a[i][j];
                        DFS(k+1);
                        visit[i][j] = 0;
                    }
                }else if(k/3==0){
                    if(gcd(a[i][j],b[k/3][k%3-1]) == 1){
                        visit[i][j] = 1;
                        b[k/3][k%3] = a[i][j];
                        DFS(k+1);
                        visit[i][j] = 0;
                    }
                }
            }
        }
    }
}
int main(){
//freopen("in","r",stdin);
    while(scanf("%d%d%d%d%d%d%d%d%d",&a[0][0],&a[0][1],&a[0][2],&a[1][0],&a[1][1],&a[1][2],&a[2][0],&a[2][1],&a[2][2]) != EOF){
        cou=0;
        memset(visit,0,sizeof(visit));
        DFS(0);
        cout << cou << endl;
    }
    return 0;
}
