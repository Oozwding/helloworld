#include <iostream>
#include <stack>
#include <map>
using namespace std;
stack<pair<int,int> > s;
int main()
{
    int n;
    int temp;
    int max=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(s.empty())
            s.push(make_pair(temp,1));
        else{
            if(temp > s.top().first)
                s.push(make_pair(temp,1));
            else{
                int num = s.top().first * s.top().second;
                max = num > max ? num:max;
                pair<int,int> t(temp,1+s.top().second);
                s.pop();
                s.push(t);
            }
        }
    }
    while(true){
        int num = s.top().first * s.top().second;
        max = num > max ? num:max;
        int p = s.top().second;
        s.pop();
        if(!s.empty())
            s.top().second += p;
        else
            break;
    }
    cout << max << endl;
    return 0;
}
