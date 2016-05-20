/**
 *  Filename:XDOJ1037
 *  Date    :2016/4/13
 *  @Author :zwding
 *  Describe:水题
 */
 /*** 36414	14020310043	1037 正确 1688 1 C++/Edit	1013B	2016-04-13 09:04:41 */
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char str[102];
        cin >> str;
        int cou = strlen(str)%2==1 ? strlen(str) + 1 : strlen(str);
        int te = cou / 2 - 1;
        for(int j = te,k = te + 1;j >= 0;){
            if(str[k] != '\0'){
                //cout << str[j] << " " << str[k] << endl;
                if(str[j]-str[k] == 0){
                    //cout << j << " " << k << endl;
                    j = te + 1;
                    k = j + 1;
                    te++;
                    //cout << j << " " << k <<endl;
                }else{
                    j--;
                    k++;
                }
            }else{
                str[k] = str[j]=='0' ? '1':'0';
                str[++k] = '\0';
                j--;
            }
        }
        cout << str << endl;
    }
    return 0;
}
