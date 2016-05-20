#include <iostream>

using namespace std;
int num[10001];
int MAX;
int MAXNUM;
int main()
{
    int n,temp;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> temp;
        num[temp]++;
        if(num[temp] > MAX){
            MAX = num[temp];
            MAXNUM = temp;
        }else if(num[temp] == MAX && temp < MAXNUM)
            MAXNUM = temp;
    }
    cout << MAXNUM << endl;
    return 0;
}
