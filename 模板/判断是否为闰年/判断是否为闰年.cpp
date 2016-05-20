#include <iostream>

using namespace std;
int leapYear(int n){
    if(((n % 4 == 0)&&(n % 100))||(n % 400 == 0))
           return 1;
    return 0;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
