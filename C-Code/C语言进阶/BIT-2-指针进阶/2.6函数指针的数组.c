#include<stdio.h>
/*
//����ָ��
int(*pf)(int, int);
//����ָ������
int(*pfArr[4])(int, int);  
//����ָ��
int* p;
//����ָ������
int* arr[5];
*/


/*
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int main()
{
	//����ָ������
	//���Դ�Ŷ��������ͬ����������ͬ�ĺ����ĵ�ַ
	int (*pfArr[2])(int, int) = { Add,Sub };
	int ret = pfArr[0](2, 3);
	printf("%d\n", ret);
	ret = pfArr[1](2, 3);
	printf("%d\n", ret);
	return 0;
}
*/


//дһ��������
//�ӡ������ˡ���
/*

*/
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("                          \n");
	printf("       1.add  2.sub       \n");
	printf("       3.mul  4.div       \n");
	printf("       0.exit             \n");
	printf("                          \n");
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	//����ָ������ - ת�Ʊ�
	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };  //����ѡ��1��Ӧ�ӷ� ���Ե�0��������Add ��0����
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		printf("����������������;>");
		scanf_s("%d %d", &x, &y);
		if (input == 0)
		{
			printf("�Ƴ�������\n");
			break;
		}

		if (input >= 1 && input <= 4)
		{
			ret = pfArr[input](x, y);
			printf("%d", ret);
		}
	
	} while (input);
	return 0;
}