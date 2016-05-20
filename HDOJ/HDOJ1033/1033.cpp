/**
 *  Filename:XDOJ1033
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:水题
 */
/**36415	14020310043
1033
正确
1688
1
C++/Edit	295 B	2016-04-13 09:08:06*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(temp > 540)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
