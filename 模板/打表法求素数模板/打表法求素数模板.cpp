#include <iostream>

using namespace std;
int prime[1000000];
void judgeprime()
{
    prime[0]=prime[1]=1;
     for(int i = 2; i <1000; i++)
         for(int j = i * i; j <1000000; j+= i)
             prime[j] = 1;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
