/************************************************************************/
/* 
实验1.1，两个递增序列，每个序列n个数，求中位数（排序后第n个数）
核心思路：
对于序列x[0]..x[xM]..x[n-1], y[0]..y[yM]..y[n-1],若x[xM] >　y[yM]
则对于x[xM]，x[0]..x[xM-1]和y[0]..y[yM]必定小于x[xM]，则至少已经有n个数小于x[xM]，则第n个数不可能在比x[xM]大的数中，即x[xM+1]..x[n-1]可排除
同理对于y[yM]，可排除y[0]..y[yM-1]
由于取中间数时向下取整，考虑每个数列个数奇偶，使两个数列个数总是保持相等
*/
/************************************************************************/

/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXSIZE = 1e6 + 10;

int n;
int x[MAXSIZE], y[MAXSIZE];

int search(int xSt, int xEd, int ySt, int yEd)
{
	//printf("%d %d %d %d\n", xSt, xEd, ySt, yEd);

	int xM = xSt + (xEd-xSt)/2;
	int yM = ySt + (yEd-ySt)/2;
	int k = max(xEd-xM, yEd-yM);

	if ( xSt == xEd && ySt == yEd ){
		return min(x[xSt], y[ySt]);
	}else if ( x[xM] == y[yM] ) {
		return x[xM];
	}else if ( x[xM] > y[yM] ){
		return search(xSt, xEd-k, ySt+k, yEd);
	}else{
		return search(xSt+k, xEd, ySt, yEd-k);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while ( cin>>n )
	{
		for (int i = 0; i < n; i++) cin>>x[i];
		for (int i = 0; i < n; i++) cin>>y[i];

		printf("ans=%d\n", search(0, n-1, 0, n-1));
	}

	return 0;
}

3
5 15 18
3 14 21

4
5 15 18 20
3 14 21 22

3
3 14 21
5 15 18

4
3 14 21 22
5 15 18 20

5
1 2 3 4 5
6 7 8 9 10

6 
7 8 9 10 11 12
1 2 3 4 5 6
*/

