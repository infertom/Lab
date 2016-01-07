/************************************************************************/
/* 
实验2.1
输入：
n，表示有n种硬币
n种面值
m，表示需要找的钱
核心思路：
完全背包，恰好到达
时间复杂度：O(nm)
*/
/************************************************************************/

/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXSIZE = 1e6 + 10;

int bag[MAXSIZE];
int val[MAXSIZE];
int n, m;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while ( cin>>n )
	{
		for (int i = 0; i < n; i++) cin>>val[i];
		cin>>m;

		memset(bag, -1, sizeof bag);
		bag[0] = 0;
		for (int i = 0; i < n; i++){
			for (int sum = 0; sum <= m-val[i]; sum++){
				if ( bag[sum] == -1 ) continue;
				if ( bag[sum+val[i]] == -1 ) bag[sum+val[i]] = bag[sum] + 1;
				else bag[sum+val[i]] = min(bag[sum+val[i]], bag[sum] + 1);
			}
		}

		if ( ~bag[m] ) printf("ans=%d\n", bag[m]);
		else printf("can not do it");
	}

	return 0;
}

	3
	1 2 5
	8

	3
	1 2 5
	5

	5
	1 2 4 8 16
	31
*/
