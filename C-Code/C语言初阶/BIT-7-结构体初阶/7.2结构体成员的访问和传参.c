#include<stdio.h>
/*
struct S
{
	char name[20];
	int age;
};

int main()
{
	struct S s = { .age = 20,.name = "zhangsan" };
	printf("%s %d\n", s.name, s.age);   //zhangsan 20
	s.age = 30;  //����
	//s.name = "zhangsanfeng";  //name�Ǹ����� ����Ԫ�ص�ַ ������ֱ�Ӹ�ֵ
	strcpy(s.name, "zhangsanfeng");   //�������
	printf("%s %d\n", s.name, s.age);   //zhangsanfeng 30
	return 0;
}
*/


//�ṹ�崫��
/*
struct S
{
	int data[1000];
	char buf[100];
};

//�ṹ�����.�ṹ���Ա��
//�ṹ��ָ��->�ṹ���Ա��
void print1(struct S s)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", s.data[i]);   // 1 2 3 0 0 0 0 0 0 0
	}
	printf("%s\n", s.buf);  // hehe
}

void print2(struct S* ps)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->data[i]);  // 1 2 3 0 0 0 0 0 0 0
	}
	printf("%s\n",ps->buf);  // hehe
}

int main()
{
	struct S s = { {1,2,3},"hehe" };
	print1(s);   //��ֵ����
	print2(&s);  //��ַ����
	return 0;
}
*/

//�������ε�ʱ�򣬲�������Ҫѹջ�ġ�
//�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ�ĵ�ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½���
//���ۣ��ṹ�崫�ε�ʱ��Ҫ���ṹ��ĵ�ַ��