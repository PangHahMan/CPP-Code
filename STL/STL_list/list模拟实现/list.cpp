#include "list.h"


void print_list(const list<int>& lt)
{
	//��ӡ������һ�㲻��Ҫ�ı�ֵ����ô���Ǿ���Ҫʹ��const������
	list<int>::const_iterator it = lt.begin(); // ��Ҫ����������һ��const����
	while (it != lt.end())
	{
		//(*it) *= 2;  //����const begin�������޷��޸�
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
	list<int>::iterator it = lt.begin(); // ���ÿ������죬Ĭ�ϵ�ǳ������
	//����ǳ����û������,��Ϊ������û������
	while (it != lt.end())
	{
		cout << *it << " "; // 1 2 3 4
		it++;
	}
	cout << endl;
	it = lt.begin();
	for (auto e : lt)
	{
		cout << e << " "; // 1 2 3 4
	}
	cout << endl;

	//print_list(lt);  //1 2 3 4
}

void test2()
{
	// const�ڶ����ʱ����û��const�����Եģ���Ȼ�ڶ����ʱ����޷���ʼ����
	const list<int> lt1;
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	// list<int>::iterator pos = find(lt.begin(), lt.end(), 3);  //#include<algorithm>,�������Ŀ���ʵ�ֲ���
	list<int>::iterator pos = lt.begin();

	lt.insert(pos + 2 - 2, 666);

	for (auto e : lt)
	{
		cout << e << " "; // 666 1 2 3 4
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

struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 0, int a2 = 0)
		: _a1(a1), _a2(a2)
	{
	}
};

//�Զ������͵�list  ->ģ�� 

void test3()
{
	list<AA> lt;   //list��node��data���Զ�������  T data
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));

	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << " " << (*it)._a2 << endl;  //*it = _node->data   ._a1 = AA data.a1
		cout << it->_a1 << " " << it->_a2 << endl;     //it���ص���&_node->data  ��data��ַ-> ����data.a1	
		it++;
	}

}

//��������
void test4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;

	list<int> lt2(lt);

	for (auto e : lt2)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;

	list<int> lt3;
	lt3 = lt;
	for (auto e : lt3)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;
}

//���������
void test5()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";   //5 4 3 2 1 
		++rit;
	}
	cout << endl;

}
int main()
{
	test5();
	return 0;
}