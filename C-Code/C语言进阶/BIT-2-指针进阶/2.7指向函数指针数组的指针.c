#include<stdio.h>
/*
ָ����ָ�������ָ����һ�� ָ��
ָ��ָ��һ�� ���� �������Ԫ�ض��� ����ָ��;
*/

void test(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	//����ָ��pfun
	void (*pfun)(const char*) = test;
	//����ָ�������pfunArr
	void (*pfunArr[5])(const char* str);
	pfunArr[0] = test;
	//ָ����ָ������pfunArr��ָ��ppfunArr
	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
	return 0;
}