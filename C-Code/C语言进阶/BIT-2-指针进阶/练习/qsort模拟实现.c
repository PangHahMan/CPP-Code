#include<stdio.h>
#include<stdlib.h>
//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
void Swap(char* buf1, char* buf2, int width)   //�����ĵ�ַ�е�����
{
	int i = 0;
	for (i = 0; i < width; i++)   //width�����ֽ���  ÿѭ��һ�� ����һ���ֽ��� ������ͬ���Ͷ��ܽ���
	{
		//����һ���ֽڵ�ֵ  ��������� ��width����4  �򽻻�4���ֽڵ�ֵ
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp_int(const void* e1, const void* e2) 
{
	//���e1>e2 �Ļ� return 1  e1<e2�Ļ�return -1
	return (*(int*)e1) - (*(int*)e2); 
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//һ��ð������Ĺ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 3,6,9,7,4,1,2,5,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
	return 0;
}