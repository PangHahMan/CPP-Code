#include<stdio.h>
struct Stu
{
	char name[20];
	int age;
	char sex[5];
	char id[12];
};


void print(struct Stu* ps)    //�ṹ��ָ��
{
	//�ṹ��ָ�����������.�ṹ���Ա
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);
	//�ṹ��ָ�����->�ṹ���Ա
	printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->id);
}

//int main()
//{
//	struct Stu s = { "zhangsan",18,"nan","20220402"};
//	//�ṹ�����.�ṹ���Ա
//	printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);
//	print(&s);   //�ṹ��ָ��
//	return 0;
//}


//����ṹ��
int main()
{
	struct Stu s = { 0 };
	//����
	scanf("%s %s %s %d", s.name, s.sex, s.id, &(s.age));
	//�ṹ�����.�ṹ���Ա
	printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);
	print(&s);   //�ṹ��ָ��
	return 0;
}