 /**
 *  Filename:TJU3485 16省赛选拔E
 *  Date    :2016/4/28
 *  @Author :zwding
 *  Describe:序列求和问题
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

///超时
/*int countsum(vector<int>& v){
    int coun = 0;
    for(int i=0;i<v.size();i++){
        int sum = 0;
        for(int j=i;j<v.size();j++){
            sum += v[j];
            if(sum == 47)
                ++coun;
        }
    }
    return coun;
}*/
map<int,int> sumofseq;
int countsum(vector<int>& v){
    //存储和为sum的序列个数
    int sum = 0;
    int coun = 0;
    sumofseq[0] = 1;
    for(int i=0;i<v.size();i++){
        sum += v[i];
        sumofseq[sum]++;
        coun += sumofseq[sum-47];
    }
    sumofseq.clear();
    return coun;
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        int k,t;
        cin >> k;
        vector<int> v(k,0);
        for(int i=0;i<k;i++){
            cin >> t;
            v[i] = t;
        }
        cout << countsum(v) << endl;
    }
    return 0;
}
