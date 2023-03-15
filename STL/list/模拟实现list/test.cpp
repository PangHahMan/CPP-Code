#include"list.h"
#include<iostream>
using namespace std;
void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();  //��Ҫ����������һ��const����
	while (it != lt.end())
	{
		//(*it) *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();  //���ÿ������죬Ĭ�ϵ�ǳ����������ǳ����û������
	//ǳ������Ϊʲôû������Ϊ������û��д��������
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;  
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	print_list(lt);
}

struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 0, int a2 = 0)
		:_a1(a1)
		,_a2(a2)
	{}
};

void test2()
{
	list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));

	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << " " << (*it)._a2 << " ";
		//ģ���ͷ->
		cout << it->_a1 << " " << it->_a2 << " ";
		
		++it;
	}
}

void test3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator pos = lt.begin();
	++pos;
	lt.insert(pos, 20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.push_back(100);
	lt.push_front(1000);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	
	lt.pop_back();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}	
}

int main()
{
	test3();
	return 0;
}