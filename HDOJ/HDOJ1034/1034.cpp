#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int pown(int n){
    for(int i=1;;i++){
        if(pow(2,i) - 1 == n)
            return i;
        if(pow(2,i) - 1 > n)
            return i - 1;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        int powl = pown(temp);
        //cout << powl << endl;
        int maxn = pow(2,powl - 1) - (temp-(pow(2,powl) - 1)) > 0 ? pow(2,powl - 1) : temp-(pow(2,powl) - 1);
        int maxk = (pow(2,powl - 1) - (temp-(pow(2,powl) - 1))) < 0 ? powl+1 : powl;
        cout << maxk << " " << maxn << endl;
    }
    return 0; 
}
