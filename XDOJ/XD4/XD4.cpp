#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x,y,a;
    while(scanf("%d%d%d",&x,&y,&a) != EOF){
        int sum = x + y;
        int left = a % sum;
        if(left == 0)
            cout << "light" << endl;
        else{
            if(x >= left)
                cout << "wanshen" << endl;
            else{
                cout << "light" << endl;
            }
        }
    }
    return 0;
}
