/**
 *  Filename:HDOJ1007
 *  Date    :2016/3/18
 *  @Author :zwding
 *  Describe:最近点序列 难
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


typedef struct node
{
    double x;
    double y;
}point;
point p[100001];
point y[100001];

int cmp_x(point a, point b)
{
    return a.x < b.x;
}

int cmp_y(point a, point b)
{
    return a.y < b.y;
}

double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double find_near(int l, int r)
{
    if (r - l == 1)
        return dist(p[l], p[r]);
    if (r - l == 2)
        return min(min(dist(p[l], p[l+1]), dist(p[l+1], p[l+2])), dist(p[l], p[l+2]));

    int mid = (l+r) / 2;
    double curmin = min(find_near(l, mid), find_near(mid+1, r));
    int ith = 0;
    int i,j;
	for (i = l; i <= r; i++)
	{
		if (p[mid].x - p[i].x <= curmin || p[i].x - p[mid].x <= curmin)
			y[ith++] = p[i];
	}
	sort(y, y + ith, cmp_y);
	int num;
	for (i = 0; i < ith; ++i)
		for (j = i+1, num = 0; j < ith && num < 7; ++num, ++j)
			if ( dist(y[i], y[j]) < curmin )
				curmin = dist(y[i], y[j]);
			else
				break;
	return curmin;

}
int main()
{
    int n;
    while (cin >> n && n)
    {
    	int i;
    	for (i = 0; i < n; ++i)
    		scanf("%lf%lf", &p[i].x, &p[i].y);
    	sort(p, p+n, cmp_x);
    	printf("%.2lf\n", find_near(0, n-1)/2);
    }
    return 0;
}
