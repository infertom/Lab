/*
********************************************************************** 
�ֲ�ʽϵͳ������ҵһ
Gossipģ��
���飺��ϣ���� ���½࣬�Ŵ����������裬 ռ��
**********************************************************************
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;

const int MAXSiZE = 100000 + 10;
const int MAXVALUE = 100;
const double EPS = 1e-6;

int n, k;
bool flag;//�Ƿ������trueΪ������һ��
double val[MAXSiZE];//�ڵ��ֵ����1��ʼ
double pro[MAXSiZE];//�ڵ�ͨ�Ÿ��ʣ���1��ʼ
bool vis[MAXSiZE];//�Ƿ񱻸���,trueΪ���룬��1��ʼ

********************************************************************** 
���������
********************************************************************* /��ʼ�������������
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
	return (int)(randomBase() * n + 0.5);
}

********************************************************************** 
gossipingģ��
********************************************************************* /��ʼ��
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

//�жϽڵ�p�Ƿ�ͨѶ��trueΪͨѶ
bool isCommunicate(int p)
{
	return (randomReal(1) - pro[p] < EPS);
}

//�ж�����double�Ƿ����
bool equal(double a, double b)
{
	return (fabs(a-b) < EPS);
}

//��ӡ���нڵ������Ϣ
void printValue()
{
	cout<<"value:"<<endl;
	for (int i = 1; i <= n; i++) {
		cout<<"("<<i<<")"<<val[i]<<"  ";
	}
	cout<<endl;

	cout<<"vis:"<<endl;
	for (int i = 1; i <= n; i++){
		cout<<"("<<i<<")"<<vis[i]<<"  ";
	}
	cout<<endl;
}


//ÿ���ڵ�ÿ��ֻ����һ��ͨѶ
bool gossiping()
{
	bool cFlag = false;
	for (int i = 1; i <= n; i++){
		if ( vis[i] ) continue;

		if ( !isCommunicate(i) ){
			vis[i] = true;
		}else{
			int j = randomInt(n-1) + 1;
			cFlag |= true;
			if ( equal(val[i], val[j]) ) {
				pro[i] /= k;
			}
			else {
				double cVal = (val[i] + val[j]) / 2;
				val[i] = val[j] = cVal;
			}
		}
	}

	return cFlag;
}


//��һ����һ���ڵ�ͨѶ�������ж��Ƿ�ͨѶ��������ڵ���Ϣ���º���������״̬
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
				val[i] = val[j] = cVal;
				pro[j] = 1;
				vis[j] = false;
			}
		}
		vis[i] = true;
	}
	//printValue();

	return cFlag;
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int st, ed;
	int ans;
	while ( cin>>n>>k )
	{
		ans = 0;
		init();
		//printValue();
		//st = clock();
		while ( flag )
		{
			ans++;
			flag = gossipingSd();
		}
		//ed = clock();
		//cout<<(ed-st)<<endl;
		cout<<"n="<<n<<"   k="<<k<<endl;
		cout<<"ans="<<ans<<endl;
		//printValue();
	}

	return 0;
}*/