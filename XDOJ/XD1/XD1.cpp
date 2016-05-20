#include <iostream>
#include <cstdio>
using namespace std;
class Complex{
public:
    int x;
    int y;

    Complex(int x1=0,int y1=0):x(x1),y(y1){}
    Complex operator+(Complex& x1){
        Complex z;
        z.x = x + x1.x;
        z.y = y + x1.y;
        return z;
    }
     friend ostream &operator<<(ostream &os,const Complex &c);
};
ostream & operator<<(ostream &os,const Complex &c)
{
    os << c.x;
    if(c.y >= 0)
        os << "+" << c.y << "i" << endl;
    else
        os << c.y << "i" << endl;
    return os;
}
Complex geshihua(char *str){
        int cou=0;
        int x=0,y=0;
        while(str[cou] != '+'){
            if(cou != 0)
                x = x * 10 + str[cou++] - '0';
            else
                x = str[cou++] - '0';
        }
        cou++;
        int temp=0;
        while(str[cou] != 'i'){
            if(temp != 0)
                y = y * 10 + str[cou++] - '0';
            else
                y = str[cou++] - '0';
            temp++;
        }
        Complex ans(x,y);
        return ans;
}
int main()
{
    char str1[30],str2[30];
    while(scanf("%s%s",str1,str2) != EOF){
        Complex a = geshihua(str1);
        //cout << a << endl;
        Complex b = geshihua(str2);
        //cout << b << endl;
        cout << a + b;
    }
    return 0;
}
