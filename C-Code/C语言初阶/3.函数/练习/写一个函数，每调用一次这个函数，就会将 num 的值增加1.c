#include<stdio.h>
void Add(int* num)
{
	(*num)++;
}

int main()
{
	int num = 0;
	//���ú�����ʹ��numÿ������1
	Add(&num);
	printf("%d\n", num);
	Add(&num);
	printf("%d\n", num);
	Add(&num);
	printf("%d\n", num);
	return 0;
}