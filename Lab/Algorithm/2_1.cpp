/************************************************************************/
/* 
ʵ��2.1
���룺
n����ʾ��n��Ӳ��
n����ֵ
m����ʾ��Ҫ�ҵ�Ǯ
����˼·��
��ȫ������ǡ�õ���
ʱ�临�Ӷȣ�O(nm)
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
