#include<stdio.h>
//1.����ָ��Ķ���
/*
//����ָ�� - ָ�����͵�ָ�� - ������ͱ����ĵ�ַ
int* p;
//�ַ�ָ�� - ָ���ַ���ָ�� - ��ŵ����ַ������ĵ�ַ
char* p;
//����ָ�� - ָ�������ָ�� - ��ŵ�������ĵ�ַ
*/


/*
int main()
{
	int a = 10;
	int* p1 = &a;

	char ch = 'w';
	char* p2 = &ch;

	int arr[10] = { 1,2,3,4,5 };
	int(*pa)[10] = &arr;   //��������ַ������ָ��pa��pa������ָ�����
	//pa�������� -> int(*)[10]
	return 0;
}
*/


/*
int main()
{
	char arr[5];
	char(*p1)[5] = &arr;
	return 0;
}
*/


//2.&��������������������
/*
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);   //00AFFA44
	printf("%p\n", arr + 1);   //00AFFA48    ����4���ֽ�
	printf("%p\n", &arr[0]);   //00AFFA44
	printf("%p\n", &arr[0] + 1);   //00AFFA48  ����4���ֽ�
	printf("%p\n", &arr);   //00AFFA44
	printf("%p\n", &arr + 1);   //00AFFA6C   ����40���ֽ� ��������������
	return 0;
}
*/


/*��������������Ԫ�صĵ�ַ
���������⣺
1.sizeof(������)
2.&������
������������������
*/


//3.����ָ���ʹ��
/*
void print1(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

void print2(int(*arr)[10], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", (*arr)[i]);  //*&arr == arr ����ʹ�ú���
	}
	printf("\n");
}

void print3(int arr[3][5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//��ά�������Ԫ�ؾ��Ƕ�ά����ĵ�һ��
//arr�Ƕ�ά����������� ��������������Ԫ�صĵ�ַ
//arr���ǵ�һ�еĵ�ַ
void print4(int(*p)[5], int r, int c)  //��ά���鴫��[5]����һ�����Ԫ�� p��1ֱ��������һ�е����Ԫ��
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}

void test1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print1(arr, sz);
	print2(&arr, sz);  //��������һά����
}

void test2()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	//print3(arr, 3, 5);
	print4(arr, 3, 5);
}
int main()
{
	//test1();
	test2();

	return 0;
}
*/

//ѧ��ָ�����������ָ��������һ��ع˲���������������˼��
/*
int arr[5];
int* parr1[10];   //ָ������
int(*parr2)[10];   //����ָ��
int(*parr3[10])[5];  //parr3�Ǵ������ָ�������
*/