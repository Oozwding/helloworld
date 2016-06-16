#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int  s;
    char c;
}grid[11][11];
int ans,sign,ans1,ans2;
int n,m;
void DFS(int row,int col){
    if(sign == 1 || sign == -1)
        return;
    if(row < 0 || row >= n || col < 0 || col >=m){
        sign = 1;
        return;
    }
    /*
     * NEESWE
     */
    ans++;
    switch (grid[row][col].c){
        case 'N':
            grid[row][col].s = ans;
            grid[row][col].c = '0';
            DFS(row-1,col);
            break;
        case 'E':
            grid[row][col].s = ans;
            grid[row][col].c = '0';
            DFS(row,col+1);
            break;
        case 'S':
            grid[row][col].s = ans;
            grid[row][col].c = '0';
            DFS(row+1,col);
            break;
        case 'W':
            grid[row][col].s = ans;
            grid[row][col].c = '0';
            DFS(row,col-1);
            break;
        case '0':
            ans1 = ans - grid[row][col].s;
            ans2 = grid[row][col].s - 1;
            sign = -1;
            break;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int b;
    while(cin >> n >> m && (n || m)){
        cin >> b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> grid[i][j].c;
            }
        }
        sign = 0;
        ans = ans1 = ans2 = 0;
        DFS(0,b-1);
        if(sign == 1){
            cout << ans << " step(s) to exit" << endl;
        }else if(sign == -1){
            cout << ans2 << " step(s) before a loop of " << ans1 << " step(s)" << endl;
        }
    }
    return 0;
}
