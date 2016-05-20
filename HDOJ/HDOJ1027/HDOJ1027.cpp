 /**
 *  Filename:HDOJ1027
 *  Date    :2016/4/26
 *  @Author :zwding
 *  Describe:next_permutation应用
 */
 ///16993779	2016-04-26 16:25:55	Accepted	1027	31MS	1592K	525 B	G++	zwding
/*排列问题
此题可以用C++STL的函数next_permutation来做
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	int i;
	int a[1001];
	while (cin >> n >> m) {
		for (i = 0; i <= n; i++)
			a[i] = i;
		for (i = 1; i < m; i++)
			next_permutation(a+1, a+n+1);
		cout << a[1];
		for (i = 2; i <= n; i++)
			cout << " " << a[i];
		cout << endl;
	}
	return 0;
}
