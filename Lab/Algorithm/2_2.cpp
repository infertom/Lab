/************************************************************************/
/* 
实验2.2
核心思路：
区间dp，ans(i,j)=min(ans(i,k) + ans(k,j))
时间复杂度：O(n^2)
*/
/************************************************************************/
/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXSIZE = 2000 + 10;

int f[MAXSIZE][MAXSIZE];
int matr[MAXSIZE][MAXSIZE];
int n;

int cal(int st, int ed)
{
	if ( ed - st == 1 ) return matr[st][ed];

	int ans = matr[st][ed];
	for (int i = st+1; i < ed; i++){
		ans = min(ans, cal(st, i) + cal(i, ed));
	}
	matr[st][ed] = ans;
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while ( cin>>n )
	{
		memset(matr, -1, sizeof matr);
		for (int i = 1; i < n; i++){
			for (int j = i+1; j <= n; j++){
				scanf("%d", &matr[i][j]);
			}
		}

		printf("%d\n", cal(1, n));
	}

	return 0;
}


3
5 15
7

5
1 2 3 4
3 4 5
5 6
7

5
1 2 4 8
1 4 8
1 4
1
*/