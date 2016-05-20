/**
 *  Filename:XDOJ1030
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:三数和问题，刚开始三层循环O(n^3)的复杂度直接超时，后来剪枝还是超时，最后找到了这个O(n^2)的算法
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
int cou = 0;
set<vector<int> > find_triplets(const vector<int>& arr)
{
    set<vector<int> > triplets;
    vector<int> triplet(3);
    int n = arr.size();
    for (int i = 0;i < n; i++){
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum_two = arr[i] + arr[j];
            if (sum_two + arr[k] < 0) {
                j++;
            } else if (sum_two + arr[k] > 0) {
                k--;
            } else {
                triplet[0] = arr[i];
                triplet[1] = arr[j];
                triplet[2] = arr[k];
                triplets.insert(triplet);
                j++;
                k--;
            }
        }
    }
    return triplets;
}
int main()
{
    //freopen("in","r",stdin);
    int temp;
    vector<int> v;
    while(scanf("%d",&n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        set<vector<int> > s = find_triplets(v);
        if(s.empty())
            cout << "Ren Chou Jiu Gai Duo Du Shu!" << endl;
        else{
            for(set<vector<int> >::iterator it = s.begin();it != s.end();it++)
                printf("%d %d %d\n",(*it)[0],(*it)[1],(*it)[2]);
        }
        v.clear();
    }
    return 0;
}
