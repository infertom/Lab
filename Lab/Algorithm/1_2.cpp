/************************************************************************/
/* 
ʵ��1.2���ݹ鹹��Gray��
����˼·��
ÿ�δ���һ��Gray���иı�һ��������ȫ��������֪��ÿ�ζ�����������չʱ���ı�һ���ڵ㼴�ɹ����Gray��
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

int gray[MAXSIZE];//Gray�룬��С��1�𣬳�ʼȫ0
int n;//Gray�볤��
//��ʼ��Gray��ȫ0
void init()
{
	memset(gray, 0, sizeof gray);
}

//��ӡGray��
void printGray()
{
	for (int i = 1; i <= n; i++) cout<<gray[i];
	cout<<endl;
}

//����Gray��
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
