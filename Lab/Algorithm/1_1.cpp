/************************************************************************/
/* 
ʵ��1.1�������������У�ÿ������n����������λ����������n������
����˼·��
��������x[0]..x[xM]..x[n-1], y[0]..y[yM]..y[n-1],��x[xM] >��y[yM]
�����x[xM]��x[0]..x[xM-1]��y[0]..y[yM]�ض�С��x[xM]���������Ѿ���n����С��x[xM]�����n�����������ڱ�x[xM]������У���x[xM+1]..x[n-1]���ų�
ͬ�����y[yM]�����ų�y[0]..y[yM-1]
����ȡ�м���ʱ����ȡ��������ÿ�����и�����ż��ʹ�������и������Ǳ������
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

