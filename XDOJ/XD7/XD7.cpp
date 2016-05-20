#include <cstdio>
#include <iostream>
#include <queue>
#define LL long long
using namespace std;
priority_queue<LL,vector<LL>,greater<LL> > pq;
int n,m;
LL temp;
int main(){
    //freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        temp = 0;
        for(int i=0;i<n;i++){
            scanf("%lld",&temp);
            pq.push(temp);
        }
        LL ans = 0;
        LL tt = 0;
        if(n<=m){
            for(int i=0;i<m && !pq.empty();i++){
                ans += pq.top();
                pq.pop();
            }
            cout << ans << endl;
            continue;
        }
        int k = (n-m) % (m-1);
        if(k != 0){
            k = k + 1;
            for(int i=0;i<k;i++){
                tt += pq.top();
                pq.pop();
            }
            pq.push(tt);
            ans += tt;
            tt = 0;
        }
        while(pq.size() > 1){
            for(int i=0;i<m && !pq.empty();i++){
                tt += pq.top();
                //cout << pq.top() << " ";
                pq.pop();
            }
            pq.push(tt);
            ans += tt;
            //cout << "tt:" << tt << " ans:" << ans << endl;
            tt = 0;
        }
        while(!pq.empty())
            pq.pop();
        printf("%lld\n",ans);
    }
}
