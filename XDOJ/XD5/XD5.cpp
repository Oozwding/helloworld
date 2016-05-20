#include <iostream>
#include <map>
using namespace std;
map<char,int> m;
int main()
{
    string A,B;
    int x=3;
    while(cin >> A >> B){
        int cou=0;
        for(int i=0;i<B.size();i++)
            m[B[i]] = 1;
        for(int i=0;i<A.size();i++){
            if(m[A[i]] == 1)
                continue;
            else{
                cout << A[i];
                cou++;
            }
        }
        if(!cou)
            cout << "EMPTY";
        cout << endl;
        m.clear();

    }
    return 0;
}
