#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int next[8] = {-1,0,0,0,0,0,0,0};
string P("wanshen");
int m = 7;
int j;
int kmp(const string T){
    int n = T.size(), i = 0;
    int ans = 0;
    while(i < n){
         if(j < 0 || T[i] == P[j]){
            i++;j++;
        }else
            j = next[j];
        if(j == m){
            ans++;
            j=0;
        }
    }
    return ans;
}

int main()
{
    //freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF){
        int ans=0;
        string str;
        j=0;
        for(int i=0;i<n;i++){
            string tmp;
            cin >> tmp;
            ans += kmp(tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
