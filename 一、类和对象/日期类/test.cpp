#include"Date.h"
void Test()
{
	Date d1(2023, 2, 4);
	Date d2 = d1 + 100;   //
	d1.Print();
	d2.Print();

	Date d3 = d1 += 100;
	d1.Print();
	d3.Print();
}

void Test1()
{
	Date d1(2023, 2, 4);
	d1.Print();
	++d1;  //d1.opeartor++();
	d1.Print();

	d1++;  //d1.operator++(int);  int���� ������Ϊ��ռλ����ǰ����������
	d1.Print();
}

void Test2()
{
	Date d1(2023, 2, 4);
	d1.Print();
	Date d2 = d1 - 100;
	d2.Print();

	Date d3(2023, 2, 7);
	d3 += -100;
	d3.Print();

	Date d4(2023, 2, 7);
	d4 -= -100;  //-=�ͱ����+=
	d4.Print();
}

void Test3()
{
	Date d1(2023, 2, 4);
	d1.Print();
	Date ret1 = ++d1;
	d1.Print();
	ret1.Print();

	Date ret2 = d1++;
	d1.Print();
	ret2.Print();
}

void Test4()
{
	Date d1(2023, 2, 4);

	Date d2(2023, 2, 5);
	cout << d1 - d2 << endl;
}

//���������
void Test5()
{
	Date d1(2023, 2, 4);
	
	int i = 1;
	double d = 1.11;
	//���������+��������
	//cout << i << endl;  //cout.operator<<(int i)
	//cout << d << endl;  //cout.opeartor<<(double val)
	//�Զ�������<<�𣬿�����Ҫ�Լ�����

	//cout << d1;  /err
	//d1.operator<<(cout);
	//d1<<cout

	//operator<<(cout, d1);
	//cout << d1;
	Date d2(2023, 1, 1);
	cout << d1 << d2 << endl;

}
//����������
void Test6()
{
	Date d1;
	cin >> d1;
	cout << d1;
}

int main()
{
	Test6();
	return 0;
}