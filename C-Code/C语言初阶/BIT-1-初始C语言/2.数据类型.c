#include<stdio.h>
//1.C����������Щ�������ͣ�
// char - �ַ���������
// short - ������
// int - ����
// long - ������
// long long - ����������
// float - �����ȸ�����
// double - ˫���ȸ�����
// C��������û���ַ�������    -  ��û�У���


//2.ÿ�����͵Ĵ�С�Ƕ��٣�
// VS�е��������������£� ���ǲ�ͬ�ı����� �в�ͬ��ֵ
int main()
{
	printf("%zd\n", sizeof(char));   //1
	printf("%zd\n", sizeof(short));  //2
	printf("%zd\n", sizeof(int));    //4
	printf("%zd\n", sizeof(long));   //4
	printf("%zd\n", sizeof(long long));   //8
	printf("%zd\n", sizeof(float));    //4
	printf("%zd\n", sizeof(double));   //8
	printf("%zd\n", sizeof(long double));    //8

	//���͵�ʹ�ö���
	char ch = 'w';
	int weight = 120;
	int salary = 20000;
	return 0;
}
// sizeof�ǹؼ��� ���������ʽ��%zd
