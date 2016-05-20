/**
 *  Filename:XDOJ1035
 *  Date    :2016/4/15
 *  @Author :zwding
 *  Describe:数独
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int isValidSudoku(int arr[]) {
	vector<int> row(9,0);
	vector<int> col(9,0);
	vector<int> grid(9,0);
	for(int i=0;i<81;i++)
	{
		int x=i/9,y=i%9;
		int n=arr[i];
        if ( n<1 || n> 9)
            return 0;
		if ( row[x]& (1<<n ))
			return 0;
		else
			row[x]|=(1<<n);
		if (  col[y]& (1<<n) )
			return 0;
		else
			col[y]|=(1<<n);
		int kgrid=(x/3)*3+y/3;
		if ( grid[kgrid]&(1<<n))
			return 0;
		else
			grid[kgrid]|=(1<<n);
	}
	return 1;
}

int main()
{
    //freopen("in","r",stdin);
    int n;
    int x[81];
    cin >> n;
    while(n--){
        for(int i=0;i<81;i++)
            scanf("%d",&x[i]);
        if(!isValidSudoku(x))
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
