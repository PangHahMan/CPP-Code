#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int line = 0;
	scanf_s("%d", &line);
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++)
	{
		//��ӡ�ո�
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//��ӡ�°벿��  �°벿��ֻ��line-1��
	for (i = 0; i < line - 1; i++)
	{
		//��ӡ�ո�
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < (line - 1 - i) * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}