#include<stdio.h>
//1.�ṹ�Ļ���֪ʶ
//�ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı�����
/*
���Ӷ���  �ˣ�����+����+�绰+סַ     
�ṹ��struct-�������Ӷ���
*/


//2.�ṹ������
//����һ��ѧ��  ����+����+�Ա�+���
/*
struct Stu
{
	char name[20];  //����
	int age;       //����
	char sex[5];  //�Ա�
	float hight;   //���
}s1,s2,s3;   //ȫ�ֱ���
struct Stu s5;    //ȫ�ֱ���

int main()
{
	struct Stu s4;   //�ֲ�����
	return 0;
}

*/


//3.�ṹ��Ա������ 
// �ṹ�ĳ�Ա�����Ǳ��������顢ָ�룬�����������ṹ�塣


//4 �ṹ������Ķ���ͳ�ʼ��
/*
struct Point
{
	int x;
	int y;
};

struct S
{
	char c;
	struct Point p;   //�ṹ��Ƕ��
	double d;
	char str[20];
};

struct Stu
{
	char name[20];  //����
	int age;       //����
	char sex[5];  //�Ա�
	float hight;   //���
};

int main()
{
	struct Point p = { 10,20 };
	printf("x=%d y=%d\n", p.x, p.y);

	struct Stu s = { "zhangsan",20,"��",180 };
	printf("%s %d %s %f\n", s.name, s.age, s.sex, s.hight);

	struct S ss = { 'x',{100,200},3.14,"hehe" };
	printf("%c %d %d %lf %s\n", ss.c, ss.p.x, ss.p.y, ss.d, ss.str);
	struct S ss = { .d = 3.14,.c = 'x',.p.x = 100 };  //�����ʼ����Ҫ.�ӱ�����
	return 0;
}
*/
