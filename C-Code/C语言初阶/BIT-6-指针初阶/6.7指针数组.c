#include<stdio.h>
/*
int main()
{
	//��������-������͵�����
	int arr[10];
	//�ַ�����-����ַ�������
	char arr2[5];
	//ָ������-���ָ�������
	int* arr3[5];   //�������ָ�������
	char* arr4[6];   //����ַ�ָ�������
	return 0;
}
*/


/*
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;
	int* arr3[5] = { &a,&b,&c,&d,&e };  //�������ָ�������
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(arr3[i]));  //10 20 30 40 50
	}
	return 0;
}

*/


/*
int main()
{
	//��һά����ģ��һ����ά����
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int arr4[] = { 4,5,6,7,8 };
	int* arr[4] = { arr1, arr2, arr3, arr4 };  //ָ�롢
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
			//printf("%d ", *(*(arr+i)+j));
			//*(arr+i)�ҵ�arr1 arr2 arr3 arr4  *��arr1+j���ҵ��е�ֵ
		}
		printf("\n");
	}
	return 0;
}
*/
