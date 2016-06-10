#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#define MAX 10005
using namespace std;
vector<int> v;
int main()
{
    int n,m;
    while(cin >> n >> m){
        int t;
        v.push_back(0);
        for(int i=1;i<=n;i++){
            cin >> t;
            v.push_back(t);
            make_heap(v.begin()+1,v.end(),greater<int>());
        }
        while(m--){
            int a1,a2;
            cin >> a1;
            string s;
            cin >> s;
            if(s == "and"){
                cin >> a2;
                cin >> s;cin >> s;
                vector<int>::iterator it1 = find(v.begin()+1,v.end(),a1);
                vector<int>::iterator it2 = find(v.begin()+1,v.end(),a2);
                vector<int>::difference_type x1 = distance(v.begin(),it1);
                vector<int>::difference_type x2 = distance(v.begin(),it2);
                if(x1 / 2 == x2 / 2)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }else{
                cin >> s;
                if(s == "a"){
                    cin >> s;cin >> s;
                    cin >> a2;
                    vector<int>::iterator it1 = find(v.begin()+1,v.end(),a1);
                    vector<int>::iterator it2 = find(v.begin()+1,v.end(),a2);
                    vector<int>::difference_type x1 = distance(v.begin(),it1);
                    vector<int>::difference_type x2 = distance(v.begin(),it2);
                    if(x1 / 2 == x2)
                        cout << "T" << endl;
                    else
                        cout << "F" << endl;
                }else{
                    cin >> s;
                    if(s == "root"){
                        if(*(v.begin()+1) == a1)
                            cout << "T" << endl;
                        else
                            cout << "F" << endl;
                    }else{
                        cin >> s;
                        cin >> a2;
                        vector<int>::iterator it1 = find(v.begin()+1,v.end(),a1);
                        vector<int>::iterator it2 = find(v.begin()+1,v.end(),a2);
                        vector<int>::difference_type x1 = distance(v.begin(),it1);
                        vector<int>::difference_type x2 = distance(v.begin(),it2);
                        if(x2 / 2 == x1)
                            cout << "T" << endl;
                        else
                            cout << "F" << endl;
                    }
                }
            }
        }
        v.clear();
    }
    return 0;
}
