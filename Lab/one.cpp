/************************************************************************/
/* 
�ֲ�ʽϵͳ������ҵһ
Gossipʵ��
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
bool flag;//�Ƿ������trueΪ������һ��
double val[MAXSiZE];//�ڵ��ֵ����1��ʼ
double pro[MAXSiZE];//�ڵ�ͨ�Ÿ��ʣ���1��ʼ
bool vis[MAXSiZE];//�Ƿ񱻸���,trueΪ���룬��1��ʼ

/************************************************************************/
/* 
���������
*/
/************************************************************************/
//��ʼ�������������
void randInit()
{
	srand((unsigned)time(NULL));
}

//�������[0,1]����ʵ��
double randomBase()
{
	return 1.0 * rand() / RAND_MAX;
}

//�������[0,n]����ʵ��
double randomReal(int n)
{
	return randomBase() * n;
}

//�������[0,n]��������
int randomInt(int n)
{
	return (int)(randomBase() + 0.5);
}

/************************************************************************/
/* 
gossipingʵ��
*/
/************************************************************************/
//��ʼ��
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

//�ж�p�Ƿ�ͨѶ��trueΪͨѶ
bool isCommunicate(int p)
{
	return (randomReal(1) - pro[p] < EPS);
}

//�ж�����double�Ƿ����
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