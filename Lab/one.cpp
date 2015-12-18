/************************************************************************/
/* 
分布式系统导论作业一
Gossip实现
*/
/************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;

const int MAXSiZE = 1000 + 10;
const int MAXVALUE = 100;
const double EPS = 1e-6;

int n, k;
bool flag;//是否结束，true为继续下一轮
double val[MAXSiZE];//节点价值，从1起始
double pro[MAXSiZE];//节点通信概率，从1起始
bool vis[MAXSiZE];//是否被隔离,true为隔离，从1起始

/************************************************************************/
/* 
产生随机数
*/
/************************************************************************/
//初始化随机函数种子
void randInit()
{
	srand((unsigned)time(NULL));
}

//随机产生[0,1]区间实数
double randomBase()
{
	return 1.0 * rand() / RAND_MAX;
}

//随机产生[0,n]区间实数
double randomReal(int n)
{
	return randomBase() * n;
}

//随机产生[0,n]区间整数
int randomInt(int n)
{
	return (int)(randomBase() + 0.5);
}

/************************************************************************/
/* 
gossiping实现
*/
/************************************************************************/
//初始化
void init()
{
	randInit();
	flag = true;
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++){
		pro[i] = 1;
	}
	for (int i = 1; i <= n; i++){
		val[i] = randomReal(MAXVALUE);
	}
}

//判断p是否通讯，true为通讯
bool isCommunicate(int p)
{
	return (randomReal(1) - pro[p] < EPS);
}

//判断两个double是否相等
bool equal(double a, double b)
{
	return (fabs(a-b) < EPS);
}

bool gossiping()
{
	bool cFlag = false;
	for (int i = 1; i <= n; i++){
		if ( vis[i] ) continue;

		if ( !isCommunicate(i) ){
			vis[i] = true;
		}else{
			int j = randomInt(n-1) + 1;
			/*if ( vis[j] ) continue;*/
			cFlag |= true;
			if ( equal(val[i], val[j]) ) {
				pro[i] /= k;
			}
			else {
				double cVal = (val[i] + val[j]) / 2;
				val[i] = cVal;
				val[j] = cVal;
			}
		}
	}

	return cFlag;
}

bool gossipingSd()
{
	bool cFlag = false;
	for (int i = 1; i <= n; i++){
		if ( vis[i] ) continue;
		
		while ( isCommunicate(i) )
		{
			int j = randomInt(n-1) + 1;
			cFlag |= true;
			if ( equal(val[i], val[j]) ) {
				pro[i] /= k;
			}
			else {
				double cVal = (val[i] + val[j]) / 2;
				val[i] = cVal;
				val[j] = cVal;
				pro[j] = 1;
				vis[j] = false;
			}
		}
		vis[i] = true;
	}

	return cFlag;
}

void printValue()
{
	for (int i = 1; i <= n; i++) {
		cout<<val[i]<<"  ";
	}
	cout<<endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int st, ed;
	int ans;
	while ( cin>>n>>k )
	{
		//cout<<"Fc 1:"<<endl;
		//ans = 0;
		//init();
		////printValue();
		//st = clock();
		//while ( flag )
		//{
		//	//printValue();
		//	flag = gossiping();
		//	if ( flag ) ans++;
		//}
		//ed = clock();
		//cout<<(ed-st)<<endl;
		//cout<<ans<<endl;

		cout<<"Sd 2:"<<endl;
		ans = 0;
		init();
		//printValue();
		st = clock();
		while ( flag )
		{
			//printValue();
			flag = gossipingSd();
			if ( flag ) ans++;
		}
		ed = clock();
		cout<<(ed-st)<<endl;
		cout<<ans<<endl;
	}

	return 0;
}