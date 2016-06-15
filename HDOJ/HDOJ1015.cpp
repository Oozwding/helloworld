/*v - w^2 + x^3 - y^4 + z^5 = target*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;
string s;
bool sign;
bool visit[30];
int ans[5];
int target;
int ans1[5];
void DFS(int n){
    if(sign)
        return;
    if(n == 5){
        if((ans[0]-pow(ans[1],2)+pow(ans[2],3)-pow(ans[3],4)+pow(ans[4],5)) == target){
            sign = 1;
            //copy(ans,ans+5,ans1);
            printf("%c%c%c%c%c\n",ans[0]+'A'-1,ans[1]+'A'-1,ans[2]+'A'-1,ans[3]+'A'-1,ans[4]+'A'-1);
        }
        return;
    }
    for(int i=0;i < s.size();i++){
        if(!visit[i]){
            visit[i] = 1;
            ans[n] = s[i] - 'A' + 1;
            DFS(n+1);
            visit[i] = 0;
        }
    }
}
int main()
{
    while(cin >> target >> s && target && s != "END"){
        memset(visit,0,sizeof(visit));
        sign = 0;
        sort(s.begin(),s.end(),greater<int>());
        //copy(s.begin(),s.end(),ostream_iterator<char>(cout," "));
        DFS(0);
        if(!sign){
            cout << "no solution" << endl;
        }
    }
    return 0;
}
/*
1 ABCDEFGHIJKL
11700519 ZAYEXIWOVU
3072997 SOUGHT
1234567 THEQUICKFROG
0 END
*/
