/************************************************************************/
/*
实验3.2，求背包最优解路径
*/
/************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXSIZE = 100 + 10;
const int MAXWEI = 10000 + 10;

int bag[MAXSIZE][MAXWEI];
int n, m;
int w[MAXSIZE], val[MAXSIZE], vis[MAXSIZE];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while ( cin>>n )
	{
		memset(bag, 0, sizeof bag);
		memset(vis, 0, sizeof vis);

		cin>>m;
		for (int i = 1; i <= n; i++) cin>>w[i];
		for (int i = 1; i <= n; i++) cin>>val[i];


		for (int i = 1; i <= n; i++){
			for (int sum = 0; sum <= m; sum++) bag[i][sum] = bag[i-1][sum];
			for (int sum = m; sum >= w[i]; sum--) {
				bag[i][sum] = max(bag[i][sum], bag[i][sum-w[i]] + val[i]);
			}
		}
		
		int sum = m;
		for (int i = n; i; i--){
			if ( bag[i][sum] == bag[i-1][sum] ) continue;

			vis[i] = 1;
			sum -= w[i];
		}

		for (int i = 1; i <= n; i++) {
			printf("%d%c", vis[i], (i==n)? '\n':' ');
		}
	}

	return 0;
}

/*
	4
	5
	2 1 3 2
	12 10 20 15

	4
	5
	1 1 2 3
	11 11 11 1
*/
