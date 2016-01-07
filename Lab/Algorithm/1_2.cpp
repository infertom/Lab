/************************************************************************/
/* 
实验1.2，递归构造Gray码
核心思路：
每次从上一个Gray码中改变一个，由完全二叉树可知，每次二叉树向右扩展时即改变一个节点即可构造出Gray码
*/
/************************************************************************/

/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXSIZE = 100 + 10;

int gray[MAXSIZE];//Gray码，从小标1起，初始全0
int n;//Gray码长度
//初始化Gray至全0
void init()
{
	memset(gray, 0, sizeof gray);
}

//打印Gray码
void printGray()
{
	for (int i = 1; i <= n; i++) cout<<gray[i];
	cout<<endl;
}

//构造Gray码
void work(int pos)
{
	if ( pos == n ) {
		printGray();
		return;
	}

	work(pos+1);
	gray[pos+1] ^= 1;
	work(pos+1);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while ( cin>>n )
	{
		init();
		work(0);
	}

	return 0;
}
*/
