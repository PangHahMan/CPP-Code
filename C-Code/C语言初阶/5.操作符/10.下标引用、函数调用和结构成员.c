#include<stdio.h>
//1. �±�����[]
/*
int main()
{
	int arr[10];//��������
	arr[9] = 10;//ʵ���±����ò�������
	//[] ��������������arr��9��
	return 0;
}
*/


//2. () �������ò�����
/*
void test(int x, int y)
{

}

void test2()
{

}

int main()
{
	test(3, 4);   //() �������ò�����
	//��������test 3 4
	test2();
	//���������Ǻ�����test2
	return 0;
}
*/


//3.����һ���ṹ�ĳ�Ա
/*
. �ṹ��.��Ա��
-> �ṹ��ָ��->��Ա��
*/

//�飺���� +����
/*
struct Book
{
	char name[20];
	int price;
};

int main()
{
	struct Book sb = { "����C����",55 };
	printf("%s %d\n", sb.name, sb.price);  //�ṹ�����.�ṹ���Ա��
	struct Book* ps = &sb;
	printf("%s %d\n", (*ps).name, (*ps).price);
	printf("%s %d\n", ps->name, ps->price);  //�ṹ��ָ��->�ṹ���Ա��
	return 0;
}
*/