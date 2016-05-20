#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int num=0;
    int count = 0;
    int temp = 1;
    cin >> str;
    while(count < 13){
        if(str[count] != '-'){
            if(temp <= 9){
                num += (str[count] - '0') * temp;
                temp++;
            }else{
                //cout << num << endl << num % 11 << endl;
                if(num % 11 == 10){
                    if(str[count] == 'X')
                        cout << "Right" << endl;
                    else{
                        str[12] = 'X';
                        cout << str << endl;
                    }
                }else{
                    if((str[count] - '0') == num % 11)
                        cout << "Right" << endl;
                    else{
                        str[12] = num % 11 + '0';
                        cout << str << endl;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}
