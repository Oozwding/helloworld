/**
 *  Filename:XDOJ1053
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:水题
 */
 /*** 36414	14020310043	1053 正确 1688 1 C++/Edit	1013B	2016-04-13 09:04:41 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        if(n > 0)
            cout << "yes" << endl;
        else if(n == 0)
            cout << "light" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
