#include<stdio.h>
//1.��ά����Ĵ���
//���鴴��
int arr[3][4];
char arr[3][5];
double arr[2][4];


//2.��ά����ĳ�ʼ��
int arr[3][4] = { 1,2,3,4 };
int arr[3][4] = { {1,2},{4,5} };
int arr[][4] = { {2,3},{4,5} };//��ά��������г�ʼ�����п���ʡ�ԣ��в���ʡ��


//3.��ά�����ʹ��
#include <stdio.h>
int main()
{
	int arr[3][4] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = i * 4 + j;
		}
	}

	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
	return 0;
}


//4.��ά�������ڴ��еĴ洢
int main()
{
	int arr[3][4];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}
//��ά�������ڴ���Ҳ�������洢�ġ�
