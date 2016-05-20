#include <iostream>
#include <cstdio>
#include <cstdlib>
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
struct info{
    int m;
    int x;
    int *p;
}*data;
//int **data;

int digui(int i,int w){
    int ans = 0;
    if(data[i].x == 0){
        return data[i].m;
    }else{
        for(int j = 0;j < data[i].x;j++){
            ans += digui(data[i].p[j],w);
        }
        ans += w;
        return min(ans,data[i].m);
    }
}
int main()
{
    freopen("in","r",stdin);
    int p;
    cin >> p;
    for(int i=0;i<p;i++){
        int n,m,w;
        cin >> n >> m >> w;
        data = (struct info *)malloc(n*sizeof(struct info));
        for(int j=0;j<n;j++){
            cin >> data[j].m;
            cin >> data[j].x;
            data[j].p = (int *)malloc(data[j].x*sizeof(int));
            for(int k=0;k<data[j].x;k++){
                cin >> data[j].p[k];
            }
        }
        int ans = 0;
        for(int l=0;l<m;l++){
            int temp;
            cin >> temp;
            ans += digui(temp,w);
        }
        cout << ans << endl;
    }
    return 0;
}
