#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct node{
    int be;
    int en;
    int cha;
}num[100050];
int sign[100050];
int main(){
    int k,n;
    int ans=0,ans1=0;
    int isyes;
    while(scanf("%d%d",&n,&k)!=EOF){
        isyes = 0;ans=0;ans1=0;
        memset(sign,0,sizeof(sign));
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d %d",&num[i].be,&num[i].en);
            num[i].cha = num[i].en - num[i].be;
            sign[i]=num[i].be;
            ans+=num[i].be;
            ans1+=num[i].en;
        }
        if(ans > k || ans1 < k){
            cout << "Xue Beng" << endl;
            continue;
        }else if(ans == k){
            for(int i=0;i<n;i++)
                if(i != n-1)
                    cout << num[i].be << " ";
                else{
                    cout << num[i].be << endl;
                }
            continue;
        }else if(ans1 == k){
            for(int i=0;i<n;i++)
                if(i != n-1)
                    cout << num[i].en << " ";
                else{
                    cout << num[i].en << endl;
                }
            continue;
        }
        for(int i=n-1;i>=0;i--){
            if((ans + num[i].cha) >= k){
                sign[i] = num[i].en - (ans + num[i].cha - k);
                isyes = 1;
                break;
            }else{
                sign[i] = num[i].en;
                ans += num[i].cha;
            }
        }
        if(isyes)
            for(int i=0;i<n;i++)
                if(i != n-1)
                    cout << sign[i] << " ";
                else
                    cout << sign[i] << endl;
        else
            cout << "Xue Beng" << endl;
    }
    return 0;
}
