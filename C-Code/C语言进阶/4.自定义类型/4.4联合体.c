#include<stdio.h>
//1.�������͵Ķ���
//����Ҳ��һ��������Զ�������
//�������Ͷ���ı���Ҳ����һϵ�еĳ�Ա����������Щ��Ա����ͬһ��ռ�
/*
union Un
{
	char c;
	int i;
	double d;
};


int main()
{
	union Un un;
	printf("%p\n", &un);
	printf("%p\n", &(un.c));
	printf("%p\n", &(un.i));
	printf("%p\n", &(un.d));
	//��ַ��ͬ
	printf("%d\n", sizeof(union Un));  //8���ֽ�
	return 0;
}
*/

//һ����ֵ���洢ʱ��Ҫ���ڴ�ռ�ֻҪ����1���ֽڣ����漰˳�������
//0x 11 22 33 44
/*���������С��
int check_sys()
{
	union
	{
		char c;
		int i;
	}u;

	u.i = 1;  //�����幫��һ��ռ� i�Ŀռ�С�˴洢Ϊ 01 00 00 00
	return u.c;  //return���� c  cΪ1���ֽ� ����1  ����Ǵ�˷���0
}

int main()
{
	int ret = check_sys;
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
}
*/

//�ص㣺���ϵĳ�Ա�ǹ���ͬһ���ڴ�ռ�ģ�����һ�����ϱ����Ĵ�С������������Ա�Ĵ�С����Ϊ�������ٵ����������������Ǹ���Ա����

//2.������Ĵ�С����
//�����ϵĴ�С����������Ա�Ĵ�С��
//��������Ա��С����������������������ʱ�򣬾�Ҫ���뵽������������������
/*
union Un
{
	char arr[5];  //5 ������Ϊ1
	int i;  //4
};

union Un1
{
	short s[7]; //14
	int i;  //4
};

int main()
{
	printf("%zu\n", sizeof(union Un));  //4�ı���Ϊ8
	printf("%zu\n", sizeof(union Un1));  //16
	return 0;
}
*/
